#include "core/editabledoc.h"
#include "ast/boplistast.h"
#include "mode/menumode.h"
#include "mode/identinputmode.h"
#include "mode/stringinputmode.h"
#include "mode/numberinputmode.h"
#include "mode/pairinputmode.h"

#include <cctype>
#include <cassert>
#include <QDebug>

MenuMode::MenuMode(EditableDoc &doc, Context context) :
    Mode(doc),
    context(context)
{

}

void MenuMode::keyboard(char key)
{
    if (key == ' ') {
        doc.pop();
        return;
    }

    Ast::Type keyType = keyToNesterType(key);
    int bop = keyToBop(key);
    Mode *nextMode = nullptr;

    switch (context) {
    case Context::INSERT: {
        doc.insert(keyType, bop);
        nextMode = modeFor(keyType);
        break;
    }
    case Context::APPEND: {
        doc.append(keyType, bop);
        nextMode = modeFor(keyType);
        break;
    }
    case Context::ASSART: {
        doc.assart(keyType, bop);
        nextMode = modeFor(keyType);
        break;
    }
    case Context::FALL_SEARCH:
        switch (key) {
        // TODO: pattern matching cases keyToPattern
        default:
            // TODO: do-nothing if no map
            std::function<bool(const Ast *)> match = [keyType](const Ast *a)
            {
                return a->getType() == keyType;
            };
            doc.flyIn(match);
        }

        break;
    case Context::NEST:
        switch (key) {
        // TODO: smart condition check (nester cannot be scalar)
        case '=':
            doc.nestAsLeft(Ast::Type::ASSIGN);
            break;
        case '+':
            doc.nestAsLeft(Ast::Type::ADD_BOP_LIST, BopListAst::ADD);
            break;
        case '-':
            doc.nestAsLeft(Ast::Type::ADD_BOP_LIST, BopListAst::SUB);
            break;
        case '*':
            doc.nestAsLeft(Ast::Type::MUL_BOP_LIST, BopListAst::MUL);
            break;
        case '/':
            doc.nestAsLeft(Ast::Type::MUL_BOP_LIST, BopListAst::DIV);
            break;
        case '(':
            doc.nestAsLeft(Ast::Type::DOT_BOP_LIST, BopListAst::CALL);
            break;
        case '.':
            doc.nestAsLeft(Ast::Type::DOT_BOP_LIST, BopListAst::DOT);
            break;
        }

        break;
    default:
        break;
    }

    doc.pop(nextMode);
}

void MenuMode::onPushed()
{
    doc.toggleTension(true);
}

void MenuMode::onPopped()
{
    doc.toggleTension(false);
}

const char *MenuMode::name()
{
    return "op pending";
}

Mode *MenuMode::modeFor(Ast::Type t)
{
    switch (t) {
    case Ast::Type::IDENT:
        return new IdentInputMode(doc, true);
    default:
        return nullptr;
    }
}

Ast::Type MenuMode::keyToNesterType(char key)
{
    switch (key) {
    case '.':
    case '(':
        return Ast::Type::DOT_BOP_LIST;
    case '+':
    case '-':
        return Ast::Type::ADD_BOP_LIST;
    case '*':
    case '/':
    case '%':
        return Ast::Type::MUL_BOP_LIST;
    case 'C':
        return Ast::Type::CLASS;
    case 'i':
        return Ast::Type::IF_LIST;
    case 'm':
        return Ast::Type::METHOD;
    case 'v':
        return Ast::Type::DECL_STMT;
    default: // TODO: a 'nothing' type?
        return Ast::Type::IDENT;
    }
}

int MenuMode::keyToBop(char key)
{
    switch (key) {
    case '.': return BopListAst::DOT;
    case '(': return BopListAst::CALL;
    case '+': return BopListAst::ADD;
    case '-': return BopListAst::SUB;
    case '*': return BopListAst::MUL;
    case '/': return BopListAst::DIV;
    case '%': return BopListAst::MOD;
    default: return BopListAst::UNUSED;
    }
}



