#ifndef TOKENS_H
#define TOKENS_H

#include "hammer.h"
#include "token.h"
#include "tokensobserver.h"
#include <vector>

class Tokens
{
public:
    Tokens(TokensObserver &ob);

    Tokens(const Tokens&) = delete;
    Tokens &operator=(const Tokens&) = delete;

    void setHotLight(ssize_t back);
    void light(const Ast *inner);
    void insert(const ListAst *outer, size_t inner);
    void remove(const Ast *outer, size_t inner);
    void clear();
    void sync(const ListAst *root);
    void updateScalar(const InternalAst *outer, size_t inner);
    std::string pluck(size_t r);
    void jackKick(InternalAst *&outer, size_t &inner, bool down);

    /// @name Hammer's Interface
    ///@{
    void put(size_t r, size_t c, const std::vector<Token*> &ts);
    void erase(const Region &r);
    ///@}

    friend std::ostream &operator<<(std::ostream &os, const Tokens &ts);

private:
    Region locate(const Ast *tar);
    void suckComma(Region &region);
    void newLine(size_t r, size_t c);
    void joinLine(size_t r);
    size_t anchor(size_t r, size_t c);
    Region anchor(const Region &r);

private:
    std::vector<std::vector<std::unique_ptr<Token>>> rows;
    Hammer hammer;
    TokensObserver &ob;
};

std::ostream &operator<<(std::ostream &os, const Tokens &ts);

#endif // TOKENS_H
