# Hygge
Simple Script Language

```
hawi = expr*

expr = statement |
    for_loop |
    while_loop |
    function |
    branch

statement = var_def | assign | computing SEMICOLON

var_def = KW_LET ID
assign = KW_LET? ID ASSIGN_OP computing
computing = value (op value)*

value = ID |
    DIGIT | 
    FLOAT_DIGIT | 
    STRING | 
    BOOL

op = ADD_OP |
    SUB_OP |
    MULT_OP |
    DIV_OP

for_loop = KW_FOR O_BRACKET assign? SEMICOLON check_statement? SEMICOLON computing? C_BRACKET 
    O_BRACE expr* C_BRACE

while_loop = KW_WHILE O_BRACKET check_statement C_BRACKET 
    O_BRACE expr* C_BRACE

check_statement = value check_op computing

check_op = EQUAL_OP |
    NOT_EQUAL_OP |
    GREATER_OP |
    LESS_OP |
    GREATER_OR_EQUAL_OP |
    LESS_OR_EQUAL_OP

function = function_def | function_exec

function_def = KW_FUNCTION ID O_BRACKET var_def* C_BRACKET 
    O_BRACE (expr | (return computing*))* C_BRACE
function_exec = ID O_BRACKET computing* C_BRACKET

# ==========================================

# KW_* - is Key Word

KW_CLASS = "class"
KW_INT = "int"
KW_UINT = "uint"
KW_BOOL = "bool"
KW_STRING = "string"
KW_LET = "let"
KW_CONST = "const"
KW_FUNCTION = "function"
KW_RETURN = "return"
KW_IF = "if"
KW_ELSE = "else"
KW_DO = "do"
KW_WHILE = "while"
KW_FOR = "for"
KW_BREAK = "break"
KW_CONTINUE = "continue"
KW_SINGLE_COMMENT = "//"
KW_MULTI_COMMENT_OPEN = "/\*"
KW_MULTI_COMMENT_CLOSE = "\*/"

ID = "[_a-zA-Z]+[_a-zA-Z0-9]*"

SEMICOLON = ";"
COMMA = ","
DOT = "."

DIGIT = "0|([1-9][0-9]*)"
FLOAT = "[0-9]+\.[0-9]+"
STRING = "[a-zA-Z]*"
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
DIV_OP = "\/"
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
