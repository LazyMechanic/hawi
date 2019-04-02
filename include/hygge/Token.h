#pragma once

#include <string>

#include <hygge/Grammar.h>

namespace hygge {
class Token {
public:
    /**
     * \brief Default Token constructor
     */
    Token();

    /**
     * \brief Token constructor. Construct it with specific params
     * \param type Token type
     * \param value Token value
     */
    Token(grammar::terminal::Type type, const std::string& value);

    /**
     * \brief Default copy Token constructor
     */
    Token(const Token&) = default;

    /**
     * \brief Default move Token constructor
     */
    Token(Token&&) = default;

    /**
     * \brief Default copy assign Token operator
     */
    Token& operator =(const Token&) = default;

    /**
     * \brief Default move assign Token operator
     */
    Token& operator =(Token&&) = default;

    /**
     * \brief Token destructor
     */
    ~Token() = default;

    /**
     * \brief Token type
     */
    grammar::terminal::Type type;

    /**
     * \brief Token value
     */
    std::string value;
};

bool operator ==(const Token& left, const Token& right);

bool operator !=(const Token& left, const Token& right);
}