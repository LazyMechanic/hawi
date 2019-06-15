#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

#include <list>

#include <hygge/Grammar.h>
#include <hygge/Parser.h>

using namespace hygge;
using namespace grammar;

void checkPreRpn(Parser& parser,const TokenList& correctPreRpn)
{
    auto preRpn = parser.getPreRpn();

    REQUIRE(preRpn.size() == correctPreRpn.size());
    REQUIRE(std::equal(preRpn.begin(), preRpn.end(), correctPreRpn.begin()) == true);
}

void checkRpn(Parser& parser, const TokenList& correctPreRpn)
{
    auto rpn = parser.getRpn();

    REQUIRE(rpn.size() == correctPreRpn.size());
    REQUIRE(std::equal(rpn.begin(), rpn.end(), correctPreRpn.begin()) == true);
}

void checkVariables(Parser& parser, const Parser::VariableSpace& correctVariables)
{
    auto variables = parser.getVariables();

    REQUIRE(variables.size() == correctVariables.size());
    REQUIRE(std::equal(variables.begin(), variables.end(), correctVariables.begin()) == true);
}


void checkLists(Parser& parser, const Parser::ListSpace& correctLists)
{
}

TEST_CASE("var_def")
{
    Parser parser;

    SECTION("1 variable") {
        std::list<Token> tokens = {
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "abcdef"},
            {terminal::Type::Semicolon, ";"}
        };

        Parser::VariableSpace correctVariables = {
            { "abcdef", 0.0 }
        };

        parser.process(tokens);
        checkVariables(parser, correctVariables);
    }

    SECTION("2 variables") {
        std::list<Token> tokens = {
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a1"},
            {terminal::Type::Semicolon, ";"},
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a2"},
            {terminal::Type::Semicolon, ";"}
        };

        Parser::VariableSpace correctVariables = {
            { "a1", 0.0 },
            { "a2", 0.0 }
        };

        parser.process(tokens);
        checkVariables(parser, correctVariables);
    }

    SECTION("Several variables") {
        std::list<Token> tokens = {
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a1"},
            {terminal::Type::Semicolon, ";"},
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a2"},
            {terminal::Type::Semicolon, ";"},
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a3"},
            {terminal::Type::Semicolon, ";"},
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a4"},
            {terminal::Type::Semicolon, ";"},
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a5"},
            {terminal::Type::Semicolon, ";"},
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a6"},
            {terminal::Type::Semicolon, ";"}
        };

        Parser::VariableSpace correctVariables = {
            { "a1", 0.0 },
            { "a2", 0.0 },
            { "a3", 0.0 },
            { "a4", 0.0 },
            { "a5", 0.0 },
            { "a6", 0.0 }
        };

        parser.process(tokens);
        checkVariables(parser, correctVariables);
    }
}

