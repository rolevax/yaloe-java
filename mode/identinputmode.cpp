#include "mode/identinputmode.h"
#include "core/editabledoc.h"

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
    } else {
        // check legal char
        doc.scalarAppend(key);
    }
}

void IdentInputMode::onPushed()
{
    if (clear) {
        assert(doc.getInner().getType() == Ast::Type::IDENT);
        doc.scalarClear();
    }

    doc.setHotLight(EditableDoc::HotLightLevel::POINT);
}

void IdentInputMode::onPopped()
{
    doc.setHotLight(EditableDoc::HotLightLevel::OFF);
}

const char *IdentInputMode::name()
{
    return "Ident Input";
}

