# Hygge
Simple Script Language

```
hygge = expr*

expr = statement | 
    while_loop |
    branch

statement = var_def | assign | list_op | print SEMICOLON

var_def = KW_LET | KW_LIST | KW_SET ID
assign = ID ASSIGN_OP computing
computing = value (op value)*

list_op = list_add_op |
    list_remove_op |
    list_get_op |
    list_has_op

# 1. List id
# 2. Value
# 3. Position
list_add_op = KW_LISTADD ID value list_pos
# 1. List id
# 2. Position
list_remove_op = KW_LISTREMOVE ID list_pos
# 1. List id
# 2. Var for save
# 3. Position
list_get_op = KW_LISTGET ID ID list_pos

list_pos = KW_BACK | KW_FRONT | DIGIT | ID

value = ID |
    DIGIT |
    FLOAT_DIGIT |
    (O_BRACKET computing C_BRACKET)

op = ADD_OP |
    SUB_OP |
    MULT_OP |
    DIV_OP

while_loop = KW_WHILE O_BRACKET check_statement C_BRACKET 
    O_BRACE expr* C_BRACE

check_statement = computing check_op computing

check_op = EQUAL_OP |
    NOT_EQUAL_OP |
    GREATER_OP |
    LESS_OP |
    GREATER_OR_EQUAL_OP |
    LESS_OR_EQUAL_OP

branch = if_branch

if_branch = KW_IF O_BRACKET check_statement C_BRACKET O_BRACE expr* C_BRACE

print = KW_PRINT printable

printable = ID | DIGIT | FLOAT_DIGIT

# ==========================================

# KW_* - is Key Word

KW_LET = "let"
KW_IF = "if"
KW_WHILE = "while"

KW_LIST = "list"
KW_SET = "set"
KW_LISTADD = "listadd"
KW_LISTREMOVE = "listremove"
KW_LISTGET = "listget"
KW_SETADD = "setadd"
KW_SETREMOVE = "setremove"
KW_SETHAS = "sethas"
KW_BACK = "back"
KW_FRONT = "front"
KW_SETREHASH = "setrehash"
KW_PRINT = "print"

KW_SINGLE_COMMENT = "^//[^\x03]*$"
KW_MULTI_LINE_COMMENT = "^/\*(?:[^\*]/|\*[^/]|[^\*/])*[^\x03]?[^\x03]?"

ID = "[_a-zA-Z]+[_a-zA-Z0-9]*"

SEMICOLON = ";"
COMMA = ","
DOT = "."

QUOTES = "\""

DIGIT = "0|([1-9][0-9]*)"
FLOAT_DIGIT = "[0-9]+\.[0-9]+"

O_BRACE = "{"
C_BRACE = "}"
O_BRACKET = "("
C_BRACKET = ")"

ASSIGN_OP = "="
ADD_OP = "\+"
SUB_OP = "\-"
MULT_OP = "\*"
DIV_OP = "\/"

EQUAL_OP = "=="
NOT_EQUAL_OP = "!="
GREATER_OP = ">"
LESS_OP = "<"
GREATER_OR_EQUAL_OP = ">="
LESS_OR_EQUAL_OP = "<="
```
