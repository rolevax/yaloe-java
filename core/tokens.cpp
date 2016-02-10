#include "core/tokens.h"
#include "core/bonetoken.h"
#include "core/soultoken.h"
#include <cassert>

#include <QDebug>
#include <iostream>
#include <sstream>

Tokens::Tokens(TokensObserver &ob) :
    hammer(*this),
    ob(ob)
{
    clear();
}

void Tokens::setHotLight(ssize_t back)
{
    ob.observeHotLight(back);
}

/**
 * @brief Make the displayed cursor point to a node.
 * @param inner the node to point
 */
void Tokens::light(const Ast *inner)
{
    Region in = anchor(locate(inner));

    Ast *outer = &inner->getParent();
    Region out = anchor(locate(outer));

    ob.observeLight(out.br, out.bc, out.er, out.ec,
                    in.br, in.bc, in.er, in.ec);
}

/**
 * @brief Apply a insertion change in Ast into Tokens.
 * @param outer Parent of new node
 * @param inner Index of new node within its parent
 * Should be called after Ast's insertion.
 * Also called in Doc::change().
 * When changing a node inside map, will locate by the
 * meta soul token left by Tokens::remove().
 * Deal with commas when outer is list.
 */
void Tokens::insert(const ListAst *outer, size_t inner)
{
    // TODO list? var-size?
    assert(inner < outer->size());

    if (outer->getType() == Ast::Type::CLASS_LIST) {
        hammer.hit(*outer, 0, 0);
    } else if (outer->isList()) {
        if (outer->size() == 1) { // assart
            /* TODO
            Ast *parent = &outer->getParent();
            size_t outerIndex = parent->indexOf(outer);
            remove(parent, outerIndex);
            insert(parent, outerIndex);
            */
            /* recursion terminates when outer is root */
        } else if (inner < outer->size() - 1) { // not very end
            Region younger = locate(&outer->at(inner + 1));
            //suckIndent(younger);
            //write(new BoneToken(outer, ",", false, true), younger.br, younger.bc);
            hammer.hit(outer->at(inner), younger.br, younger.bc);
        } else { // very end
            /*
            Region ass = locate(&outer->at(inner - 1));
            // [ ... comma ass empty-bone-newline ]
            //write(new BoneToken(outer, ",", false, true), ass.er, ++ass.ec);
            // [ ... comma ass-with-comma (auto-newline) nextRC empty-bone-newline ]
            size_t nextR, nextC;
            if (rows[ass.er][ass.ec]->needEnter()) {
                nextR = ass.er + 1;
                nextC = 0;
            } else {
                nextR = ass.er;
                nextC = ass.ec + 1;
            }
            hammer.hit(outer->at(inner), nextR, nextC);
            */
        }
    } else if (outer->isMap()) {
        Region out = locate(outer);
        // works only for JSON
        std::vector<std::unique_ptr<Token>> &row = rows[out.br];
        auto it = std::find_if(row.begin() + out.bc, row.begin() + out.ec + 1,
                               [](const std::unique_ptr<Token> &t) {
                                   return t->getRole() == Token::Role::META;
                               });
        assert(it != row.end());
        size_t bc = it - row.begin();
        row.erase(it); // delete meta token
        hammer.hit(outer->at(inner), out.br, bc);
    } else {
        throw "Tokens::insert uninsertable outer";
    }
}

/**
 * @brief Apply a removal change of Ast.
 * @param outer Parent of the node to remove
 * @param inner Index of the node to remove within its parent
 * This should be called before modifying Ast.
 * If outer is map, will leave a meta placeholder token.
 * Deal with commas when outer is list.
 */
void Tokens::remove(const Ast *outer, size_t inner)
{
    (void) outer; (void) inner;
    /*
    assert(inner < outer->size());

    Region r = locate(&outer->at(inner));
    //suckIndent(r);
    if (outer->isList())
        suckComma(r);
    erase(r);

    if (outer->isMap()) {
        Token *meta = new SoulToken(outer, Token::Role::META);
        rows[r.br].emplace(rows[r.br].begin() + r.bc, meta);
    }
    */
}

