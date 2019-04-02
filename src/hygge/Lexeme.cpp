#include <hygge/Lexeme.h>

namespace hygge {
Lexeme::Lexeme() :
    type(grammar::terminal::Type::Invalid),
    regex(""),
    priority(grammar::Priority::Low)
{
}

Lexeme::Lexeme(grammar::terminal::Type type, const std::regex& regex, grammar::Priority priority) :
    type(type),
    regex(regex),
    priority(priority)
{
}
}
