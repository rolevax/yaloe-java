#ifndef EDITABLEDOC_H
#define EDITABLEDOC_H

#include "ast/ast.h"
#include "mode/mode.h"

#include <string>
#include <functional>

class EditableDoc
{
public:
    virtual ~EditableDoc() = default;

    virtual void push(Mode *mode) = 0;
    virtual void pop(Mode *nextPush = nullptr) = 0;

    virtual const Ast &getOuter() const = 0;
    virtual const Ast &getInner() const = 0;

    virtual void cursorIn() = 0;
    virtual void cursorForward() = 0;

    virtual void fallIn() = 0;
    virtual void digOut() = 0;
    virtual void sibling(int step) = 0;
    virtual void jackKick(bool down) = 0;
    virtual void hackLead(bool right) = 0;
    virtual void flyIn(std::function<bool(const Ast*)> &match) = 0;
    virtual void insert(Ast::Type type) = 0;
    virtual void remove() = 0;
    virtual void change(Ast::Type type) = 0;
    virtual void nest(Ast::Type type) = 0;

    virtual void scalarAppend(const char *str) = 0;
    virtual void scalarAppend(char c) = 0;
    virtual void scalarClear() = 0;

    virtual void setHotLight(bool b) = 0;
    virtual void toggleTension(bool b) = 0;
};

#endif // EDITABLEDOC_H
