#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

#include <hygge/Interpreter.h>

using namespace hygge;

TEST_CASE("Help me....")
{
    Interpreter interp;

    std::string script;

    SECTION("Test all")
    {
        script = "let a; a = 10; list l; while (a > 0) { a = a - 1; listadd l a back; } if (a > 0) { print 1; } print l;";
        interp.parse(script);
    }
}