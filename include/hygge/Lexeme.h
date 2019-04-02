#pragma once

#include <regex>
#include <string>
#include <cstdint>

#include <hygge/Grammar.h>

namespace hygge {
class Lexeme {
public:
    /**
     * \brief Default Lexeme constructor
     */
    Lexeme();

    /**
     * \brief Lexeme constructor. Construct it with specific params
     * \param type Lexeme type
     * \param regex Lexeme regex
     * \param priority Priority
     */
    Lexeme(grammar::terminal::Type type, const std::regex& regex, grammar::Priority priority);

    /**
     * \brief Default copy Lexeme constructor
     */
    Lexeme(const Lexeme&) = default;

    /**
     * \brief Default move Lexeme constructor
     */
    Lexeme(Lexeme&&) = default;

    /**
     * \brief Default copy assign Lexeme operator
     */
    Lexeme& operator =(const Lexeme&) = default;

    /**
     * \brief Default move assign Lexeme operator
     */
    Lexeme& operator =(Lexeme&&) = default;

    /**
     * \brief Lexeme destructor
     */
    ~Lexeme() = default;

    /**
     * \brief Lexeme type
     */
    grammar::terminal::Type type;

    /**
     * \brief Lexeme regex
     */
    std::regex regex;

    /**
     * \brief Lexeme priority. The lower the number, the higher the priority
     */
    grammar::Priority priority;
};
}