TEST_CASE("assign")
{
    Parser parser;

    SECTION("Assign to simple value") {
        SECTION("1 variable") {
            std::list<Token> tokens = {
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "abcdef"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "abcdef"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Semicolon, ";"}
            };

            TokenList correctPreRpn = {
                {terminal::Type::Id, "abcdef"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Mark, ""}
            };

            Parser::VariableSpace correctVariables = {
                { "abcdef", 5.0 },
            };

            parser.process(tokens);
            checkPreRpn(parser, correctPreRpn);
            checkVariables(parser, correctVariables);
        }

        SECTION("2 variables") {
            std::list<Token> tokens = {
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "a1"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "a2"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "a1"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "a2"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Semicolon, ";"}
            };

            TokenList correctPreRpn = {
                {terminal::Type::Id, "a1"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Mark, ""},
                {terminal::Type::Id, "a2"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Mark, ""}
            };

            Parser::VariableSpace correctVariables = {
                { "a1", 5.0 },
                { "a2", 5.0 },
            };

            parser.process(tokens);
            checkPreRpn(parser, correctPreRpn);
            checkVariables(parser, correctVariables);
        }

        SECTION("Several variables") {
            std::list<Token> tokens = {
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "a1"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "a2"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "a3"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "a4"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "a5"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "a6"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "a1"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "a2"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "a3"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "a4"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "a5"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "a6"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Semicolon, ";"}
            };

            TokenList correctPreRpn = {
                {terminal::Type::Id, "a1"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Mark, ""},
                {terminal::Type::Id, "a2"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Mark, ""},
                {terminal::Type::Id, "a3"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Mark, ""},
                {terminal::Type::Id, "a4"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Mark, ""},
                {terminal::Type::Id, "a5"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Mark, ""},
                {terminal::Type::Id, "a6"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Digit, "5"},
                {terminal::Type::Mark, ""}
            };

            Parser::VariableSpace correctVariables = {
                { "a1", 5.0 },
                { "a2", 5.0 },
                { "a3", 5.0 },
                { "a4", 5.0 },
                { "a5", 5.0 },
                { "a6", 5.0 },
            };

            parser.process(tokens);
            checkPreRpn(parser, correctPreRpn);
            checkVariables(parser, correctVariables);
        }
    }


    SECTION("Assign to complex value") {
        SECTION("1 variable") {
            std::list<Token> tokens = {
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "abcdef"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "abcdef"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::OpenBracket, "("},
                {terminal::Type::Digit, "2"},
                {terminal::Type::AddOperator, "+"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::CloseBracket, ")"},
                {terminal::Type::MultOperator, "*"},
                {terminal::Type::Digit, "3"},
                {terminal::Type::Semicolon, ";"}
            };

            TokenList correctPreRpn = {
                {terminal::Type::Id, "abcdef"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::OpenBracket, "("},
                {terminal::Type::Digit, "2"},
                {terminal::Type::AddOperator, "+"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::CloseBracket, ")"},
                {terminal::Type::MultOperator, "*"},
                {terminal::Type::Digit, "3"},
                {terminal::Type::Mark, ""}
            };

            TokenList correctRpn = {
                {terminal::Type::Id, "abcdef"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::AddOperator, "+"},
                {terminal::Type::Digit, "3"},
                {terminal::Type::MultOperator, "*"},
                {terminal::Type::AssignOperator, "="},
            };

            Parser::VariableSpace correctVariables = {
                { "abcdef", 12.0 },
            };

            parser.process(tokens);
            checkPreRpn(parser, correctPreRpn);
            checkRpn(parser, correctRpn);
            checkVariables(parser, correctVariables);
        }

        SECTION("2 variables") {
            std::list<Token> tokens = {
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "a1"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::KeywordLet, "let"},
                {terminal::Type::Id, "a2"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "a1"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::OpenBracket, "("},
                {terminal::Type::Digit, "2"},
                {terminal::Type::AddOperator, "+"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::CloseBracket, ")"},
                {terminal::Type::MultOperator, "*"},
                {terminal::Type::Digit, "3"},
                {terminal::Type::Semicolon, ";"},
                {terminal::Type::Id, "a2"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::OpenBracket, "("},
                {terminal::Type::Digit, "2"},
                {terminal::Type::AddOperator, "+"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::CloseBracket, ")"},
                {terminal::Type::MultOperator, "*"},
                {terminal::Type::Digit, "3"},
                {terminal::Type::Semicolon, ";"}
            };

            TokenList correctPreRpn = {
                {terminal::Type::Id, "a1"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::OpenBracket, "("},
                {terminal::Type::Digit, "2"},
                {terminal::Type::AddOperator, "+"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::CloseBracket, ")"},
                {terminal::Type::MultOperator, "*"},
                {terminal::Type::Digit, "3"},
                {terminal::Type::Mark, ""},
                {terminal::Type::Id, "a2"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::OpenBracket, "("},
                {terminal::Type::Digit, "2"},
                {terminal::Type::AddOperator, "+"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::CloseBracket, ")"},
                {terminal::Type::MultOperator, "*"},
                {terminal::Type::Digit, "3"},
                {terminal::Type::Mark, ""}
            };

            TokenList correctRpn = {
                {terminal::Type::Id, "a1"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::AddOperator, "+"},
                {terminal::Type::Digit, "3"},
                {terminal::Type::MultOperator, "*"},
                {terminal::Type::AssignOperator, "="},
                {terminal::Type::Id, "a2"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::Digit, "2"},
                {terminal::Type::AddOperator, "+"},
                {terminal::Type::Digit, "3"},
                {terminal::Type::MultOperator, "*"},
                {terminal::Type::AssignOperator, "="},
            };

            Parser::VariableSpace correctVariables = {
                { "a1", 12.0 },
                { "a2", 12.0 },
            };

            parser.process(tokens);
            checkPreRpn(parser, correctPreRpn);
            checkRpn(parser, correctRpn);
            checkVariables(parser, correctVariables);
        }
    }
}

