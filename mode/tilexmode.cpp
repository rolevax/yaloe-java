#include "mode/tilexmode.h"
#include "mode/identinputmode.h"
#include "mode/stringinputmode.h"
#include "mode/numberinputmode.h"
#include "core/editabledoc.h"

#include <cassert>

TilexMode::TilexMode(EditableDoc &doc, bool macroContext)
    : Mode(doc)
    , macroContext(macroContext)
{

}

Mode::Result TilexMode::keyboard(Key key)
{
    char str[2] = { KeyCode::toChar(key), '\0' };
    Ast::Type ot = doc.getOuter().getType();

    if (KeyCode::isAlpha(key)) {
        doc.change(Ast::Type::IDENT);
        doc.scalarClear();
        doc.scalarAppend(str);
        return { ResultType::DONE_POP, new IdentInputMode(doc, false) };
    } else if (KeyCode::isDigit(key)) {
        doc.change(Ast::Type::NUMBER);
        doc.scalarClear();
        doc.scalarAppend(str);
        return { ResultType::DONE_POP, new NumberInputMode(doc, false) };
    } else if (key == Key::DOUBLE_QUOTE) {
        doc.change(Ast::Type::STRING);
        return { ResultType::DONE_POP, new StringInputMode(doc, true) };
    } else if (key == Key::TAB) { // paste
        doc.paste();
        doc.setHotLight(EditableDoc::HotLightLevel::OFF);
        return DONE_POP_NOPUSH;
    } else if (key == Key::SPACE) {
        return keyboardSpace();
    } else if (key == Key::EQUAL) {
        return keyboardEqual();
    } else if (key == Key::PLUS || key == Key::MINUS) {
        return ppmm(key == Key::PLUS);
    } else { // character coupling
        if (key == Key::AND && ot == Ast::Type::BIT_AND) // & -> &&
            castOuter(Ast::Type::LOGIC_AND_BOP_LIST);
        else if (key == Key::PIPE && ot == Ast::Type::BIT_OR) // | -> ||
            castOuter(Ast::Type::LOGIC_OR_BOP_LIST);
        else if (key == Key::LESS && ot == Ast::Type::LT) // < -> <<
            castOuter(Ast::Type::SHL);
        else if (key == Key::GREATER && ot == Ast::Type::GT) // > -> >>
            castOuter(Ast::Type::SHR);
        else if (key == Key::GREATER && ot == Ast::Type::SHR) // >> -> >>>
            castOuter(Ast::Type::SHRA);
        return DONE_STAY_NOPUSH;
    }
}

Mode::Result TilexMode::onPushed()
{
    assert(doc.getInner().getType() == Ast::Type::META);
    doc.setHotLight(EditableDoc::HotLightLevel::AREA);
    return DONE_STAY_NOPUSH;
}

const char *TilexMode::name()
{
    return "Tilex";
}

Mode::Result TilexMode::keyboardSpace()
{
    const InternalAst &outer = doc.getOuter();
    if (outer.getType() == Ast::Type::ADD_BOP_LIST
            && outer.size() == 2
            && doc.getInnerIndex() == 0) {
        Ast::Type t = outer.asBopList().opAt(1) == BopListAst::ADD ?
                    Ast::Type::UNARY_PLUS : Ast::Type::UNARY_MINUS;
        doc.sibling(1);
        doc.nestAsRight(t);
        doc.expose();
    } else if (outer.getType() == Ast::Type::DOT_BOP_LIST
               && outer.asBopList().opAt(doc.getInnerIndex()) == BopListAst::ARR) {
        doc.change(Ast::Type::HIDDEN);
    } else {
        doc.remove(); // remove the meta node
    }

    doc.setHotLight(EditableDoc::HotLightLevel::OFF);
    return DONE_POP_NOPUSH;
}

