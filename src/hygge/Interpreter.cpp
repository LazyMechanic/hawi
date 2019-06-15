#include <hygge/Interpreter.h>

namespace hygge {
void Interpreter::parse(const std::string& script)
{
    m_lexer.process(script);
    m_parser.process(m_lexer.getTokens());
}
}
