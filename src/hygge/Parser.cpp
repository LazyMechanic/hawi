#include <hygge/Parser.h>
#include <stdexcept>
#include <iostream>

namespace hygge {
using namespace grammar::terminal;

Parser::JumpId Parser::m_currentJumpId = 0;

Parser::Parser()
{
    m_rpnFsmHandlers = {
        // =============================================== //
        {{Mark, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{AssignOperator, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{EqualOperator, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{NotEqualOperator, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{GreaterOperator, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{LessOperator, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{GreaterOrEqualOperator, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{LessOrEqualOperator, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{KeywordListAdd, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{KeywordListRemove, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{KeywordListGet, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{KeywordPrint, Mark}, [this](const Token&) {
            goodPreRpn();
        }},
        {{AddOperator, Mark}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{SubOperator, Mark}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{MultOperator, Mark}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{DivOperator, Mark}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{OpenBracket, Mark}, [this](const Token&) {
            badPreRpn();
        }},

        // =============================================== //
        {{Mark, AddOperator}, [this](const Token& token) {
            addToOpStack(token);
        }},
        {{AssignOperator, AddOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},
        { {EqualOperator, AddOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {NotEqualOperator, AddOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {GreaterOperator, AddOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {LessOperator, AddOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {GreaterOrEqualOperator, AddOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {LessOrEqualOperator, AddOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListAdd, AddOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListRemove, AddOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListGet, AddOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordPrint, AddOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        {{AddOperator, AddOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{SubOperator, AddOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{MultOperator, AddOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{DivOperator, AddOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{OpenBracket, AddOperator}, [this](const Token& token) {
            addToOpStack(token);
        }},

        // =============================================== //
        {{Mark, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},
        {{AssignOperator, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},
        { {EqualOperator, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {NotEqualOperator, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {GreaterOperator, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {LessOperator, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {GreaterOrEqualOperator, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {LessOrEqualOperator, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListAdd, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListRemove, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListGet, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordPrint, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        {{AddOperator, SubOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{SubOperator, SubOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{MultOperator, SubOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{DivOperator, SubOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{OpenBracket, SubOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},

        // =============================================== //
        {{Mark, MultOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},
        {{AssignOperator, MultOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},
        { {EqualOperator, MultOperator}, [this](const Token& token) {
            addToOpStack(token);
        } },
        { {NotEqualOperator, MultOperator}, [this](const Token& token) {
            addToOpStack(token);
        } },
        { {GreaterOperator, MultOperator}, [this](const Token& token) {
            addToOpStack(token);
        } },
        { {LessOperator, MultOperator}, [this](const Token& token) {
            addToOpStack(token);
        } },
        { {GreaterOrEqualOperator, MultOperator}, [this](const Token& token) {
            addToOpStack(token);
        } },
        { {LessOrEqualOperator, MultOperator}, [this](const Token& token) {
            addToOpStack(token);
        } },
        { {KeywordListAdd, MultOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListRemove, MultOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListGet, MultOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordPrint, MultOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        {{AddOperator, MultOperator}, [this](const Token& token) {
            addToOpStack(token);
        }},
        {{SubOperator, MultOperator}, [this](const Token& token) {
            addToOpStack(token);
        }},
        {{MultOperator, MultOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{DivOperator, MultOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{OpenBracket, MultOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},

        // =============================================== //
        {{Mark, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},
        {{AssignOperator, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},
        { {EqualOperator, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {NotEqualOperator, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {GreaterOperator, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {LessOperator, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {GreaterOrEqualOperator, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {LessOrEqualOperator, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListAdd, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListRemove, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListGet, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordPrint, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        } },
        {{AddOperator, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},
        {{SubOperator, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},
        {{MultOperator, DivOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{DivOperator, DivOperator}, [this](const Token&) {
            fromOpStackToRpn();
        }},
        {{OpenBracket, DivOperator}, [this](const Token & token) {
            addToOpStack(token);
        }},

        // =============================================== //
        {{Mark, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        }},
        {{AssignOperator, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        }},
        { {EqualOperator, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {NotEqualOperator, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {GreaterOperator, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {LessOperator, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {GreaterOrEqualOperator, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {LessOrEqualOperator, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListAdd, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListRemove, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordListGet, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        } },
        { {KeywordPrint, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        } },
        {{AddOperator, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        }},
        {{SubOperator, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        }},
        {{MultOperator, OpenBracket}, [this](const Token& token) {
            addToOpStack(token);
        }},
        {{DivOperator, OpenBracket}, [this](const Token& token) {
            addToOpStack(token);
        }},
        {{OpenBracket, OpenBracket}, [this](const Token & token) {
            addToOpStack(token);
        }},

        // =============================================== //
        {{Mark, CloseBracket}, [this](const Token &) {
            badPreRpn();
        }},
        {{AssignOperator, CloseBracket}, [this](const Token&) {
            badPreRpn();
        }},
        { {EqualOperator, CloseBracket}, [this](const Token&) {
            badPreRpn();
        } },
        { {NotEqualOperator, CloseBracket}, [this](const Token&) {
            badPreRpn();
        } },
        { {GreaterOperator, CloseBracket}, [this](const Token&) {
            badPreRpn();
        } },
        { {LessOperator, CloseBracket}, [this](const Token&) {
            badPreRpn();
        } },
        { {GreaterOrEqualOperator, CloseBracket}, [this](const Token&) {
            badPreRpn();
        } },
        { {LessOrEqualOperator, CloseBracket}, [this](const Token&) {
            badPreRpn();
        } },
        { {KeywordListAdd, CloseBracket}, [this](const Token &) {
            badPreRpn();
        } },
        { {KeywordListRemove, CloseBracket}, [this](const Token &) {
            badPreRpn();
        } },
        { {KeywordListGet, CloseBracket}, [this](const Token &) {
            badPreRpn();
        } },
        { {KeywordPrint, OpenBracket}, [this](const Token &) {
            badPreRpn();
        } },
        {{AddOperator, CloseBracket}, [this](const Token &) {
            fromOpStackToRpn();
        }},
        {{SubOperator, CloseBracket}, [this](const Token &) {
            fromOpStackToRpn();
        }},
        {{MultOperator, CloseBracket}, [this](const Token &) {
            fromOpStackToRpn();
        }},
        {{DivOperator, CloseBracket}, [this](const Token &) {
            fromOpStackToRpn();
        }},
        {{OpenBracket, CloseBracket}, [this](const Token &) {
            removeFromOpStack();
        }}
    };

    m_opStack.emplace(Mark, "");
}

void Parser::process(const std::list<Token>& tokens)
{
    m_variables.clear();
    m_lists.clear();
    m_rpn.clear();
    m_opStack = std::stack<Token>();
    m_opStack.emplace(Mark, "");
    m_preRpn.clear();
    m_jumpIds.clear();    

    m_tokenIterator = tokens.begin();
    while (m_tokenIterator != tokens.end()) {
        bool isExpr = expr();
        if (!isExpr)
            throw std::runtime_error("Unexpected nonterminal. Token = { value: " + m_tokenIterator->value + ", type: " + std::to_string(m_tokenIterator->type));
    }

    rpnConvert();
    rpnComputing();
}

Parser::VariableSpace& Parser::getVariables()
{
    return m_variables;
}

Parser::ListSpace& Parser::getLists()
{
    return m_lists;
}

TokenList& Parser::getPreRpn()
{
    return m_preRpn;
}

TokenList& Parser::getRpn()
{
    return m_rpn;
}

bool Parser::expr()
{
    const auto startTokenIterator = m_tokenIterator;
    bool isValid = statement();

    if (!isValid) {
        m_tokenIterator = startTokenIterator;
        isValid = whileLoop();
    }

    if (!isValid) {
        m_tokenIterator = startTokenIterator;
        isValid = branch();
    }

    if (!isValid) {
        m_tokenIterator = startTokenIterator;
    }

    return isValid;
}

bool Parser::statement()
{
    const auto startTokenIterator = m_tokenIterator;
    bool isValid = varDef();

    if (!isValid) {
        m_tokenIterator = startTokenIterator;
        isValid = assign();
    }

    if (!isValid) {
        m_tokenIterator = startTokenIterator;
        isValid = listOp();
    }

    if (!isValid) {
        m_tokenIterator = startTokenIterator;
        isValid = setOp();
    }

    if (!isValid) {
        m_tokenIterator = startTokenIterator;
        isValid = print();
    }

    if (isValid) {
        checkToken(Semicolon, m_tokenIterator);

        ++m_tokenIterator;

        return true;
    }

    return false;
}

bool Parser::whileLoop()
{
    if (m_tokenIterator->type != KeywordWhile)
        return false;

    ++m_tokenIterator;
    checkToken(OpenBracket, m_tokenIterator++);

    JumpId jumpId = getNextJumpId();
    JumpId jumpIfId = getNextJumpId();


    m_preRpn.emplace_back(ResponsePosition, std::to_string(jumpId));

    checkStatement();

    m_preRpn.emplace_back(Mark, "");
    m_preRpn.emplace_back(KeywordIf, "");
    m_preRpn.emplace_back(RequestPosition, std::to_string(jumpIfId));

    checkToken(CloseBracket, m_tokenIterator++);
    checkToken(OpenBrace, m_tokenIterator++);

    while (expr()) {}

    checkToken(CloseBrace, m_tokenIterator++);

    m_preRpn.emplace_back(RequestPosition, std::to_string(jumpId));
    m_preRpn.emplace_back(ResponsePosition, std::to_string(jumpIfId));
    m_preRpn.emplace_back(Mark, "");

    return true;
}

bool Parser::branch()
{
    return ifBranch();
}

bool Parser::print()
{
    if (m_tokenIterator->type != KeywordPrint)
        return false;

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    printable();

    m_preRpn.emplace_back(Mark, "");

    return true;
}

bool Parser::varDef()
{
    bool isValid = false;
    switch (m_tokenIterator->type) {
    case Type::KeywordLet:
        ++m_tokenIterator;

        checkToken(Type::Id, m_tokenIterator);

        if (!isVarAlreadyExists(m_tokenIterator->value)) {
            initVariable(m_tokenIterator->value);
        }
        else {
            throw std::runtime_error("The Variable = { " + m_tokenIterator->value + " } already exists");
        }
        break;
    case Type::KeywordList:
        ++m_tokenIterator;

        checkToken(Type::Id, m_tokenIterator);

        if (!isListAlreadyExists(m_tokenIterator->value)) {
            initList(m_tokenIterator->value);
        }
        else {
            throw std::runtime_error("The List = { " + m_tokenIterator->value + " } already exists");
        }
        break;
    case Type::KeywordSet:
        // TODO: create set logic
        break;
    default:
        return false;
        break;
    }

    ++m_tokenIterator;
    return true;
}

bool Parser::assign()
{
    if (m_tokenIterator->type != Type::Id)
        return false;

    if (!isVarAlreadyExists(m_tokenIterator->value))
        throw std::runtime_error("The Var = { " + m_tokenIterator->value + " } doesnt definition");

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    checkToken(Type::AssignOperator, m_tokenIterator);

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    computing();

    // Mark of ending
    m_preRpn.emplace_back(Type::Mark, "");

    return true;
}

bool Parser::computing()
{
    value();
    while(op()) {
        value();
    }

    return true;
}

bool Parser::listOp()
{
    const auto startTokenIterator = m_tokenIterator;
    bool isValid = listAddOp();

    if (!isValid) {
        m_tokenIterator = startTokenIterator;
        isValid = listRemoveOp();
    }

    if (!isValid) {
        m_tokenIterator = startTokenIterator;
        isValid = listGetOp();
    }

    if (isValid) {
        m_preRpn.emplace_back(Mark, "");
    }

    return isValid;
}

bool Parser::listAddOp()
{
    if (m_tokenIterator->type != Type::KeywordListAdd)
        return false;

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    checkToken(Type::Id, m_tokenIterator);

    if (!isListAlreadyExists(m_tokenIterator->value))
        throw std::runtime_error("The List = { " + m_tokenIterator->value + " } doesnt definition");

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    value();

    listPos();

    return true;
}

bool Parser::listRemoveOp()
{
    if (m_tokenIterator->type != Type::KeywordListRemove)
        return false;

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    checkToken(Type::Id, m_tokenIterator);

    if (!isListAlreadyExists(m_tokenIterator->value))
        throw std::runtime_error("The List = { " + m_tokenIterator->value + " } doesnt definition");

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    listPos();

    return true;
}

bool Parser::listGetOp()
{
    if (m_tokenIterator->type != Type::KeywordListGet)
        return false;

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    checkToken(Type::Id, m_tokenIterator);

    if (!isListAlreadyExists(m_tokenIterator->value))
        throw std::runtime_error("The List = { " + m_tokenIterator->value + " } doesnt definition");

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    checkToken(Type::Id, m_tokenIterator);

    if (!isVarAlreadyExists(m_tokenIterator->value))
        throw std::runtime_error("The Var = { " + m_tokenIterator->value + " } doesnt definition");

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    listPos();

    return true;
}

bool Parser::listPos()
{
    checkToken(KeywordBack, KeywordFront, Digit, Type::Id, m_tokenIterator);

    if (m_tokenIterator->type == Type::Id) {
        if (!isVarAlreadyExists(m_tokenIterator->value))
            throw std::runtime_error("The Var = {" + m_tokenIterator->value + "} doesnt definition");
    }

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    return true;
}

bool Parser::setOp()
{
    return false;
}

bool Parser::setAddOp()
{
    return true;
}

bool Parser::setRemoveOp()
{
    return true;
}

bool Parser::setHasOp()
{
    return false;
}

bool Parser::value()
{
    checkToken(Type::Id, Type::Digit, Type::FloatDigit, Type::OpenBracket, m_tokenIterator);

    if (m_tokenIterator->type == Type::Id) {
        if (!isVarAlreadyExists(m_tokenIterator->value))
            throw std::runtime_error("The Var = { " + m_tokenIterator->value + " } doesnt definition");
    }

    m_preRpn.push_back(*m_tokenIterator);

    if (isTokenEq(Type::OpenBracket, m_tokenIterator)) {
        ++m_tokenIterator;
        computing();
        checkToken(Type::CloseBracket, m_tokenIterator);

        m_preRpn.push_back(*m_tokenIterator);
    }

    ++m_tokenIterator;
    return true;
}

bool Parser::op()
{
    if (isTokenEq(Type::AddOperator, m_tokenIterator) ||
        isTokenEq(Type::SubOperator, m_tokenIterator) ||
        isTokenEq(Type::MultOperator, m_tokenIterator) ||
        isTokenEq(Type::DivOperator, m_tokenIterator))
    {
        m_preRpn.push_back(*m_tokenIterator);

        ++m_tokenIterator;
        return true;
    }

    return false;
}

bool Parser::checkStatement()
{
    computing();
    checkOp();
    computing();

    return true;
}

bool Parser::checkOp()
{
    checkToken(EqualOperator,
        NotEqualOperator,
        GreaterOperator,
        LessOperator, 
        GreaterOrEqualOperator,
        LessOrEqualOperator, 
        m_tokenIterator);

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    return true;
}

bool Parser::ifBranch()
{
    if (m_tokenIterator->type != Type::KeywordIf)
        return false;

    ++m_tokenIterator;
    checkToken(OpenBracket, m_tokenIterator++);

    JumpId jumpId = getNextJumpId();

    checkStatement();

    m_preRpn.emplace_back(Mark, "");
    m_preRpn.emplace_back(KeywordIf, "");
    m_preRpn.emplace_back(RequestPosition, std::to_string(jumpId));

    checkToken(CloseBracket, m_tokenIterator++);
    checkToken(OpenBrace, m_tokenIterator++);

    while (expr()) {}

    checkToken(CloseBrace, m_tokenIterator++);

    m_preRpn.emplace_back(ResponsePosition, std::to_string(jumpId));
    m_preRpn.emplace_back(Mark, "");

    return true;
}

bool Parser::printable()
{
    checkToken(Type::Id, Digit, FloatDigit, m_tokenIterator);

    if (m_tokenIterator->type == Type::Id) {
        if (!isVarAlreadyExists(m_tokenIterator->value) &&
            !isListAlreadyExists(m_tokenIterator->value))
            throw std::runtime_error("The Var = { " + m_tokenIterator->value + " } doesnt definition");
    }

    m_preRpn.push_back(*m_tokenIterator);

    ++m_tokenIterator;
    return true;
}

void Parser::checkToken(grammar::terminal::Type terminalType, TokenList::const_iterator tokenIterator) const
{
    if (!isTokenEq(terminalType, tokenIterator))
        badToken(terminalType, tokenIterator);
}

void Parser::checkToken(grammar::terminal::Type terminalType1,
    grammar::terminal::Type terminalType2,
    TokenList::const_iterator tokenIterator) const
{
    if (!(isTokenEq(terminalType1, tokenIterator) ||
        isTokenEq(terminalType2, tokenIterator)))
    {
        badToken(terminalType1,
            terminalType2,
            tokenIterator);
    }
}

void Parser::checkToken(grammar::terminal::Type terminalType1,
    grammar::terminal::Type terminalType2,
    grammar::terminal::Type terminalType3,
    TokenList::const_iterator tokenIterator) const
{
    if (!(isTokenEq(terminalType1, tokenIterator) ||
        isTokenEq(terminalType2, tokenIterator) ||
        isTokenEq(terminalType3, tokenIterator)))
    {
        badToken(terminalType1,
            terminalType2,
            terminalType3,
            tokenIterator);
    }
}

void Parser::checkToken(grammar::terminal::Type terminalType1,
    grammar::terminal::Type terminalType2,
    grammar::terminal::Type terminalType3,
    grammar::terminal::Type terminalType4,
    TokenList::const_iterator tokenIterator) const
{
    if (!(isTokenEq(terminalType1, tokenIterator) ||
        isTokenEq(terminalType2, tokenIterator) ||
        isTokenEq(terminalType3, tokenIterator) ||
        isTokenEq(terminalType4, tokenIterator)))
    {
        badToken(terminalType1,
            terminalType2,
            terminalType3,
            terminalType4,
            tokenIterator);
    }
}

void Parser::checkToken(grammar::terminal::Type terminalType1,
    grammar::terminal::Type terminalType2,
    grammar::terminal::Type terminalType3,
    grammar::terminal::Type terminalType4,
    grammar::terminal::Type terminalType5,
    TokenList::const_iterator tokenIterator) const
{
    if (!(isTokenEq(terminalType1, tokenIterator) ||
        isTokenEq(terminalType2, tokenIterator) ||
        isTokenEq(terminalType3, tokenIterator) ||
        isTokenEq(terminalType4, tokenIterator) ||
        isTokenEq(terminalType5, tokenIterator)))
    {
        badToken(terminalType1,
            terminalType2,
            terminalType3,
            terminalType4,
            terminalType5,
            tokenIterator);
    }
}

void Parser::checkToken(grammar::terminal::Type terminalType1,
    grammar::terminal::Type terminalType2,
    grammar::terminal::Type terminalType3,
    grammar::terminal::Type terminalType4,
    grammar::terminal::Type terminalType5,
    grammar::terminal::Type terminalType6,
    TokenList::const_iterator tokenIterator) const
{
    if (!(isTokenEq(terminalType1, tokenIterator) ||
        isTokenEq(terminalType2, tokenIterator) ||
        isTokenEq(terminalType3, tokenIterator) ||
        isTokenEq(terminalType4, tokenIterator) ||
        isTokenEq(terminalType5, tokenIterator) ||
        isTokenEq(terminalType6, tokenIterator)))
    {
        badToken(terminalType1,
            terminalType2,
            terminalType3,
            terminalType4,
            terminalType5,
            terminalType6, tokenIterator);
    }
}

bool Parser::isTokenEq(grammar::terminal::Type terminalType, TokenList::const_iterator tokenIterator) const
{
    return terminalType == tokenIterator->type;
}

void Parser::badToken(grammar::terminal::Type terminalType, TokenList::const_iterator tokenIterator) const
{
    throw std::runtime_error("Token = { type: " + std::to_string(terminalType) + " } expected, but Token = { type: " + std::to_string(tokenIterator->type) + ", value: " + tokenIterator->value + " } found");
}

void Parser::badToken(grammar::terminal::Type terminalType1,
    grammar::terminal::Type terminalType2,
    TokenList::const_iterator tokenIterator) const
{
    throw std::runtime_error(
        "Token = { type: " + 
        std::to_string(terminalType1) + 
        " | " + 
        std::to_string(terminalType2) + 
        " } expected, but Token = { type: " + 
        std::to_string(tokenIterator->type) + 
        ", value: " + 
        tokenIterator->value + 
        " } found");
}

void Parser::badToken(grammar::terminal::Type terminalType1,
    grammar::terminal::Type terminalType2,
    grammar::terminal::Type terminalType3,
    TokenList::const_iterator tokenIterator) const
{
    throw std::runtime_error(
        "Token = { type: " +
        std::to_string(terminalType1) +
        " | " +
        std::to_string(terminalType2) +
        " | " +
        std::to_string(terminalType3) +
        " | " +
        " } expected, but Token = { type: " +
        std::to_string(tokenIterator->type) +
        ", value: " +
        tokenIterator->value +
        " } found");
}

void Parser::badToken(grammar::terminal::Type terminalType1,
    grammar::terminal::Type terminalType2,
    grammar::terminal::Type terminalType3,
    grammar::terminal::Type terminalType4,
    TokenList::const_iterator tokenIterator) const
{
    throw std::runtime_error(
        "Token = { type: " +
        std::to_string(terminalType1) +
        " | " +
        std::to_string(terminalType2) +
        " | " +
        std::to_string(terminalType3) +
        " | " +
        std::to_string(terminalType4) +
        " } expected, but Token = { type: " +
        std::to_string(tokenIterator->type) +
        ", value: " +
        tokenIterator->value +
        " } found");
}

void Parser::badToken(grammar::terminal::Type terminalType1,
    grammar::terminal::Type terminalType2,
    grammar::terminal::Type terminalType3,
    grammar::terminal::Type terminalType4,
    grammar::terminal::Type terminalType5,
    TokenList::const_iterator tokenIterator) const
{
    throw std::runtime_error(
        "Token = { type: " +
        std::to_string(terminalType1) +
        " | " +
        std::to_string(terminalType2) +
        " | " +
        std::to_string(terminalType3) +
        " | " +
        std::to_string(terminalType4) +
        " | " +
        std::to_string(terminalType5) +
        " | " +
        " } expected, but Token = { type: " +
        std::to_string(tokenIterator->type) +
        ", value: " +
        tokenIterator->value +
        " } found");
}

void Parser::badToken(grammar::terminal::Type terminalType1,
    grammar::terminal::Type terminalType2,
    grammar::terminal::Type terminalType3,
    grammar::terminal::Type terminalType4,
    grammar::terminal::Type terminalType5,
    grammar::terminal::Type terminalType6,
    TokenList::const_iterator tokenIterator) const
{
    throw std::runtime_error(
        "Token = { type: " +
        std::to_string(terminalType1) +
        " | " +
        std::to_string(terminalType2) +
        " | " +
        std::to_string(terminalType3) +
        " | " +
        std::to_string(terminalType4) +
        " | " +
        std::to_string(terminalType5) +
        " | " +
        std::to_string(terminalType6) +
        " } expected, but Token = { type: " +
        std::to_string(tokenIterator->type) +
        ", value: " +
        tokenIterator->value +
        " } found");
}

bool Parser::isVarAlreadyExists(const std::string& name)
{
    return m_variables.find(name) != m_variables.end();
}

bool Parser::isListAlreadyExists(const std::string& name)
{
    return m_lists.find(name) != m_lists.end();
}

bool Parser::isSetAlreadyExists(const std::string& name)
{
    return false;
}

void Parser::initVariable(const std::string& name, double value)
{
    m_variables[name] = value;
}

void Parser::initList(const std::string& name)
{
    m_lists[name] = List();
}

void Parser::rpnConvert()
{
    for (m_rpnTokenIterator = m_preRpn.begin(); m_rpnTokenIterator != m_preRpn.end(); ++m_rpnTokenIterator) {
        if (m_rpnTokenIterator->type == Type::Id ||
            m_rpnTokenIterator->type == Digit ||
            m_rpnTokenIterator->type == FloatDigit ||
            m_rpnTokenIterator->type == KeywordFront ||
            m_rpnTokenIterator->type == KeywordBack)
        {
            m_rpn.push_back(*m_rpnTokenIterator);
            continue;
        }

        if (m_rpnTokenIterator->type == AssignOperator ||
            m_rpnTokenIterator->type == EqualOperator ||
            m_rpnTokenIterator->type == NotEqualOperator ||

            m_rpnTokenIterator->type == GreaterOperator ||
            m_rpnTokenIterator->type == LessOperator ||
            m_rpnTokenIterator->type == GreaterOrEqualOperator ||
            m_rpnTokenIterator->type == LessOrEqualOperator ||
            m_rpnTokenIterator->type == KeywordListAdd ||
            m_rpnTokenIterator->type == KeywordListRemove ||
            m_rpnTokenIterator->type == KeywordListGet ||
            m_rpnTokenIterator->type == KeywordPrint)
        {
            addToOpStack(*m_rpnTokenIterator);
            continue;
        }

        if (m_rpnTokenIterator->type == ResponsePosition ||
            m_rpnTokenIterator->type == RequestPosition ||
            m_rpnTokenIterator->type == KeywordIf)
        {
            m_rpn.push_back(*m_rpnTokenIterator);

            if (m_rpnTokenIterator->type == ResponsePosition) {
                m_jumpIds[std::stoi(m_rpnTokenIterator->value)] = m_rpn.size() - 1;
            }

            continue;
        }

        m_rpnFsmHandlers[{m_opStack.top().type, m_rpnTokenIterator->type}](*m_rpnTokenIterator);
    }
}

void Parser::addToOpStack(const Token& token)
{
    m_opStack.push(token);
}

void Parser::fromOpStackToRpn()
{
    m_rpn.push_back(m_opStack.top());
    m_opStack.pop();
    --m_rpnTokenIterator;
}

void Parser::removeFromOpStack()
{
    m_opStack.pop();
}

void Parser::goodPreRpn()
{
    if (!m_opStack.empty() && 
        (m_opStack.top().type == AssignOperator ||
        m_opStack.top().type == EqualOperator ||
        m_opStack.top().type == NotEqualOperator ||
        m_opStack.top().type == GreaterOperator ||
        m_opStack.top().type == LessOperator ||
        m_opStack.top().type == GreaterOrEqualOperator ||
        m_opStack.top().type == LessOrEqualOperator ||
        m_opStack.top().type == KeywordListAdd ||
        m_opStack.top().type == KeywordListRemove ||
        m_opStack.top().type == KeywordListGet ||
        m_opStack.top().type == KeywordPrint))
    {
        m_rpn.push_back(m_opStack.top());
        m_opStack.pop();
    }
}

void Parser::badPreRpn() const
{
    throw std::runtime_error("Pre rpn is incorrect");
}

void Parser::rpnComputing()
{    
    std::stack<Token> valueStack;
    for (auto it = m_rpn.begin(); it != m_rpn.end(); ++it) {
        if (it->type == Type::Id ||
            it->type == Digit ||
            it->type == FloatDigit ||
            it->type == KeywordBack ||
            it->type == KeywordFront) 
        {
            valueStack.push(*it);
            continue;
        }
        switch (it->type) {
        case AddOperator:
        {
            double right = getValueFromToken(valueStack.top());
            valueStack.pop();
            double left = getValueFromToken(valueStack.top());
            valueStack.pop();

            valueStack.emplace(FloatDigit, std::to_string(left + right));
        }
            break;
        case SubOperator:
        {
            double right = getValueFromToken(valueStack.top());
            valueStack.pop();
            double left = getValueFromToken(valueStack.top());
            valueStack.pop();

            valueStack.emplace(FloatDigit, std::to_string(left - right));
        }
            break;
        case MultOperator:
        {
            double right = getValueFromToken(valueStack.top());
            valueStack.pop();
            double left = getValueFromToken(valueStack.top());
            valueStack.pop();

            valueStack.emplace(FloatDigit, std::to_string(left * right));
        }
            break;
        case DivOperator:
        {
            double right = getValueFromToken(valueStack.top());
            valueStack.pop();
            double left = getValueFromToken(valueStack.top());
            valueStack.pop();

            valueStack.emplace(FloatDigit, std::to_string(left / right));
        }
            break;
        case AssignOperator:
        {
            double right = getValueFromToken(valueStack.top());
            valueStack.pop();
            std::string leftId = valueStack.top().value;
            valueStack.pop();

            m_variables[leftId] = right;
        }
            break;
        case EqualOperator: 
        {
            double right = getValueFromToken(valueStack.top());
            valueStack.pop();
            double left = getValueFromToken(valueStack.top());
            valueStack.pop();

            valueStack.emplace(Digit, std::to_string(left == right));
        }
            break;
        case NotEqualOperator:
        {
            double right = getValueFromToken(valueStack.top());
            valueStack.pop();
            double left = getValueFromToken(valueStack.top());
            valueStack.pop();

            valueStack.emplace(Digit, std::to_string(left != right));
        }
            break;
        case GreaterOperator:
        {
            double right = getValueFromToken(valueStack.top());
            valueStack.pop();
            double left = getValueFromToken(valueStack.top());
            valueStack.pop();

            valueStack.emplace(Digit, std::to_string(left > right));
        }
            break;
        case LessOperator:
        {
            double right = getValueFromToken(valueStack.top());
            valueStack.pop();
            double left = getValueFromToken(valueStack.top());
            valueStack.pop();

            valueStack.emplace(Digit, std::to_string(left < right));
        }
            break;
        case GreaterOrEqualOperator:
        {
            double right = getValueFromToken(valueStack.top());
            valueStack.pop();
            double left = getValueFromToken(valueStack.top());
            valueStack.pop();

            valueStack.emplace(Digit, std::to_string(left >= right));
        }
            break;
        case LessOrEqualOperator:
        {
            double right = getValueFromToken(valueStack.top());
            valueStack.pop();
            double left = getValueFromToken(valueStack.top());
            valueStack.pop();

            valueStack.emplace(Digit, std::to_string(left <= right));
        }
            break;
        case RequestPosition:
            it = std::next(m_rpn.begin(), m_jumpIds[std::stoi(it->value)]);
            break;
        case KeywordIf:
        {
            std::string right = valueStack.top().value;
            valueStack.pop();

            if (right == "1") {
                ++it;
            }
        }
            break;
        case KeywordListAdd:
        {
            Token position = valueStack.top();
            valueStack.pop();

            double value = getValueFromToken(valueStack.top());
            valueStack.pop();

            std::string listId = valueStack.top().value;
            valueStack.pop();

            if (position.type == KeywordBack) {
                m_lists[listId].add(value, m_lists[listId].size());
            }
            else if (position.type == KeywordFront) {
                m_lists[listId].add(value, 0);
            }
            else {
                m_lists[listId].add(value, getValueFromToken(position));
            }
        }
            break;
        case KeywordListRemove:
        {
            Token position = valueStack.top();
            valueStack.pop();

            std::string listId = valueStack.top().value;
            valueStack.pop();

            if (position.type == KeywordBack) {
                m_lists[listId].remove(m_lists[listId].size() - 1);
            }
            else if (position.type == KeywordFront) {
                m_lists[listId].remove(0);
            }
            else {
                m_lists[listId].remove(getValueFromToken(position));
            }
        }
            break;
        case KeywordListGet:
        {
            Token position = valueStack.top();
            valueStack.pop();

            std::string varId = valueStack.top().value;
            valueStack.pop();

            std::string listId = valueStack.top().value;
            valueStack.pop();

            if (position.type == KeywordBack) {
                m_variables[varId] = m_lists[listId].get(m_lists[listId].size() - 1)->value;
            }
            else if (position.type == KeywordFront) {
                m_variables[varId] = m_lists[listId].get(0)->value;
            }
            else {
                m_variables[varId] = m_lists[listId].get(getValueFromToken(position))->value;
            }
        }
            break;
        case KeywordPrint:
        {
            Token token = valueStack.top();
            valueStack.pop();

            if (token.type == Type::Id) {
                if (m_variables.find(token.value) != m_variables.end()) {
                    std::cout << m_variables[token.value] << std::endl;
                }
                else if (m_lists.find(token.value) != m_lists.end()) {
                    List& l = m_lists[token.value];
                    ListNode* curNode = l.front();

                    for (size_t i = 0; i < l.size(); ++i) {
                        std::cout << curNode->value << " ";
                        curNode = curNode->next;
                    }

                    std::cout << std::endl;
                }
            }
            else {
                std::cout << token.value << std::endl;
            }
        }
            break;
        }
    }
}

double Parser::getValueFromToken(const Token& token)
{
    switch (token.type) {
    case Type::Id:
        return m_variables[token.value];
        break;
    case Digit:
        return std::stoi(token.value);
        break;
    case FloatDigit:
        return std::stod(token.value);
        break;
    default:
        throw std::runtime_error("Oops...");
        break;
    }

    return 0.0;
}

Parser::JumpId Parser::getNextJumpId()
{
    return m_currentJumpId++;
}
}