Mode::Result TilexMode::keyboardEqual()
{
    if (doc.getOuter().size() != 2)
        return DONE_STAY_NOPUSH;

    switch (doc.getOuter().getType()) {
    case Ast::Type::ASSIGN:
        castOuter(Ast::Type::EQ);
        break;
    case Ast::Type::LT:
        castOuter(Ast::Type::LEQ);
        break;
    case Ast::Type::GT:
        castOuter(Ast::Type::GEQ);
        break;
    case Ast::Type::SHL:
        castOuter(Ast::Type::ASS_SHL);
        break;
    case Ast::Type::SHR:
        castOuter(Ast::Type::ASS_SHR);
        break;
    case Ast::Type::SHRA:
        castOuter(Ast::Type::ASS_SHRA);
        break;
    case Ast::Type::BIT_OR:
        castOuter(Ast::Type::ASS_OR);
        break;
    case Ast::Type::BIT_XOR:
        castOuter(Ast::Type::ASS_XOR);
        break;
    case Ast::Type::BIT_AND:
        castOuter(Ast::Type::ASS_AND);
        break;
    case Ast::Type::ADD_BOP_LIST:
        switch (doc.getOuter().asBopList().opAt(1)) {
        case BopListAst::ADD:
            castOuter(Ast::Type::ASS_ADD);
            break;
        case BopListAst::SUB:
            castOuter(Ast::Type::ASS_SUB);
            break;
        default:
            throw "WTF";
        }
        break;
    case Ast::Type::MUL_BOP_LIST:
        switch (doc.getOuter().asBopList().opAt(1)) {
        case BopListAst::MUL:
            castOuter(Ast::Type::ASS_MUL);
            break;
        case BopListAst::DIV:
            castOuter(Ast::Type::ASS_DIV);
            break;
        case BopListAst::MOD:
            castOuter(Ast::Type::ASS_MOD);
            break;
        default:
            throw "WTF";
        }
        break;
    default:
        break;
    }

    return DONE_STAY_NOPUSH;
}

Mode::Result TilexMode::ppmm(bool inc)
{
    const InternalAst &outer = doc.getOuter();
    if (outer.getType() != Ast::Type::ADD_BOP_LIST || outer.size() != 2)
        return DONE_STAY_NOPUSH;

    bool prefix = doc.getInnerIndex() == 0;
    bool plus = outer.asBopList().opAt(1) == BopListAst::ADD;
    if (plus != inc) // "+-" or "-+"
        return DONE_STAY_NOPUSH;

    Ast::Type t = prefix ? (inc ? Ast::Type::PRE_INC : Ast::Type::PRE_DEC)
                         : (inc ? Ast::Type::POST_INC : Ast::Type::POST_DEC);
    doc.sibling(prefix ? +1 : -1);
    doc.nestAsLeft(t); // unary nest, both left and right is ok
    doc.expose();

    doc.setHotLight(EditableDoc::HotLightLevel::OFF);
    return DONE_POP_NOPUSH;
}

void TilexMode::castOuter(Ast::Type ot)
{
    assert(!Ast::isScalar(ot));

    // remember cursor position of the meta and dolly-out
    size_t inner = doc.getInnerIndex();
    doc.digOut();

    doc.cast(ot);

    // set cursor back
    doc.fallIn();
    doc.sibling(inner);

    if (macroContext)
        relayMacro(inner);
}

void TilexMode::relayMacro(int savedInner)
{
    Ast::Type ot = doc.getOuter().getType();
    Ast::Type oot = doc.getOuter().getParent().getType();

    if (Ast::isBopList(oot) && oot == ot) {
        doc.digOut();
        const BopListAst &flattenee = doc.getInner().asBopList();
        int flatteneeSize = flattenee.size();
        for (int i = 0; i < flatteneeSize; i++) {
            int infix = i == 0 ? BopListAst::UNUSED : flattenee.opAt(i);
            doc.append(Ast::Type::META, infix);
            doc.change(flattenee.at(i).clone());
        }

        doc.sibling(-flatteneeSize); // back to the meta-containing tree
        doc.remove();
        doc.sibling(savedInner); // back to the copied meta
        assert(doc.getInner().getType() == Ast::Type::META);
    } else if (doc.getOuter().size() == 2
               && Ast::precedence(ot) < Ast::precedence(oot)) {
        // a macro either nest-as-left or append.
        // (the only exception is type-cast, but that's not double-char op)
        // if the outer's size is two, it must be a nest.
        assert(doc.getInnerIndex() == 1);
        // revert the node created by the single-char macro
        doc.sibling(-1);
        doc.expose();

        // auto dolly-out as macros did
        while (Ast::precedence(ot) < doc.getOuter().precedence()
               && doc.getInnerIndex() == doc.getOuter().size() - 1)
            doc.digOut();

        // nest-or-append as macros did
        if (doc.getOuter().getType() == ot && doc.getOuter().isList()) {
            doc.append(Ast::Type::META);
        } else {
            doc.nestAsLeft(ot);
            doc.fallIn();
            doc.sibling(+1);
        }
    }
}
