#pragma once
#include <functional>
#include <string>
#include <stack>
#include <list>
#include <map>

#include <hygge/Token.h>
#include <hygge/List.h>

namespace hygge {

class Parser
{
public:
    using Id = std::string;
    using JumpId = int;
    using Position = int;
    using VarValue = double;
    using VariableSpace = std::map<Id, VarValue>;
    using ListSpace = std::map<Id, List>;

    using OpStackTokenType = grammar::terminal::Type;
    using CurrentTokenType = grammar::terminal::Type;

    Parser();

    ~Parser() = default;

    void process(const TokenList& tokens);

    VariableSpace& getVariables();

    ListSpace& getLists();

    TokenList& getPreRpn();

    TokenList& getRpn();

private:
    bool expr();

    bool statement();

    bool whileLoop();

    bool branch();

    bool print();

    bool varDef();

    bool assign();

    bool computing();

    bool listOp();

    bool listAddOp();

    bool listRemoveOp();

    bool listGetOp();

    bool listPos();

    bool setOp();

    bool setAddOp();

    bool setRemoveOp();

    bool setHasOp();

    bool value();

    bool op();

    bool checkStatement();

    bool checkOp();

    bool ifBranch();

    bool printable();


    void checkToken(grammar::terminal::Type terminalType,
        TokenList::const_iterator tokenIterator) const;

    void checkToken(grammar::terminal::Type terminalType1,
        grammar::terminal::Type terminalType2,
        TokenList::const_iterator tokenIterator) const;

    void checkToken(grammar::terminal::Type terminalType1,
        grammar::terminal::Type terminalType2,
        grammar::terminal::Type terminalType3,
        TokenList::const_iterator tokenIterator) const;

    void checkToken(grammar::terminal::Type terminalType1,
        grammar::terminal::Type terminalType2,
        grammar::terminal::Type terminalType3,
        grammar::terminal::Type terminalType4,
        TokenList::const_iterator tokenIterator) const;

    void checkToken(grammar::terminal::Type terminalType1,
        grammar::terminal::Type terminalType2,
        grammar::terminal::Type terminalType3,
        grammar::terminal::Type terminalType4,
        grammar::terminal::Type terminalType5, TokenList::const_iterator tokenIterator) const;

    void checkToken(grammar::terminal::Type terminalType1,
        grammar::terminal::Type terminalType2,
        grammar::terminal::Type terminalType3,
        grammar::terminal::Type terminalType4,
        grammar::terminal::Type terminalType5,
        grammar::terminal::Type terminalType6,
        TokenList::const_iterator tokenIterator) const;

    bool isTokenEq(grammar::terminal::Type terminalType, TokenList::const_iterator tokenIterator) const;

    void badToken(grammar::terminal::Type terminalType, 
        TokenList::const_iterator tokenIterator) const;

    void badToken(grammar::terminal::Type terminalType1,
        grammar::terminal::Type terminalType2, 
        TokenList::const_iterator tokenIterator) const;

    void badToken(grammar::terminal::Type terminalType1,
        grammar::terminal::Type terminalType2,
        grammar::terminal::Type terminalType3, 
        TokenList::const_iterator tokenIterator) const;

    void badToken(grammar::terminal::Type terminalType1,
        grammar::terminal::Type terminalType2,
        grammar::terminal::Type terminalType3,
        grammar::terminal::Type terminalType4, 
        TokenList::const_iterator tokenIterator) const;

    void badToken(grammar::terminal::Type terminalType1,
        grammar::terminal::Type terminalType2,
        grammar::terminal::Type terminalType3,
        grammar::terminal::Type terminalType4,
        grammar::terminal::Type terminalType5, TokenList::const_iterator tokenIterator) const;

    void badToken(grammar::terminal::Type terminalType1, 
        grammar::terminal::Type terminalType2, 
        grammar::terminal::Type terminalType3,
        grammar::terminal::Type terminalType4,
        grammar::terminal::Type terminalType5, 
        grammar::terminal::Type terminalType6, 
        TokenList::const_iterator tokenIterator) const;


    bool isVarAlreadyExists(const std::string& name);

    bool isListAlreadyExists(const std::string& name);

    bool isSetAlreadyExists(const std::string& name);


    void initVariable(const std::string& name, double value = 0.0);

    void initList(const std::string& name);


    void rpnConvert();

    void addToOpStack(const Token& token);
    void fromOpStackToRpn();
    void removeFromOpStack();
    void goodPreRpn();
    void badPreRpn() const;

    TokenList::const_iterator m_rpnTokenIterator;

    TokenList::const_iterator m_tokenIterator;


    void rpnComputing();

    double getValueFromToken(const Token& token);


    VariableSpace m_variables;

    ListSpace m_lists;


    std::map<std::pair<OpStackTokenType, CurrentTokenType>, std::function<void(const Token&)>> m_rpnFsmHandlers;

    TokenList m_rpn;

    std::stack<Token> m_opStack;

    TokenList m_preRpn;


    static JumpId m_currentJumpId;

    JumpId getNextJumpId();

    std::map<JumpId, Position> m_jumpIds;
};
}