void Tokens::clear()
{
    if (rows.size() > 1)
        ob.observeRemoveLine(1, rows.size() - 1);
    rows.clear();
    rows.emplace_back();
    ob.observeUpdateLine(0, pluck(0));
}

/**
 * @brief Apply a scalar change. Assuming it is a one-line change.
 */
void Tokens::updateScalar(const InternalAst *outer, size_t inner)
{
    assert(outer->at(inner).isScalar());
    Region r = locate(&outer->at(inner));

    ob.observeUpdateLine(r.br, pluck(r.br));
}

/**
 * @brief print a row to the returned string
 */
std::string Tokens::pluck(size_t r)
{
    assert(r < rows.size());

    std::string ret;
    for (const std::unique_ptr<Token> &t : rows[r])
        ret += t->getText();

    return ret;
}

/**
 * @brief Vertical concrete cursor moving
 */
void Tokens::jackKick(InternalAst *&outer, size_t &inner, bool down)
{
    Region r = locate(&outer->at(inner));
    for (ssize_t i = down ? r.er + 1 : r.br - 1;
         down ? size_t(i) < rows.size() : i >= 0;
         down ? i++ : i--) {
        for (ssize_t j = rows[i].size() - 1; j - 2 >= 0; j--) {
            const Token &begin = *rows[i][j - 2];
            const Token &end = *rows[i][j];
            const Ast *a = end.getAst();
            if (a->isScalar()
                    || (a == begin.getAst()
                        && begin.getRole() == Token::Role::BEGIN
                        && end.getRole() == Token::Role::END)) {
                outer = &a->getParent();
                inner = outer->indexOf(a);
                light(a);
                return;
            }
        }
    }
}

void Tokens::put(size_t r, size_t c, const std::vector<Token *> &ts)
{
    size_t origR = r;

    for (Token *t : ts) {
        if (t == nullptr) {
            newLine(r, c);
            ++r;
            c = 0;
        } else {
            auto &row = rows[r];
            row.emplace(row.begin() + c, t);
            ++c;
        }
    }

    if (r > origR)
    ob.observeInsertLine(origR, r - origR);

    while (origR <= r) {
        ob.observeUpdateLine(origR, pluck(origR));
        ++origR;
    }
}

/**
 * @brief Tokens::erase
 * @param r
 * Remove all tokens from the region 'r'
 */
void Tokens::erase(const Region &r)
{
    assert(r.br < rows.size() && r.bc < rows[r.br].size());
    assert(r.er < rows.size() && r.ec < rows[r.er].size());
    assert(r.br <= r.er);

    int needJoin = 0;

    if (r.br == r.er) { // one-line erase
        /*
        needJoin += rows[r.er][r.ec]->needEnter();
        auto it = rows[r.br].begin();
        rows[r.br].erase(it + r.bc, it + r.ec + 1);
        */
    } else { // multi-line erase
        /*
        needJoin += rows[r.br].back()->needEnter(); // first line
        */

        /* bottom-up remove from the last row
         * since it won't mess up the row indices
         */

        // remove inside the last line
        /*
        needJoin += rows[r.er][r.ec]->needEnter();
        auto endIt = rows[r.er].begin();
        rows[r.er].erase(endIt, endIt + r.ec + 1);

        if (r.br + 1 < r.er) { // remove internal lines [br+1,er-1]
            rows.erase(rows.begin() + r.br + 1, rows.begin() + r.er);
            ob.observeRemoveLine(r.br + 1, r.er - (r.br + 1));
        }

        // remove inside the first line
        rows[r.br].erase(rows[r.br].begin() + r.bc, rows[r.br].end());
        */
    }


    while (needJoin --> 0)
        joinLine(r.br + 1);

    ob.observeUpdateLine(r.br, pluck(r.br));
}

