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

    KeywordList,
    KeywordSet,

    KeywordListAdd,
    KeywordListRemove,
    KeywordListGet,
    KeywordSetAdd,
    KeywordSetRemove,
    KeywordSetHas,
    KeywordSetRehash,
    KeywordBack,
    KeywordFront,
    KeywordPrint,

    KeywordSingleLineComment,
    KeywordMultiLineComment,

    Semicolon,
    Comma,
    Dot,

    Quotes,

    RequestPosition,
    ResponsePosition,
    Mark,

    Id,
    Digit,
    FloatDigit,
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

namespace nonterminal {
    enum Type
    {
        Expr,

        Statement,
        ForLoop,
        WhileLoop,
        Branch,
        Print,

        VarDef,
        Assign,
        Computing,

        Value,
        Op,

        CheckStatement,
        CheckOp,
        LogicOp,

        IfBranch,
        ElseBranch,

        Printable,       

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