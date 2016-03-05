#ifndef INTERNALAST_H
#define INTERNALAST_H

#include "ast.h"

class InternalAst : public Ast
{
public:
    InternalAst(Type t);
    virtual ~InternalAst() = default;

    void change(size_t pos, Ast *next);
    virtual size_t size() const = 0;
    virtual Ast &at(size_t pos) const = 0;
    virtual size_t indexOf(const Ast *child) const = 0;
    Ast::Type typeAt(size_t pos);

protected:
    virtual void doChange(size_t pos, Ast *next) = 0;
};

#endif // INTERNALAST_H
