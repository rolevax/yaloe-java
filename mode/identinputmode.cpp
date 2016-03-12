#include "mode/identinputmode.h"
#include "core/editabledoc.h"
#include "ast/scalarast.h"

#include <algorithm>
#include <cstdlib>
#include <cassert>

IdentInputMode::IdentInputMode(EditableDoc &doc, bool clear)
    : Mode(doc),
      clear(clear)
{

}

Mode::Result IdentInputMode::keyboard(char key, bool top)
{
    assert(doc.getInner().getType() == Ast::Type::IDENT);

    if (key == ' ') {
        Mode * nextPush = promotion();
        return { true, true, nextPush };
    }

    if (clear) {
        doc.setHotLight(EditableDoc::HotLightLevel::POINT);
        doc.scalarClear();
        clear = false;
    }

    if (isalnum(key) || key == '\b' || key == '_' || key == '$') {
        doc.scalarAppend(key);
        return { false, true, nullptr };
    } else {
        return { true, false, nullptr };
    }
}

Mode::Result IdentInputMode::onPushed()
{
    if (clear)
        doc.setHotLight(EditableDoc::HotLightLevel::AREA);
    else
        doc.setHotLight(EditableDoc::HotLightLevel::POINT);
    return { false, true, nullptr };
}

void IdentInputMode::onPopped()
{
    doc.setHotLight(EditableDoc::HotLightLevel::OFF);
}

const char *IdentInputMode::name()
{
    return "Ident Input";
}

bool IdentInputMode::isType(const std::string &id)
{
    return isPrimitiveType(id) || isUpperCamel(id);
}

bool IdentInputMode::isPrimitiveType(const std::string &id)
{
    return id == "void" || id == "byte" || id == "short"
            || id == "int" || id == "long" || id == "char"
            || id == "float" || id == "double";
}

bool IdentInputMode::isUpperCamel(const std::string &id)
{
    // at least size 2, initial is upper, at least one lower
    return id.size() > 1 && isupper(id[0])
            && id.end() != std::find_if(id.begin() + 1, id.end(), islower);
}

Mode *IdentInputMode::promotion()
{
    bool promoted = promoteToDeclVar() || promoteToStmt();
    return promoted ? doc.createModifyMode(true) : nullptr;
}

bool IdentInputMode::promoteToDeclVar()
{
    if (isType(doc.getInner().asScalar().getText())) {
        // case 1: check bare identifier
        Ast::Type otype = doc.getOuter().getType();
        if (otype == Ast::Type::STMT_LIST || otype == Ast::Type::MEMBER_LIST) {
            doc.nestAsLeft(Ast::Type::DECL_VAR);
            return true;
        }

        // case 2: check qualified name
        if (otype == Ast::Type::DOT_BOP_LIST) {
            const BopListAst &bast = doc.getOuter().asBopList();
            assert(bast.size() >= 2);
            size_t i = 1;
            while (i != bast.size() && bast.opAt(i) == BopListAst::DOT)
                i++;
            if (i == bast.size()) { // all op is member access
                Ast::Type ootype = doc.getOuter().getParent().getType();
                if (ootype == Ast::Type::STMT_LIST
                        || ootype == Ast::Type::MEMBER_LIST) {
                    doc.digOut();
                    doc.nestAsLeft(Ast::Type::DECL_VAR);
                    return true;
                }
            }
        }
    }

    return false;
}

bool IdentInputMode::promoteToStmt()
{
    const std::string &text = doc.getInner().asScalar().getText();
    if (text == "while") {
        doc.change(Ast::Type::WHILE);
        return true;
    }

    return false;
}

