#include "ast/listast.h"
#include "ast/scalarast.h"

#include <algorithm>
#include <cassert>

ListAst::ListAst(Type t)
    : InternalAst(t)
{

}

ListAst *ListAst::clone() const
{
    ListAst *ret = new ListAst(getType());
    for (size_t i = 0; i < size(); i++)
        ret->append(at(i).clone());
    return ret;
}

size_t ListAst::size() const
{
    return subtrees.size();
}

Ast &ListAst::at(size_t pos) const
{
    return *subtrees[pos];
}

size_t ListAst::indexOf(const Ast *child) const
{
    auto eq = [child](const std::unique_ptr<Ast> &a) {
        return a.get() == child;
    };
    auto it = std::find_if(subtrees.begin(), subtrees.end(), eq);

    if (it == subtrees.end())
        return assert(false && "child not found"), 0;
    else
        return it - subtrees.begin();
}

void ListAst::insert(size_t pos, Ast *child)
{
    child->setParent(this);
    doInsert(pos, child);
}

void ListAst::append(Ast *subtree)
{
    insert(size(), subtree);
}

Ast *ListAst::remove(size_t pos)
{
    assert(pos < subtrees.size());
    Ast *res = subtrees[pos].release();
    subtrees.erase(subtrees.begin() + pos);
    return res;
}

bool ListAst::illZero() const
{
    if (0 != size())
        return false;
    Ast::Type t = getType();
    return t == Type::ADD_BOP_LIST || t == Type::MUL_BOP_LIST;
}

bool ListAst::illOne() const
{
    if (1 != size())
        return false;
    return false; // TODO might be useless
}

void ListAst::doInsert(size_t pos, Ast *child)
{
    subtrees.emplace(subtrees.begin() + pos, child);
}

void ListAst::doChange(size_t pos, Ast *next)
{
    assert(pos < subtrees.size());
    subtrees[pos].reset(next);
}

