#include "listast.h"
#include "scalarast.h"

#include <algorithm>
#include <cassert>

ListAst::ListAst(Type t)
    : InternalAst(t)
{
    assert(isList());
}

void ListAst::dump() const
{
    std::cout << '[';
    for (size_t i = 0; i < size(); i++) {
        const auto &t = at(i);
        t.dump();
        if (i != size() - 1)
            std::cout << ',';
    }
    std::cout << ']';
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
    return mSubtrees.size();
}

Ast &ListAst::at(size_t pos) const
{
    return *mSubtrees[pos];
}

size_t ListAst::indexOf(const Ast *child) const
{
    auto eq = [child](const std::unique_ptr<Ast> &a) {
        return a.get() == child;
    };
    auto it = std::find_if(mSubtrees.begin(), mSubtrees.end(), eq);

    if (it == mSubtrees.end())
        return assert(false && "child not found"), 0;
    else
        return it - mSubtrees.begin();
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

void ListAst::erase(size_t pos)
{
    delete remove(pos);
}

Ast *ListAst::remove(size_t pos)
{
    assert(pos < mSubtrees.size());
    Ast *res = mSubtrees[pos].release();
    mSubtrees.erase(mSubtrees.begin() + pos);
    return res;
}

void ListAst::clear()
{
    mSubtrees.clear();
}

bool ListAst::illZero(bool assumeSize) const
{
    if (!assumeSize && 0 != size())
        return false;
    if (illOne(true)) // assume all ill-one is also ill-zero
        return true;

    Type t = getType();
    return t == Type::TRY_LIST
            || t == Type::NAME_LIST;
}

bool ListAst::illOne(bool assumeSize) const
{
    if (!assumeSize && 1 != size())
        return false;

    if (isBopList()) // binary operator must be binary
        return true;

    Ast::Type t = getType();
    return t == Type::DECTOR_LIST
            || t == Type::IF_LIST;
}

void ListAst::doInsert(size_t pos, Ast *child)
{
    mSubtrees.emplace(mSubtrees.begin() + pos, child);
}

void ListAst::doChange(size_t pos, Ast *next)
{
    assert(pos < mSubtrees.size());
    mSubtrees[pos].reset(next);
}

