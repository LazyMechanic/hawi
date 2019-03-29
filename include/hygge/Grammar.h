#pragma once

#include <list>

namespace hygge {
class Lexeme;

namespace grammar {
enum TerminalType
{
    KeywordClass,
    KeywordInt,
    KeywordUInt,
    KeywordChar,
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

    KeywordSingleComment,
    KeywordMultiCommentOpen,
    KeywordMultiCommentClose,

    Semicolon,
    Comma,
    Dot,

    Id,
    Digit,
    Float,
    String,
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

enum Priority
{
    High,
    Normal,
    Low
};

const std::list<Lexeme>& getLexemes();

}
}