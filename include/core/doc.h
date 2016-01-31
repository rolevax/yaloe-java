#ifndef DOC_H
#define DOC_H

#include "core/editabledoc.h"
#include "core/tokens.h"
#include "ast/rootast.h"
#include <stack>

class PDoc;

class Doc : public EditableDoc
{
public:
    Doc(PDoc &dob, TokensObserver &tob);

    Doc(const Doc&) = delete;
    Doc &operator=(const Doc&) = delete;

    void load(const std::string &filename);
    void save(const std::string &filename);
    void keyboard(char key);

private:
    /// @name EditableDoc interface
    ///@{
    void push(Mode *mode) override;
    void pop(Mode *nextPush) override;

    const Ast &getOuter() const override;
    const Ast &getInner() const override;

    void cursorIn() override;
    void cursorForward() override;

    void fallIn() override;
    void digOut() override;
    void sibling(int step) override;
    void jackKick(bool down) override;
    void hackLead(bool right) override;
    void insert(Ast::Type type) override;
    void remove() override;
    void change(Ast::Type type) override;
    void nest(Ast::Type type) override;

    void scalarAppend(const char *str) override;
    void scalarAppend(char c) override;
    void scalarClear() override;

    void setHotLight(bool b) override;
    void toggleTension(bool b) override;
    ///@}

    /// @name "really" private functions
    ///@{
    Ast *newTree(Ast::Type type);
    ///@}

private:
    std::stack<std::unique_ptr<Mode>> modes;
    std::unique_ptr<RootAst> root = nullptr;
    Ast *outer = nullptr;
    size_t inner = 0;
    std::unique_ptr<Ast> clipboard = nullptr;
    Tokens tokens;
    PDoc &ob;
};

#endif // DOC_H
