#include "ast/fixsizeast.h"

#include <algorithm>
#include <cassert>

template<std::size_t N>
void FixSizeAst<N>::dump() const
{
    for (const auto &p : subtrees)
        p->dump();
}

template<std::size_t N>
size_t FixSizeAst<N>::size() const
{
    return N;
}

template<std::size_t N>
Ast &FixSizeAst<N>::at(size_t pos) const
{
    assert(pos < N);
    return *subtrees[pos];
}

template<std::size_t N>
size_t FixSizeAst<N>::indexOf(const Ast *child) const
{
    auto eq = [child](const std::unique_ptr<Ast> &p) { return p.get() == child; };
    auto it = std::find_if(subtrees.begin(), subtrees.end(), eq);
    assert(it != subtrees.end());
    return it - subtrees.begin();
}

template<std::size_t N>
void FixSizeAst<N>::doChange(size_t pos, Ast *next)
{
    assert(pos < N);
    subtrees[pos].reset(next);
}

template class FixSizeAst<1>;
template class FixSizeAst<2>;
template class FixSizeAst<3>;
