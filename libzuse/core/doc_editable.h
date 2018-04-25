#ifndef ZUSE_DOC_EDITABLE_H
#define ZUSE_DOC_EDITABLE_H

#include "../ast/ast_list_bop.h"
#include "../mode/mode.h"

#include <string>
#include <functional>



class DocEditable
{
public:
    enum class HotLightLevel { OFF, POINT, AREA };

    virtual ~DocEditable() = default;

    virtual const AstInternal &getOuter() const = 0;
    virtual const Ast &getInner() const = 0;
    virtual size_t getInnerIndex() const = 0;

    virtual void fallIn() = 0;
    virtual void digOut() = 0;
    virtual void sibling(int step, bool skipHidden = false) = 0;
    virtual void jackKick(bool down) = 0;
    virtual void hackLead(bool right) = 0;
    virtual void focusInBig(bool match(const Ast*)) = 0;
    virtual void focusInBig(Ast::Type match) = 0;
    virtual void dollyOutBig(bool match(const Ast*)) = 0;
    virtual void dollyOutBig(Ast::Type match) = 0;
    virtual void siblingBig(bool match(const Ast*), bool right) = 0;
    virtual void siblingBig(Ast::Type match, bool right) = 0;
    virtual void insert(Ast::Type type, Bop bop = Bop::UNUSED) = 0;
    virtual void append(Ast::Type type, Bop bop = Bop::UNUSED) = 0;
    virtual void assart(Ast::Type type, Bop bop = Bop::UNUSED) = 0;
    virtual void remove() = 0;
    virtual void change(std::unique_ptr<Ast> a) = 0;
    virtual void change(Ast::Type type) = 0;
    virtual void nestAsLeft(Ast::Type type, Bop bop = Bop::UNUSED) = 0;
    virtual void nestAsRight(Ast::Type type, Bop bop = Bop::UNUSED) = 0;
    virtual void expose() = 0;
    virtual void cast(Ast::Type type) = 0;

    virtual std::unique_ptr<Mode> createModifyMode(bool clear, size_t offset = 0,
                                                   bool macroContext = false) = 0;
    virtual void scalarAppend(const char *str) = 0;
    virtual void scalarAppend(char c) = 0;
    virtual void scalarClear() = 0;
    virtual void listClear() = 0;

    virtual void toggleAbstract() = 0;
    virtual void toggleFinal() = 0;
    virtual void toggleAccess(bool up) = 0;
    virtual void toggleStatic() = 0;
    virtual void toggleTransient() = 0;
    virtual void toggleVolatile() = 0;
    virtual void toggleNative() = 0;
    virtual void toggleSynchronized() = 0;

    virtual void switchClip(char c) = 0;
    virtual void yank(const Ast &a) = 0;
    virtual void paste() = 0;

    virtual void setHotLight(HotLightLevel level) = 0;
    virtual void toggleTension(bool b) = 0;
};

#endif // ZUSE_DOC_EDITABLE_H