/**
 * @brief Output in syntatically correct plain text
 */
std::ostream &operator<<(std::ostream &os, const Tokens &ts)
{
    for (const auto &row : ts.rows) {
        for (const auto &t : row)
            os << t->getText();
        os << std::endl;
    }

    return os;
}

/**
 * @brief Find the region of tokens enclosing the specified Ast
 * @param tar The ast node to locate
 * @return The region
 */
Region Tokens::locate(const Ast *tar)
{
    Region res;
    bool found = false;

    for (auto rit = rows.begin(); rit != rows.end(); ++rit) {
        for (auto cit = rit->begin(); cit != rit->end(); ++cit) {
            const Ast *a = (*cit)->getAst();
            if (a == tar) {
                Token::Role role = (*cit)->getRole();
                if (role == Token::Role::BEGIN) {
                    res.br = rit - rows.begin();
                    res.bc = cit - rit->begin();
                } else if (role == Token::Role::END) {
                    res.er = rit - rows.begin();
                    res.ec = cit - rit->begin();
                    found = true;
                    break;
                } else if (role == Token::Role::FLESH) {
                    res.er = rit - rows.begin();
                    res.br = res.er;
                    res.ec = cit - rit->begin();
                    res.bc = res.ec;
                    found = true;
                    break;
                }
            }
        }
    }

    assert(found);
    return res;
}

/**
 * @brief Include a comman that should be removed together
 * 		  with the region.
 * @param r region to remove
 * Assume that comma is adjacent to the "group",
 * including prefix tab indent.
 * @deprecated
 */
void Tokens::suckComma(Region &r)
{
    const Ast *in = rows[r.br][r.bc]->getAst();
    const InternalAst &par = in->getParent();
    if (par.size() > 1) {
        if (par.indexOf(in) == par.size() - 1) {
            /* very end of a non-single-element list
               then include the previous comma,
               which is assumed to be the end of the previous row. */
            if (rows[r.br - 1].back()->getAst() == &par) {
                --r.br;
                r.bc = rows[r.br].size() - 1;
            }
        } else { // first or internel list element
            if (rows[r.er][r.ec + 1]->getAst() == &par)
                ++r.ec; // include the following comma
        }
    }
}

void Tokens::newLine(size_t r, size_t c)
{
    assert(r < rows.size() && c <= rows[r].size());
    rows.emplace(rows.begin() + r + 1);
    auto &newRow = rows[r + 1];
    newRow.insert(newRow.end(),
                  std::make_move_iterator(rows[r].begin() + c),
                  std::make_move_iterator(rows[r].end()));
    rows[r].erase(rows[r].begin() + c, rows[r].end());
}

/**
 * @brief Join the r-th line into the (r-1)-th line
 * @param r
 */
void Tokens::joinLine(size_t r)
{
    assert(r > 0 && r < rows.size());
    auto &prevRow = rows[r - 1];
    prevRow.insert(prevRow.end(),
                   std::make_move_iterator(rows[r].begin()),
                   std::make_move_iterator(rows[r].end()));
    rows.erase(rows.begin() + r);
}

/**
 * @brief Convert token level index into character level index
 * @param r row of token
 * @param c column of token
 * @return column index in terms of character
 * "How many characters are there before the token?"
 */
size_t Tokens::anchor(size_t r, size_t c)
{
    assert(r < rows.size() && c <= rows[r].size());
    size_t offset = 0;
    for (size_t i = 0; i < c; i++)
        offset += rows[r][i]->getText().size();
    return offset;
}

Region Tokens::anchor(const Region &r)
{
   Region c(r);
   c.bc = anchor(c.br, c.bc);
   if (r.br != r.er && r.ec == 0) {
       c.er = r.er - 1;
       c.ec = anchor(r.er - 1, rows[r.er - 1].size());
   } else {
       c.ec = anchor(c.er, c.ec + 1);
   }
   return c;
}

