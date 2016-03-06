#include "mode/identinputmode.h"
#include "core/editabledoc.h"
#include "ast/scalarast.h"

#include <algorithm>
#include <cassert>

IdentInputMode::IdentInputMode(EditableDoc &doc, bool clear)
    : Mode(doc),
      clear(clear)
{

}

void IdentInputMode::keyboard(char key)
{
    if (key == ' ') {
        doc.pop();
        return;
    }

    if (clear) {
        doc.setHotLight(EditableDoc::HotLightLevel::POINT);
        doc.scalarClear();
        clear = false;
    }

    if (key == '.') {
        if (doc.getOuter().getType() == Ast::Type::DOT_BOP_LIST) {
            doc.append(Ast::Type::IDENT, BopListAst::DOT);
        } else {
            doc.nestAsLeft(Ast::Type::DOT_BOP_LIST, BopListAst::DOT);
            doc.fallIn();
            doc.sibling(+1);
        }
        clear = true;
    } else {
        // check legal char
        doc.scalarAppend(key);
    }
}

void IdentInputMode::onPushed()
{
    if (clear)
        doc.setHotLight(EditableDoc::HotLightLevel::AREA);
    else
        doc.setHotLight(EditableDoc::HotLightLevel::POINT);
}

void IdentInputMode::onPopped()
{
    doc.setHotLight(EditableDoc::HotLightLevel::OFF);

    if (isType(doc.getInner().asScalar().getText())) {
        Ast::Type otype = doc.getOuter().getType();
        if (otype == Ast::Type::STMT_LIST || otype == Ast::Type::MEMBER_LIST) {
            doc.nestAsLeft(Ast::Type::DECL_VAR);
        }
    }
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

