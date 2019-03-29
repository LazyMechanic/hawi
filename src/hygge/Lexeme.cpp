#include <hygge/Lexeme.h>

namespace hygge {
Lexeme::Lexeme() :
    type(grammar::TerminalType::Invalid),
    regex(""),
    priority(grammar::Priority::Low)
{
}

Lexeme::Lexeme(grammar::TerminalType type, const std::regex& regex, grammar::Priority priority) :
    type(type),
    regex(regex),
    priority(priority)
{
}
}
