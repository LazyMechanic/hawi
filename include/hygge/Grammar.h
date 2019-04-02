#pragma once

#include <list>

namespace hygge {
class Lexeme;

namespace grammar {
namespace terminal {
enum Type
{
    KeywordClass,
    KeywordInt,
    KeywordUInt,
    KeywordBool,
    KeywordString,
    KeywordLet,
    KeywordConst,

    KeywordFunction,
    KeywordReturn,

    KeywordIf,
    KeywordElse,

    KeywordDo,
    KeywordWhile,
    KeywordFor,

    KeywordBreak,
    KeywordContinue,

    KeywordSingleLineComment,
    KeywordMultiLineComment,

    Semicolon,
    Comma,
    Dot,

    Id,
    Digit,
    Float,
    Literal,
    Bool,

    Whitespace,

    OpenBrace,
    CloseBrace,

    OpenBracket,
    CloseBracket,

    OpenSquareBracket,
    CloseSquareBracket,

    DoubleQuotes,
    SingleQuotes,

    AssignOperator,
    AddOperator,
    SubOperator,
    MultOperator,
    DivOperator,
    ModOperator,
    UnaryPlusOperator,
    UnaryMinusOperator,
    IncOperator,
    DecOperator,

    EqualOperator,
    NotEqualOperator,
    GreaterOperator,
    LessOperator,
    GreaterOrEqualOperator,
    LessOrEqualOperator,

    NotOperator,
    AndOperator,
    OrOperator,

    BitNotOperator,
    BitAndOperator,
    BitOrOperator,
    BitXorOperator,
    BitLeftShiftOperator,
    BitRightShiftOperator,

    Invalid
};
}

enum Priority
{
    Highest = 0,
    High,
    Normal,
    Low,
    Lowest
};

const std::list<Lexeme>& getLexemes();

}
}