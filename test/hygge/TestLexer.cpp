#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

#include <hygge/Lexer.h>

using namespace hygge;
using namespace grammar;

void checkTokens(Lexer& lexer, const std::string& script, const std::list<Token>& correctTokens)
{
    lexer.process(script);
    std::list<Token> resultTokens = lexer.getTokens();

    REQUIRE(correctTokens.size() == resultTokens.size());

    for (std::list<Token>::const_iterator correctIt = correctTokens.begin(), resultIt = resultTokens.begin();
        correctIt != correctTokens.end();
        ++correctIt, ++resultIt)
    {
        REQUIRE(correctIt->type == resultIt->type);
        REQUIRE(correctIt->value == resultIt->value);
    }
}

TEST_CASE("Keywords")
{
    Lexer lexer;
    SECTION("Class")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordClass, "class"},
        };

        checkTokens(lexer, "class", correctTokens);
    }

    SECTION("UInt")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordUInt, "uint"},
        };

        checkTokens(lexer, "uint", correctTokens);
    }

    SECTION("Bool")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordBool, "bool"},
        };

        checkTokens(lexer, "bool", correctTokens);
    }

    SECTION("Literal")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordString, "string"},
        };

        checkTokens(lexer, "string", correctTokens);
    }

    SECTION("Let")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordLet, "let"},
        };

        checkTokens(lexer, "let", correctTokens);
    }

    SECTION("Const")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordConst, "const"},
        };

        checkTokens(lexer, "const", correctTokens);
    }

    SECTION("Function")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordFunction, "function"},
        };

        checkTokens(lexer, "function", correctTokens);
    }

    SECTION("Return")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordReturn, "return"},
        };

        checkTokens(lexer, "return", correctTokens);
    }

    SECTION("If")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordIf, "if"},
        };

        checkTokens(lexer, "if", correctTokens);
    }

    SECTION("Else")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordElse, "else"},
        };

        checkTokens(lexer, "else", correctTokens);
    }

    SECTION("Do")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordDo, "do"},
        };

        checkTokens(lexer, "do", correctTokens);
    }

    SECTION("While")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordWhile, "while"},
        };

        checkTokens(lexer, "while", correctTokens);
    }

    SECTION("For")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordFor, "for"},
        };

        checkTokens(lexer, "for", correctTokens);
    }

    SECTION("Break")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordBreak, "break"},
        };

        checkTokens(lexer, "break", correctTokens);
    }

    SECTION("Continue")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordContinue, "continue"},
        };

        checkTokens(lexer, "continue", correctTokens);
    }

    SECTION("Single comment")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::KeywordSingleLineComment, "//ghjs sakgk;hhw h    if"},
        };

        checkTokens(lexer, "//ghjs sakgk;hhw h    if", correctTokens);
    }

    SECTION("Multi line comment")
    {
        std::list<Token> correctTokens;
        
        correctTokens = {
            {terminal::Type::KeywordMultiLineComment, "/* gfasghgkljkls \n ghjdsjkow oio\t sa*/"},
        };

        checkTokens(lexer, "/* gfasghgkljkls \n ghjdsjkow oio\t sa*/", correctTokens);
        
        correctTokens = {
            {terminal::Type::KeywordMultiLineComment, "/* \t\t\t\t\t sa*/"},
        };

        checkTokens(lexer, "/* \t\t\t\t\t sa*/             ", correctTokens);
    }

    SECTION("Mix")
    {

        std::list<Token> correctTokens = {
            {terminal::Type::KeywordClass, "class"},
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::KeywordContinue, "continue"},
            {terminal::Type::KeywordContinue, "continue"},
            {terminal::Type::KeywordFor, "for"},
            {terminal::Type::KeywordMultiLineComment, "/* gfasghgkl \n class let jkls \n gh// jdsjkow oio\t sa*/"},
        };

        checkTokens(lexer, "class let continue continue \n\tfor/* gfasghgkl \n class let jkls \n gh// jdsjkow oio\t sa*/", correctTokens);
    }
}

TEST_CASE("Identifiers")
{
    Lexer lexer;
    SECTION("Single variable")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::Id, "variable"},
        };

        checkTokens(lexer, "variable", correctTokens);
    }

    SECTION("Several variable")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::Id, "variable_1"},
            {terminal::Type::Id, "variable_2"},
            {terminal::Type::Id, "variable_3"}
        };

        checkTokens(lexer, "variable_1 \t variable_2 \n variable_3", correctTokens);
    }
}

TEST_CASE("Values")
{
    Lexer lexer;
    SECTION("Single digit number")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::Digit, "6242"},
        };

        checkTokens(lexer, "6242", correctTokens);
    }

    SECTION("Several digit numbers")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::Digit, "6242"},
            {terminal::Type::Digit, "8250"},
            {terminal::Type::Digit, "1"},
            {terminal::Type::Digit, "679"}
        };

        checkTokens(lexer, "6242 \t 8250  \t\n 1 679", correctTokens);
    }

    SECTION("Single float number")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::Float, "0.425"},
        };

        checkTokens(lexer, " \t\n0.425", correctTokens);
    }

    SECTION("Several float numbers")
    {
        std::list<Token> correctTokens = {
            {terminal::Type::Float, "0.1562"},
            {terminal::Type::Float, "1.516"},
            {terminal::Type::Float, "0.00124"},
            {terminal::Type::Float, "8329.58924"}
        };

        checkTokens(lexer, "0.1562  \t\n 1.516     0.00124\n8329.58924", correctTokens);
    }

    SECTION("Single string")
    {
        std::list<Token> correctTokens;

        correctTokens = {
            {terminal::Type::Literal, "\"gjkalas jghlke wo h\""},
        };
        checkTokens(lexer, "\"gjkalas jghlke wo h\"", correctTokens);


        correctTokens = {
            {terminal::Type::Literal, "\"\\\"\""},
        };
        checkTokens(lexer, "\"\\\"\"", correctTokens);
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
//        lexer.process(" 0.1562 1.516 0.00124 8329.58924?");
//    }
//    catch (const std::exception& e) {
//        std::cout << e.what();
//        getchar();
//        getchar();
//    }
//}