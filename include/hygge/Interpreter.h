#pragma once

#include <hygge/Lexer.h>
#include <hygge/Parser.h>

namespace hygge {
class Interpreter
{
public:

private:
    Lexer m_lexer;
    Parser m_parser;
};
}