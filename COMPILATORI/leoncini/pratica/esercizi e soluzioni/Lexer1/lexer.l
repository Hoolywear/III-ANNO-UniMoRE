%{
#include <iostream>
using namespace std;
%}

/* read only one input file */
%option noyywrap

id      [a-zA-Z][a-zA-Z_0-9]*
integer  0|[1-9][0-9]∗
sep      [ \t\n]

%%
{sep}            {}
"%"              {cout << "- Operatore: " << yytext[0] << endl; }
":"              {cout << "- Separatore condizione/azione: " << yytext[0] << endl; }
";"              {cout << "- Separatore alternative condizionali: " << yytext[0] << endl; }
"="              {cout << "- Test uguaglianza: " << yytext[0] << endl; }
"("              {cout << "- Parentesi aperta: " << yytext[0] << endl; }
")"              {cout << "- Parentesi chiusa: " << yytext[0] << endl; }
","              {cout << "- Separatore argomenti: " << yytext[0] << endl; }
{integer}        { errno = 0;
                   int n = stoi(yytext, NULL);
                   cout << "- Numero: " << n << endl; 
                 }
"function"       {cout << "- Parola chiave: " << yytext << endl; }
"external"       {cout << "- Parola chiave: " << yytext << endl; }
"if"             {cout << "- Parola chiave: " << yytext << endl; }
"end"            {cout << "- Parola chiave: " << yytext << endl; }
"True"           {cout << "- Costante logica: " << yytext << endl; }
{id}             {cout << "- Identificatore: " << yytext << endl; }
.                {cout << "- Token sconosciuto: " << yytext[0] << endl; }

%%

int main(int argc, char** argv) {
    FlexLexer* lexer = new yyFlexLexer;
    lexer->yylex();
    return 0;
}
