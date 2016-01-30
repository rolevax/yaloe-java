#ifndef SOULTOKEN_H
#define SOULTOKEN_H

#include "core/token.h"

class SoulToken : public Token
{
public:
    SoulToken(const Ast *ast, Role role);

    const std::string &getText() const;
};

#endif // SOULTOKEN_H
