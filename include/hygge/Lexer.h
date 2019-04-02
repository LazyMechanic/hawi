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
     * \param str Literal for checking
     * \return List of lexeme candidates
     */
    std::list<Lexeme> getCandidates(const std::string& str) const;

    /**
     * \brief Make token instance
     * \param buf String from which the token will be created
     * \return Token instance
     */
    Token makeToken(const std::string& buf) const;

    /**
     * \brief 
     * \param script 
     * \param currentScriptOffset 
     * \return 
     */
    std::string getNextScriptBuffer(const std::string& script, std::size_t& currentScriptOffset) const;

    /**
     * \brief Try create and add token in m_tokens
     * \param buffer Buffer from which will create the token
     * \return True if token is valid
     */
    bool tryAddToken(std::string& buffer);

    /**
     * \brief Tokens
     */
    std::list<Token> m_tokens;
};
}