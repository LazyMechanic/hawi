#include <hygge/Lexer.h>

#include <regex>
#include <algorithm>
#include <iostream>

#include <hygge/Lexeme.h>

namespace hygge {
constexpr std::size_t etx = 0x03;

Lexer::Lexer()
{
}

void Lexer::process(const std::string& script)
{
    m_tokens.clear();
    std::string buffer("");
    buffer.reserve(4096);

    std::size_t scriptOffset = 0;
    std::string scriptBuffer = getNextScriptBuffer(script, scriptOffset);

    auto chIt = scriptBuffer.cbegin();
    while (true) {
        // If reach end of buffer
        if (*chIt == etx) {
            scriptBuffer = getNextScriptBuffer(script, scriptOffset);
            chIt = scriptBuffer.begin();

            // If reach end of script
            if (*chIt == etx) {
                buffer += *chIt;
                tryAddToken(buffer);
                break;
            }
        }

        buffer += *chIt;

        bool isTokenValid = tryAddToken(buffer);

        if (!isTokenValid) {
            ++chIt;;
        }
    }
}

std::list<Token>& Lexer::getTokens()
{
    return m_tokens;
}

std::list<Lexeme> Lexer::getCandidates(const std::string& str) const
{
    if (str.empty()) {
        return std::list<Lexeme>();
    }

    std::list<Lexeme> result;
    const std::list<Lexeme>& lexemes = grammar::getLexemes();
    
    auto it = lexemes.begin();
    while (it != lexemes.end()) {
        it = std::find_if(it, lexemes.end(), [&str](const Lexeme & l) {
            return std::regex_match(str, l.regex);
            });

        if (it != lexemes.end()) {
            result.push_back(*it);
            ++it;
        }
    }

    result.sort([](const Lexeme & left, const Lexeme & right) {
        return left.priority < right.priority;
    });

    return result;
}

Token Lexer::makeToken(const std::string& buf) const
{
    std::list<Lexeme> candidates = getCandidates(buf);

    // If we have candidates
    if (!candidates.empty()) {
        return Token(candidates.front().type, buf);
    }
    else {
        return Token(grammar::terminal::Type::Invalid, buf);
    }
}

std::string Lexer::getNextScriptBuffer(const std::string& script, std::size_t& currentScriptOffset) const
{
    const std::size_t scriptCopySize = 4094;
    std::string nextScriptBuffer;
    nextScriptBuffer.reserve(4096);
    nextScriptBuffer = etx;

    if (currentScriptOffset < script.size()) {
        nextScriptBuffer = script.substr(currentScriptOffset, scriptCopySize);
        // If reach the end of the script
        if ((currentScriptOffset + scriptCopySize) >= script.size()) {
            nextScriptBuffer += etx;
        }
        currentScriptOffset += scriptCopySize;
    }

    return nextScriptBuffer;
}

bool Lexer::tryAddToken(std::string& buffer)
{
    bool result = false;

    // If current Token from current buffer is invalid
    if (makeToken(buffer).type == grammar::terminal::Type::Invalid) {
        std::string prevBuffer = buffer.substr(0, buffer.size() - 1);

        Token token = makeToken(prevBuffer);
        if (token.type != grammar::terminal::Type::Whitespace) {
            m_tokens.push_back(token);
        }

        result = true;

        // If token is invalid
        if (token.type == grammar::terminal::Invalid) {
            throw std::runtime_error("Lexer error: unexpected token");
        }

        buffer.clear();
    }

    return result;
}
}
