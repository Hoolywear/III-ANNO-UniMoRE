/*******************************************************************
****** Parser a discesa ricorsiva con backtracking per la    *******
****** grammatica che genera sequenze di parentesi binaciate *******
********************************************************************/
#include <iostream>
#include <FlexLexer.h>
#include <string>
#include <vector>
#include "token.h"
using namespace std;

bool S(int& i);

const int nonterm_S = 1;
const int eps = 0;

class Token {
public:
    Token(TokenType t): t(t) {};
    Token(TokenType t, int v): t(t), v(v) {};
    TokenType t;
    int v;
};

vector<Token*> inputseq; // Vettore che contiene la sequenza di token da analizzare
string inputstr = "";

/* Rappresentazione delle produzioni:
   1) La parte destra di una produzione è rappresentata come lista
      di numeri interi
   2) Le produzioni relative ad uno stesso non terminale (qui solo S) sono
      poi inserite in uno stesso "vettore di vettori di interi"
*/
      
std::vector<int> prod1{tok_left, nonterm_S, tok_right, nonterm_S};   // S --> (S)S
std::vector<int> prod2{eps};                                         // S --> eps
// 
std::vector<vector<int>> Sprods{prod1,prod2};
// array di stringhe che rappresentano le produzioni in modo "human readable"
string Sdisplay[2] = {"S --> (S)S","S --> eps"};
/************************************/

bool isterm(int v) {   // Test per simbolo non terminale
    return v<=0;
}

bool iseps(int v) {    // Test per epsilon
    return v==0;
}

// Funzione corrispondente all'unico non terminaale
bool S(int& i, string indent) {
  int saveptr = i;
  int n = Sprods.size();
  for (int j=0; j<n; j++) {  // Proviamo tutte le produzioni prima di dichiarare eventuale fallimento
    bool fail = false;
    cout << indent+"Trying production " << Sdisplay[j] << " at " << inputstr.substr(i,inputstr.length()) << endl;
    for(int v=0; v<Sprods[j].size(); v++) { // Scansione della parte dx della j-esima  pruduzione
      int t = Sprods[j][v];
      if (iseps(t) or not isterm(t) && S(i,indent+" ")) continue;
      if (isterm(t) and inputseq.at(i)->t==t) {
	i++;
	continue;
      };
      i = saveptr; // Insuccesso, ripristiniamo puntatore di input
      fail = true;
      cout << indent+Sdisplay[j] << " failed\n";
      break;
    }
    if (not fail) {   // Una produzione è stata analizzata con successo, procediamo
      //std::cout << indent << Sdisplay[j] << endl;
      return true;
    }
  }
  return false;  // Tutte le produzione hanno fallito, restituiamo false al chiamante
}
         
int main()
/* Per semplicità la stringa di input viene letta interamente e "tokenizzata".
   Solo dopo inizia il parsing. Questo viene fatto perché "questo" parser funziona con
   backtracking e naturalmente la sua implementazione è più agevole se la sequenza
   è in memoria e su file
*/
{
  FlexLexer* lexer = new yyFlexLexer;
  Token* t;
  int tok;
  std::cout << "Starting...\n";;
  while ((tok = lexer->yylex()) && (tok != tok_eof)) { // Inseriamo tutti i token
      t = new Token(static_cast<TokenType>(tok));      // nel buffer di input
      inputseq.push_back(t);
      if (tok==tok_left) inputstr = inputstr+"(";
      else inputstr = inputstr+")";
  }
  inputstr = inputstr+"$";
  inputseq.push_back(new Token(tok_eof));
  // Lettura terminata, inizia il parsing
  int i = 0;  // Puntatore di input (punta al token corrente)
  if (S(i,"") and inputseq.at(i)->t == tok_eof) // Se la funzione per S (assioma) restituisce true e
      std::cout << "Accept\n";               // il puntatore è su eof, il parsing ha avuto successo
  else  std::cout << "Reject\n";             // Altrimenti la stringa non è stata riconosciuta
  return 0;
}

