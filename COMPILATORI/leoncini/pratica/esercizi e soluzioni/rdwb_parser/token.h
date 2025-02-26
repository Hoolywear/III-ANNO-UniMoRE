// Definizione dei Token
// La definizione "spetta" al parser e deve essere
// importata e "rispettata" dal lexer

enum TokenType {
  tok_eof = -1,

  // parenthesis
  tok_left = -2,
  tok_right = -3,
};
