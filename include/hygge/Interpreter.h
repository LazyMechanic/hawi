#pragma once

#include <hygge/Lexer.h>
#include <hygge/Parser.h>

namespace hygge {
class Interpreter
{
public:
    void parse(const std::string& script);
private:
    Lexer m_lexer;
    Parser m_parser;
};
}