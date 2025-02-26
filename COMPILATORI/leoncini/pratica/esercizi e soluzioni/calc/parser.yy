%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2"
%defines

/* %define api.namespace {calc}   -> cambia il nome del namespace (usualmente yy) in calc
   %define api.location.file none -> non genera il file location.hh perché le locations non
                                     sono usate fuori dal parser
   %define api.token.constructor  -> definisce nel file parser.hpp le funzioni utilizzabili
                                     dallo scanner per restituire i token (make_XXX)
   %define api.value.type variant -> il semantic type di token diversi (tipicamenti numeri e identificatori)
                                     viene definito tramite variant (e non più union))
*/
%define api.namespace {calc}
%define api.location.file none
%define api.token.constructor
%define api.value.type variant
%define parse.assert

/* %code requires -> Il codice viene inserito nel file parser.hpp */
%code requires {
  #include <string>
  #include <map>
  #include <cmath>
  
// Tell Flex the lexer's prototype ...
# define YY_DECL \
  calc::parser::symbol_type yylex ()
}

%locations


%define parse.trace
%define parse.error verbose

/* %code -> Il codice viene inserito nel file parser.cpp */
%code {
  extern std::map<std::string,int> variables;
  extern calc::location location;
  extern int result;
  YY_DECL;
}

%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
  ASSIGN  "="
  MINUS   "-"
  PLUS    "+"
  STAR    "*"
  SLASH   "/"
  LPAREN  "("
  RPAREN  ")"
  POWER   "^"
  SQRT    "sqrt"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm  <int> exp

/* Con la direttiva %printer il codice incluso in {} viene invocato tutte
le  volte che il parser deve evidenziare uno dei simboli che  seguono. <*> indica
simboli con qualsiasi semantic value */ 
%printer { yyoutput << $$; } <*>;

%%
%start unit;
unit: assignments exp  { result = $2; };

assignments:
  %empty                 {}
| assignments assignment {};

assignment:
  "identifier" "=" exp { variables[$1] = $3; };

%left "+" "-";
%left "*" "/";
%right "^";

exp:
  exp "+" exp   { $$ = $1 + $3; }
| exp "-" exp   { $$ = $1 - $3; }
| exp "*" exp   { $$ = $1 * $3; }
| exp "/" exp   { $$ = $1 / $3; }
| exp "^" exp   { $$ = pow($1,$3); }
| "(" exp ")"   { $$ = $2; }
| "identifier"  { $$ = variables[$1]; }
| "number"      { $$ = $1; };
| "sqrt" "(" exp ")" { $$ = sqrt($3); }
%%

void
calc::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
