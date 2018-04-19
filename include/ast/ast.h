#ifndef AST_H
#define AST_H

#include <cstddef>
#include <memory>
#include <iostream> // for Ast::dump()

class ScalarAst;
class InternalAst;
template<std::size_t N> class FixSizeAst;
class ListAst;
class BopListAst;

class Ast
{
public:
    /**
     * @brief type of a node in the language tree
     */
    enum class Type {
        // LIST, sync with isList() definition
        CLASS_LIST, MEMBER_LIST, DECL_PARAM_LIST, STMT_LIST,
        IF_LIST, TRY_LIST,
        DECTOR_LIST, ARG_LIST, NAME_LIST,

        // BOP-LIST, sync with isBopList() and isList() definition
        DOT_BOP_LIST, MUL_BOP_LIST, ADD_BOP_LIST,
        LOGIC_AND_BOP_LIST, LOGIC_OR_BOP_LIST,

        // FIX-SIZE, sync with isFixSize() definition
        // size 1
        RETURN, BREAK, CONTINUE, THROW,
        POST_INC, POST_DEC, PRE_INC, PRE_DEC,
        UNARY_PLUS, UNARY_MINUS, LOGIC_NOT, BIT_NOT,
        // size 2
        DECL_VAR, DECL_PARAM, WHILE, DO_WHILE, IF_CONDBODY,
        CATCH,
        CAST,
        LT, LEQ, GT, GEQ, INSTANCEOF, EQ, NEQ, SHL, SHR, SHRA,
        BIT_OR, BIT_XOR, BIT_AND,
        ASSIGN, ASS_ADD, ASS_SUB, ASS_MUL, ASS_DIV, ASS_MOD,
        ASS_AND, ASS_XOR, ASS_OR, ASS_SHL, ASS_SHR, ASS_SHRA,
        // size 3
        QUESTION, NEW_CLASS, NEW_ARRAY,
        // size 4
        DECL_CLASS, DECL_INTERFACE, FOR,
        // size 5
        DECL_METHOD,

        // SCALAR, isScalar() := !isList() && !isFixSize()
        IDENT, NUMBER, STRING, META, HIDDEN
    };

    Ast(Type t);
    Ast(const Ast &copy) = delete;
    Ast &operator=(const Ast &assign) = delete;
    virtual ~Ast() = default;

    virtual void dump() const {} // for debug use

    static bool isList(Type mType);
    static bool isBopList(Type mType);
    static bool isFixSize(Type mType, size_t s = 0);
    static bool isScalar(Type mType);
    bool isList() const;
    bool isBopList() const;
    bool isFixSize(size_t s = 0) const;
    bool isScalar() const;

    ScalarAst &asScalar();
    const ScalarAst &asScalar() const;
    InternalAst &asInternal();
    const InternalAst &asInternal() const;
    template<std::size_t N> FixSizeAst<N> &asFixSize();
    template<std::size_t N> const FixSizeAst<N> &asFixSize() const;
    ListAst &asList();
    const ListAst &asList() const;
    BopListAst &asBopList();
    const BopListAst &asBopList() const;

    ListAst *bodify();
    static int precedence(Type mType);
    int precedence() const;

    /**
     * @brief Recursive value deep copy
     * @return Ast with same value but parent is null
     */
    virtual Ast *clone() const = 0;

    Type getType() const;
    InternalAst &getParent() const;
    void setParent(InternalAst *next);

    bool hasIndent() const;
    int indentLevel() const;

private:
    Type mType;
    InternalAst *mParent;
};

#endif // AST_H
