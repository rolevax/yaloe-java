#include "ast/ast.h"

#include <cassert>

bool Ast::isList(Ast::Type type)
{
    return Type::CLASS_LIST <= type && type <= Type::MULDIV_LIST;
}

bool Ast::isList(const Ast &a)
{
    return isList(a.type);
}

bool Ast::isMap(Ast::Type type)
{
    return Type::CLASS <= type && type <= Type::ASSIGN;
}

bool Ast::isMap(const Ast &a)
{
    return isMap(a.type);
}

bool Ast::isScalar(Ast::Type type)
{
    return !isList(type) && !isMap(type);
}

bool Ast::isScalar(const Ast &a)
{
    return isScalar(a.type);
}

bool Ast::isChangeable(Ast::Type type)
{
    return type != Type::KEY && type != Type::PAIR && type != Type::ROOT;
}

bool Ast::isChangeable(const Ast &a)
{
    return isChangeable(a.type);
}

Ast::Ast(Type t) :
    type(t),
    parent(nullptr)
{

}

Ast::Type Ast::getType() const
{
    return type;
}

Ast &Ast::getParent() const
{
    return *parent;
}

void Ast::insert(size_t pos, Ast *child)
{
    child->parent = this;
    doInsert(pos, child);
}

std::unique_ptr<Ast> Ast::remove(size_t pos)
{
    (void) pos;
    throw 2048;
}

void Ast::change(size_t pos, Ast *next)
{
    next->parent = this;
    doChange(pos, next);
}

void Ast::nest(size_t pos, Ast *nester)
{
    assert(nester->type == Type::ARRAY && nester->size() == 0);

    std::unique_ptr<Ast> nestee = remove(pos);
    insert(pos, nester);
    at(pos).insert(0, nestee.release());
}

size_t Ast::size() const
{
    return 0;
}

Ast &Ast::at(size_t pos) const
{
    (void) pos;
    throw 2048;
}

size_t Ast::indexOf(const Ast *child) const
{
    (void) child;
    return -1;
}

int Ast::indentLevel() const
{
    int ret = 0;
    Type ptype = parent->type;
    bool hasIndent = ptype == Type::METHOD_LIST
            || ptype == Type::STMT_LIST;
    if (hasIndent)
        for (const Ast *a = this; a->parent != a; a = &a->getParent())
            ret += Ast::isList(*a);
    return ret;
}

void Ast::doInsert(size_t pos, Ast *child)
{
    (void) pos;
    (void) child;
    throw 2048;
}

void Ast::doChange(size_t pos, Ast *next)
{
    (void) pos;
    (void) next;
    throw 2048;
}



