#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

#include <hygge/Lexer.h>

using namespace hygge;
using namespace grammar;

void checkTokens(std::list<Token>& correctTokens, std::list<Token>& resultTokens)
{
    REQUIRE(correctTokens.size() == resultTokens.size());

    for (std::list<Token>::iterator correctIt = correctTokens.begin(), resultIt = resultTokens.begin();
        correctIt != correctTokens.end();
        ++correctIt, ++resultIt)
    {
        REQUIRE(correctIt->type == resultIt->type);
        REQUIRE(correctIt->value == resultIt->value);
    }
}

TEST_CASE("Variables")
{
    Lexer lexer;
    SECTION("Define single variable")
    {
        lexer.process("let variable;");
        std::list<Token> correctTokens = {
            {TerminalType::KeywordLet, "let"},
            {TerminalType::Id, "variable"},
            {TerminalType::Semicolon, ";"}
        };

        checkTokens(correctTokens, lexer.getTokens());
    }

    SECTION("Define several variable")
    {
        lexer.process("let variable_1; let variable_2; \n let variable_3;");
        std::list<Token> correctTokens = {
            {TerminalType::KeywordLet, "let"},
            {TerminalType::Id, "variable_1"},
            {TerminalType::Semicolon, ";"},
            {TerminalType::KeywordLet, "let"},
            {TerminalType::Id, "variable_2"},
            {TerminalType::Semicolon, ";"},
            {TerminalType::KeywordLet, "let"},
            {TerminalType::Id, "variable_3"},
            {TerminalType::Semicolon, ";"}
        };

        checkTokens(correctTokens, lexer.getTokens());
    }
}

TEST_CASE("Numbers")
{
    Lexer lexer;
    SECTION("Single digit number")
    {
        lexer.process("6242");
        std::list<Token> correctTokens = {
            {TerminalType::Digit, "6242"},
        };

        checkTokens(correctTokens, lexer.getTokens());
    }

    SECTION("Several digit numbers")
    {
        lexer.process("6242 8250 1 679");
        std::list<Token> correctTokens = {
            {TerminalType::Digit, "6242"},
            {TerminalType::Digit, "8250"},
            {TerminalType::Digit, "1"},
            {TerminalType::Digit, "679"}
        };

        checkTokens(correctTokens, lexer.getTokens());
    }

    SECTION("Single float number")
    {
        lexer.process("0.425");
        std::list<Token> correctTokens = {
            {TerminalType::Float, "0.425"},
        };

        checkTokens(correctTokens, lexer.getTokens());
    }

    SECTION("Several float numbers")
    {
        lexer.process("0.1562 1.516 0.00124 8329.58924");
        std::list<Token> correctTokens = {
            {TerminalType::Float, "0.1562"},
            {TerminalType::Float, "1.516"},
            {TerminalType::Float, "0.00124"},
            {TerminalType::Float, "8329.58924"}
        };

        checkTokens(correctTokens, lexer.getTokens());
    }
}

//#include <iostream>
//#include <hygge/Lexer.h>
//using namespace hygge;
//using namespace grammar;
//
//int main()
//{
//    try {
//        Lexer lexer;
//        lexer.process("0.1562 1.516 0.00124 8329.58924");
//    }
//    catch (const std::exception& e) {
//        std::cout << e.what();
//        getchar();
//        getchar();
//    }
//}