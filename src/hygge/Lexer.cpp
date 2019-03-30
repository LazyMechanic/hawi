#include <hygge/Lexer.h>

#include <regex>
#include <algorithm>

#include <hygge/Lexeme.h>

namespace hygge {
Lexer::Lexer()
{
}

void Lexer::process(const std::string& script)
{
    std::string prevBuffer("");
    std::string buffer("");

    for (auto chIt = script.begin(); chIt != script.end(); ++chIt) {
        prevBuffer = buffer;
        buffer += *chIt;

        size_t candidatesCount = getCandidatesCount(buffer);

        // If character is first in script and it is wrong
        if (candidatesCount == 0 && chIt == script.begin()) {
            throw std::runtime_error("Lexer error: unexpected characters: \"" + buffer + "\"");
        }

        // If no have candidates then check previous buffer
        if (candidatesCount == 0 || std::next(chIt) == script.end()) {
            // If current character is end of script we need check current buffer
            if (std::next(chIt) == script.end()) {
                prevBuffer = buffer;
            }

            std::list<Lexeme> candidates = getCandidates(prevBuffer);

            // If we have candidates to previous buffer
            if (!candidates.empty()) {
                // If terminal is not a whitespace
                if (candidates.begin()->type != grammar::TerminalType::Whitespace) {
                    m_tokens.emplace_back(candidates.begin()->type, prevBuffer);
                }

                // If current character is not end of script
                if (std::next(chIt) != script.end()) {
                    --chIt;
                }
            }
            else {
                throw std::runtime_error("Lexer error: unexpected character: \"" + std::string(1, buffer.back()) + "\"");
            }
            prevBuffer.clear();
            buffer.clear();
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

size_t Lexer::getCandidatesCount(const std::string& str) const
{
    if (str.empty()) {
        return 0;
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

    return result.size();
}
}
