%{
#include <stdexcept>
#include "token.h"
void illegal(char c);
%}

%option noyywrap

%%
[ \t\n]     { /* Ignoriamo i separatori */ }
"("         { return tok_left; }
")"         { return tok_right; }
<<EOF>>     { return tok_eof; }
.           { illegal(yytext[0]); }

%%

void illegal(char c) {
   throw std::invalid_argument( "Trovato un carattere illegale" );
}
