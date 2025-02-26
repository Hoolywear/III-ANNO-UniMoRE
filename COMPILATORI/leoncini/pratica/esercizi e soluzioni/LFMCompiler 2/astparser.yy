%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2"
%defines

%define api.token.constructor
%define api.location.file none
%define api.value.type variant
%define parse.assert
%define parse.trace
%define parse.error verbose

%code requires {
//#include <exception>
  class driver;
  class RootAST;
  class ExprAST;
  class FunctionAST;
  class PrototypeAST;
  
  // Tell Flex the lexer's prototype ...
# define YY_DECL \
  yy::parser::symbol_type yylex (driver& drv)
}

%param { driver& drv }

%locations

%code {
# include "astdriver.hpp"
YY_DECL;
}

%define api.token.prefix {TOK_}
%token
  EOF  0  "end of file"
  COLON      ":"
  SEMICOLON  ";"
  COMMA      ","
  MINUS      "-"
  PLUS       "+"
  STAR       "*"
  SLASH      "/"
  MOD        "%"
  LPAREN     "("
  RPAREN     ")"
  ALT        "|"
  LE         "<="
  LT         "<"
  EQ         "=="
  NEQ        "<>"
  GE         ">="
  GT         ">"
  BIND       "="
  TRUE       "true"
  FALSE      "false"
  EXTERN     "external"
  DEF        "function"
  IF         "if"
  AND        "and"
  OR         "or"
  NOT        "not"
  LET        "let"
  IN         "in"
  MAIN	     "main"
  END        "end"
;

%token <std::string> IDENTIFIER "id"
%token <int> NUMBER "number"

%type <RootAST*> deflist
%type <ExprAST*> expr
%type <FunctionAST*> funcdef
%type <PrototypeAST*> extdef
%type <PrototypeAST*> prototype
%type <std::vector<std::string>> params
%type <std::vector<ExprAST*>> arglist
%type <std::vector<ExprAST*>> args
%%

%start startsymb;

startsymb:
  deflist               { };

deflist:
  def deflist           { }
| def                   { };

def:
  extdef                { }
| funcdef               { };

extdef:
  "external" prototype  { };

funcdef:
  "function" prototype expr "end"  { };

prototype:
  "id" "(" params ")"   { };

params:
  %empty                { }
| "id" params           { };
 
%nonassoc "<" "==" "<>" "<=" ">" ">=";
%left "+" "-";
%left "*" "/" "%";
%nonassoc UMINUS;
%left "or";
%left "and";
%nonassoc NEGATE;

expr:
  expr "+" expr          { }
| expr "-" expr          { }
| expr "*" expr          { }
| expr "/" expr          { }
| expr "%" expr          { }
| "-" expr %prec UMINUS  { }
| "(" expr ")"           { }
| "id"                   { }
| "id" "(" arglist ")"   { }
| "number"               { }
| condexpr               { }
| letexpr                { };
  
arglist: 
  %empty                 { }
| args                   { };

args:
  expr                   { }
| expr "," args          { };

condexpr:
 "if" pairs "end"        { };
 
pairs:
  pair                   { }
| pair ";" pairs           { };

pair: 
  boolexpr ":" expr      { };
  
boolexpr:
  boolexpr "and" boolexpr { }
| boolexpr "or" boolexpr  { }
| "not" boolexpr  %prec NEGATE { }
| literal                 { }
| relexpr                 { };

literal:
  "true"                  { }
| "false"                 { };

relexpr:
  expr "<"  expr          { }
| expr "==" expr          { }
| expr "<>" expr          { }
| expr "<=" expr          { }
| expr ">"  expr          { }
| expr ">=" expr          { }

letexpr: 
  "let" bindings "in" expr "end" {};

bindings:
  binding                 { }
| binding "," bindings    { };
  
binding:
  "id" "=" expr           { };
 
%%

void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
