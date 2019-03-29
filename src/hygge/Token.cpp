#include <hygge/Token.h>

namespace hygge {
Token::Token() :
    type(grammar::TerminalType::Invalid),
    value("")
{
}

Token::Token(grammar::TerminalType type, const std::string& value) :
    type(type),
    value(value)
{
}

bool operator==(const Token& left, const Token& right)
{
    return left.type == right.type && 
        left.value == right.value;
}

bool operator!=(const Token& left, const Token& right)
{
    return !(left == right);
}
}