TEST_CASE("branch")
{
    Parser parser;

    SECTION("Direct sequence") {
        std::list<Token> tokens = {
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a1"},
            {terminal::Type::Semicolon, ";"},

            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a2"},
            {terminal::Type::Semicolon, ";"},

            {terminal::Type::Id, "a1"},
            {terminal::Type::AssignOperator, "="},
            {terminal::Type::Digit, "5"},
            {terminal::Type::Semicolon, ";"},

            {terminal::Type::KeywordIf, "if"},
            {terminal::Type::OpenBracket, "("},
            {terminal::Type::Id, "a1"},
            {terminal::Type::EqualOperator, "=="},
            {terminal::Type::Digit, "5"},
            {terminal::Type::CloseBracket, ")"},
            {terminal::Type::OpenBrace, "{"},
            {terminal::Type::Id, "a2"},
            {terminal::Type::AssignOperator, "="},
            {terminal::Type::FloatDigit, "2.56"},
            {terminal::Type::Semicolon, ";"},
            {terminal::Type::CloseBrace, "}"},

            {terminal::Type::KeywordIf, "if"},
            {terminal::Type::OpenBracket, "("},
            {terminal::Type::Id, "a1"},
            {terminal::Type::GreaterOperator, ">"},
            {terminal::Type::Digit, "5"},
            {terminal::Type::CloseBracket, ")"},
            {terminal::Type::OpenBrace, "{"},
            {terminal::Type::Id, "a2"},
            {terminal::Type::AssignOperator, "="},
            {terminal::Type::FloatDigit, "222.5"},
            {terminal::Type::Semicolon, ";"},
            {terminal::Type::CloseBrace, "}"},

        };

        Parser::VariableSpace correctVariables = {
            { "a1", 5.0 },
            { "a2", 2.56 },
        };

        parser.process(tokens);
        checkVariables(parser, correctVariables);
    }


    SECTION("Reverse sequence") {
        std::list<Token> tokens = {
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a1"},
            {terminal::Type::Semicolon, ";"},

            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a2"},
            {terminal::Type::Semicolon, ";"},

            {terminal::Type::Id, "a1"},
            {terminal::Type::AssignOperator, "="},
            {terminal::Type::Digit, "5"},
            {terminal::Type::Semicolon, ";"},

            {terminal::Type::KeywordIf, "if"},
            {terminal::Type::OpenBracket, "("},
            {terminal::Type::Id, "a1"},
            {terminal::Type::GreaterOperator, ">"},
            {terminal::Type::Digit, "5"},
            {terminal::Type::CloseBracket, ")"},
            {terminal::Type::OpenBrace, "{"},
            {terminal::Type::Id, "a2"},
            {terminal::Type::AssignOperator, "="},
            {terminal::Type::FloatDigit, "2.56"},
            {terminal::Type::Semicolon, ";"},
            {terminal::Type::CloseBrace, "}"},

            {terminal::Type::KeywordIf, "if"},
            {terminal::Type::OpenBracket, "("},
            {terminal::Type::Id, "a1"},
            {terminal::Type::EqualOperator, "=="},
            {terminal::Type::Digit, "5"},
            {terminal::Type::CloseBracket, ")"},
            {terminal::Type::OpenBrace, "{"},
            {terminal::Type::Id, "a2"},
            {terminal::Type::AssignOperator, "="},
            {terminal::Type::FloatDigit, "222.5"},
            {terminal::Type::Semicolon, ";"},
            {terminal::Type::CloseBrace, "}"},

        };

        Parser::VariableSpace correctVariables = {
            { "a1", 5.0 },
            { "a2", 222.5 },
        };

        parser.process(tokens);
        checkVariables(parser, correctVariables);
    }
}

