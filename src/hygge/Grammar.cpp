#include <hygge/Grammar.h>

#include <regex>

#include <hygge/Lexeme.h>

namespace hygge {
namespace grammar {
const std::list<Lexeme>& getLexemes()
{
    using namespace terminal;
    static std::list<Lexeme> lexemes = {
        { KeywordClass, std::regex("^class$"), High },
        { KeywordInt, std::regex("^int$"), High },
        { KeywordUInt, std::regex("^uint$"), High },
        { KeywordBool, std::regex("^bool$"), High },
        { KeywordString, std::regex("^string$"), High },
        { KeywordLet, std::regex("^let$"), High },
        { KeywordConst, std::regex("^const$"), High },

        { KeywordFunction, std::regex("^function$"), High },
        { KeywordReturn, std::regex("^return$"), High },

        { KeywordIf, std::regex("^if$"), High },
        { KeywordElse, std::regex("^else$"), High },

        { KeywordDo, std::regex("^do$"), High },
        { KeywordWhile, std::regex("^while$"), High },
        { KeywordFor, std::regex("^for$"), High },

        { KeywordBreak, std::regex("^break$"), High },
        { KeywordContinue, std::regex("^continue$"), High },

        { KeywordList, std::regex("^list$"), High },
        { KeywordSet, std::regex("^set$"), High },

        { KeywordListAdd, std::regex("^listadd$"), High },
        { KeywordListRemove, std::regex("^listremove$"), High },
        { KeywordListGet, std::regex("^listget$"), High },
        { KeywordSetAdd, std::regex("^setadd$"), High },
        { KeywordSetRemove, std::regex("^setremove$"), High },
        { KeywordSetHas, std::regex("^sethas$"), High },
        { KeywordSetRehash, std::regex("^setrehash$"), High },
        { KeywordBack, std::regex("^back$"), High },
        { KeywordFront, std::regex("^front$"), High },
        { KeywordPrint, std::regex("^print$"), High },

        { KeywordSingleLineComment, std::regex("^//[^\\x03]*$"), Highest },
        { KeywordMultiLineComment, std::regex("^/\\*(?:[^\\*]/|\\*[^/]|[^\\*/])*[^\\x03]?[^\\x03]?"), Highest },

        { Semicolon, std::regex("^;$"), High },
        { Comma, std::regex("^,$"), High },
        { Dot, std::regex("^\\.$"), High },

        { Quotes, std::regex("^\"$"), High },

        { Id, std::regex("^[_a-zA-Z]+[_a-zA-Z0-9]*$"), Normal },
        { Digit, std::regex("^0|([1-9][0-9]*)"), Normal },
        { FloatDigit, std::regex("^[0-9]+\\.[0-9]*"), Normal },
        { Literal, std::regex("^(\"(?:\\\\.|[^\"])*\"$)|(\"(?:\\\\.|[^\"])*$)"), Normal },
        { Bool, std::regex("^(true)|(false)$"), Normal },

        { Whitespace, std::regex("^\\s+$"), Low },

        { OpenBrace, std::regex("^\\{$"), High },
        { CloseBrace, std::regex("^\\}$"), High },

        { OpenBracket, std::regex("^\\($"), High },
        { CloseBracket, std::regex("^\\)$"), High },

        { OpenSquareBracket, std::regex("^\\[$"), High },
        { CloseSquareBracket, std::regex("^\\]$"), High },

        { AssignOperator, std::regex("^=$"), High },
        { AddOperator, std::regex("^\\+$"), High },
        { SubOperator, std::regex("^-$"), High },
        { MultOperator, std::regex("^\\*$"), High },
        { DivOperator, std::regex("^/$"), High },
        { ModOperator, std::regex("^%$"), High },
        { UnaryPlusOperator, std::regex("^\\+$"), High },
        { UnaryMinusOperator, std::regex("^-$"), High },
        { IncOperator, std::regex("^\\+\\+$"), High },
        { DecOperator, std::regex("^--$"), High },

        { EqualOperator, std::regex("^==$"), High },
        { NotEqualOperator, std::regex("^!=$"), High },
        { GreaterOperator, std::regex("^>$"), High },
        { LessOperator, std::regex("^<$"), High },
        { GreaterOrEqualOperator, std::regex("^>=$"), High },
        { LessOrEqualOperator, std::regex("^<=$"), High },

        { NotOperator, std::regex("^!$"), High },
        { AndOperator, std::regex("^&&$"), High },
        { OrOperator, std::regex("^\\|\\|$"), High },

        { BitNotOperator, std::regex("^~$"), High },
        { BitAndOperator, std::regex("^&$"), High },
        { BitOrOperator, std::regex("^\\|$"), High },
        { BitXorOperator, std::regex("^\\^$"), High },
        { BitLeftShiftOperator, std::regex("^<<$"), High },
        { BitRightShiftOperator, std::regex("^>>$"), High },
    };

    return lexemes;
}
}
}