#include "token_soul.h"

#include <vector>
#include <cassert>

TokenSoul::TokenSoul(const Ast *ast, Role role) :
    Token(ast, role)
{
    assert(role == Role::BEGIN || role == Role::END || role == Role::META);
}

const std::string &TokenSoul::getText() const
{
    static std::vector<std::string> tab;

    if (getRole() != Role::BEGIN)
        return tab[0];

    size_t level = getAst()->hasIndent() ? getAst()->indentLevel() : 0;
    if (level >= tab.size())
        for (size_t i = tab.size(); i <= level; i++)
            tab.emplace_back(4 * i, ' ');

    return tab[level];
}