TEST_CASE("loop")
{
    Parser parser;

    SECTION("while")
    {
        std::list<Token> tokens = {
            {terminal::Type::KeywordLet, "let"},
            {terminal::Type::Id, "a1"},
            {terminal::Type::Semicolon, ";"},

            {terminal::Type::Id, "a1"},
            {terminal::Type::AssignOperator, "="},
            {terminal::Type::Digit, "5"},
            {terminal::Type::Semicolon, ";"},

            {terminal::Type::KeywordWhile, "while"},
            {terminal::Type::OpenBracket, "("},
            {terminal::Type::Id, "a1"},
            {terminal::Type::GreaterOperator, ">"},
            {terminal::Type::Digit, "1"},
            {terminal::Type::CloseBracket, ")"},
            {terminal::Type::OpenBrace, "{"},
            {terminal::Type::Id, "a1"},
            {terminal::Type::AssignOperator, "="},
            {terminal::Type::Id, "a1"},
            {terminal::Type::SubOperator, "-"},
            {terminal::Type::Digit, "1"},
            {terminal::Type::Semicolon, ";"},
            {terminal::Type::CloseBrace, "}"}
        };

        Parser::VariableSpace correctVariables = {
            { "a1", 1.0 }
        };

        parser.process(tokens);
        checkVariables(parser, correctVariables);
    }
}

TEST_CASE("list")
{
    Parser parser;

    std::list<Token> tokens = {
        {terminal::Type::KeywordLet, "let"},
        {terminal::Type::Id, "a1"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::Id, "a1"},
        {terminal::Type::AssignOperator, "="},
        {terminal::Type::Digit, "5"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::KeywordList, "list"},
        {terminal::Type::Id, "list1"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::KeywordListAdd, "listadd"},
        {terminal::Type::Id, "list1"},
        {terminal::Type::Id, "a1"},
        {terminal::Type::KeywordBack, "back"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::KeywordListAdd, "listadd"},
        {terminal::Type::Id, "list1"},
        {terminal::Type::Digit, "69"},
        {terminal::Type::KeywordBack, "front"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::KeywordListGet, "listget"},
        {terminal::Type::Id, "list1"},
        {terminal::Type::Id, "a1"},
        {terminal::Type::KeywordBack, "back"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::KeywordListRemove, "listremove"},
        {terminal::Type::Id, "list1"},
        {terminal::Type::Digit, "0"},
        {terminal::Type::Semicolon, ";"},
    };

    parser.process(tokens);
}

TEST_CASE("print")
{
    Parser parser;

    std::list<Token> tokens = {
        {terminal::Type::KeywordLet, "let"},
        {terminal::Type::Id, "a1"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::Id, "a1"},
        {terminal::Type::AssignOperator, "="},
        {terminal::Type::Digit, "5"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::KeywordList, "list"},
        {terminal::Type::Id, "list1"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::KeywordListAdd, "listadd"},
        {terminal::Type::Id, "list1"},
        {terminal::Type::Id, "a1"},
        {terminal::Type::KeywordBack, "back"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::KeywordListAdd, "listadd"},
        {terminal::Type::Id, "list1"},
        {terminal::Type::Digit, "69"},
        {terminal::Type::KeywordBack, "front"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::KeywordPrint, "print"},
        {terminal::Type::Id, "list1"},
        {terminal::Type::Semicolon, ";"},

        {terminal::Type::KeywordPrint, "print"},
        {terminal::Type::Id, "a1"},
        {terminal::Type::Semicolon, ";"},
    };

    parser.process(tokens);
}