#pragma once

#include <list>
#include <string>
#include <cstdint>

#include <hygge/Token.h>
#include <hygge/Grammar.h>

namespace hygge {
class Lexer
{
public:
    /**
     * \brief Default Lexer constructor
     */
    Lexer();

    /**
     * \brief Lexer destructor
     */
    ~Lexer() = default;

    /**
     * \brief Split the script into tokens
     * \param script Script text
     */
    void process(const std::string& script);

    /**
     * \brief Get tokens
     * \return Reference to list of tokens
     */
    std::list<Token>& getTokens();

private:
    /**
     * \brief Find all candidates in lexemes
     * \param str String for checking
     * \return List of lexeme candidates
     */
    std::list<Lexeme> getCandidates(const std::string& str) const;

    /**
     * \brief Find all candidates in lexemes
     * \param str String for checking
     * \return Size of lexeme candidates list
     */
    size_t getCandidatesCount(const std::string& str) const;

    /**
     * \brief Tokens
     */
    std::list<Token> m_tokens;
};
}