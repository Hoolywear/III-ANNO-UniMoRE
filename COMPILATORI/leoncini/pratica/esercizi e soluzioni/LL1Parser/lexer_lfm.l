%{
#include <stdexcept>
#include <map>
#include <cstring>
#include <string>
#include "tokens_lfm.h"
#include "symbtbl_lfm.h"

// Forward declaration
TokenType check_ide(std::string tok);
void illegal(char c);

// Definitions used by the parser
std::map<const int,Token*> symbtbl;
int symbtblptr;

// Local only variables
Token *t;
int count = 0;

%}

id      [a-zA-Z][a-zA-Z0-9]*
num     0|[1-9][0-9]*

%option noyywrap

%%
[ \t\n]   { /* Ignoriamo i separatori */ }
"function"  { return tok_function; }
"external"  { return tok_external; }
"end"       { return tok_end; }
"in"        { return tok_in; }
"if"        { return tok_if; }
"let"       { return tok_let; }
"and"       { return tok_and; }
"or"        { return tok_or; }
"not"       { return tok_not; }
"true"      { return tok_true; }
"false"     { return tok_false; }
{id}        { t = new Token;
              t->toktype=tok_id;
              strcpy(t->id, yytext);
              symbtblptr=++count;
              symbtbl[symbtblptr]=t;
	      return tok_id; }
{num}       { t = new Token;
              t->toktype=tok_int;
              t->num=std::atoi(yytext);
              symbtblptr=++count;
              symbtbl[symbtblptr]=t;
	      return tok_int; }
"<="      { return tok_lte; }
">="      { return tok_gte; }
"<"       { return int('<'); }
">"       { return int('>'); }
"="       { return int('='); }
"*"       { return int('*'); }
"+"       { return int('+'); }
"/"       { return int('/'); }
"-"       { return int('-'); }
"%"       { return int('%'); }
"("       { return int('('); }
")"       { return int(')'); }
","       { return int(','); }
";"       { return int(';'); }
"|"       { return int('|'); }
<<EOF>>   { return tok_eof; }
.         { illegal(yytext[0]); }

%%

void illegal(char c) {
   throw std::invalid_argument( "Trovato un carattere illegale" );
}
