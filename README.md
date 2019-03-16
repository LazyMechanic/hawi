# hawi
Simple Script Language

```
hawi = ...

statement = 

for_loop = ...
while_loop = ...
statement = ...

function_def = ...
function_exec = ...

#==========================================

# KW_* - is Key Word

KW_LET = "let"
KW_FUNCTION = "function"
KW_RETURN = "return"
KW_IF = "if"
KW_ELSE = "else"
KW_FOR = "for"
KW_WHILE = "while"
KW_BREAK = "break"
KW_CONTINUE = "continue"

VAR = "[_a-zA-Z]+[_a-zA-Z0-9]*"

SEMICOLON = ";"
COMMA = ","
DOT = "."

DIGIT = "[0-9]+"
FLOAT_DIGIT = "[0-9]+\.[0-9]+"
STRING = "[a-zA-Z]+"
BOOL = "(true)|(false)"

O_BRACE = "{"
C_BRACE = "}"
O_BRACKET = "("
C_BRACKET = ")"
O_SQUARE_BRACKET = "["
C_SQUARE_BRACKET = "]"

DOUBLE_QUOTES = "\""
SINGLE_QUOTES = "\'"

ASSIGN_OP = "="
ADD_OP = "\+"
SUB_OP = "\-"
MULT_OP = "\*"
DIV_OP = "\\/"
MOD_OP = "%"
UNARY_PLUS_OP = "\+"
UNARY_MINUS_OP = "\-"
INC_OP = "\+\+"
DEC_OP = "\-\-"

EQUAL_OP = "=="
NOT_EQUAL_OP = "!="
GREATER_OP = ">"
LESS_OP = "<"
GREATER_OR_EQUAL_OP = ">="
LESS_OR_EQUAL_OP = "<="

NOT_OP = "!"
AND_OP = "&&"
OR_OP = "\|\|"

BIT_NOT_OP = "~"
BIT_AND_OP = "&"
BIT_OR_OP = "\|"
BIT_XOR_OP = "\^"
BIT_LSHIFT_OP = "<<"
BIT_RSHIFT_OP = ">>"
```
