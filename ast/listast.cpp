#include "ast/listast.h"
#include "ast/scalarast.h"

#include <algorithm>
#include <cassert>

ListAst &ListAst::fromAst(Ast &a)
{
    assert(a.isList());
    return static_cast<ListAst&>(a);
}

const ListAst &ListAst::fromAst(const Ast &a)
{
    assert(a.isList());
    return static_cast<const ListAst&>(a);
}

ListAst::ListAst(Type t)
    : InternalAst(t)
{

}

ListAst *ListAst::clone() const
{
    ListAst *ret = new ListAst(getType());
    for (const std::unique_ptr<Ast> &sub : subtrees)
        ret->subtrees.emplace_back(sub->clone());
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
    child->parent = this;
    doInsert(pos, child);
}

void ListAst::append(Ast *subtree)
{
    insert(size(), subtree);
}

std::unique_ptr<Ast> ListAst::remove(size_t pos)
{
    assert(pos < subtrees.size());
    std::unique_ptr<Ast> res = std::move(subtrees[pos]);
    subtrees.erase(subtrees.begin() + pos);
    return res;
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

