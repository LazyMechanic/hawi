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

        // If no have candidates then go to one step back
        if (candidatesCount == 0) {
            std::list<Lexeme> candidates = getCandidates(prevBuffer);
            // If we have candidates to previous buffer
            if (!candidates.empty()) {
                // If terminal is not a whitespace
                if (candidates.begin()->type != grammar::TerminalType::Whitespace) {
                    m_tokens.emplace_back(candidates.begin()->type, prevBuffer);
                }
                --chIt;
            }
            else {
                throw std::runtime_error("Lexer error: unexpected characters: \"" + buffer + "\"");
            }
            prevBuffer.clear();
            buffer.clear();
            continue;
        }

        // If we come to end of script. Handle the case if a valid terminal is located at the end of the script
        if (std::next(chIt) == script.end()) {
            std::list<Lexeme> candidates = getCandidates(buffer);
            // If we have candidates to current buffer
            if (!candidates.empty()) {
                m_tokens.emplace_back(candidates.begin()->type, buffer);
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
