#include "astdriver.hpp"
#include "astparser.hpp"

driver::driver(): trace_parsing(false), trace_scanning(false) {};

int driver::parse (const std::string &f)
{
  file = f;
  location.initialize(&file);
  scan_begin();
  yy::parser parser(*this);
  parser.set_debug_level(trace_parsing);
  int res = parser.parse();
  scan_end();
  return res;
}

NumberExprAST::NumberExprAST(int Val): Val(Val) {};
void NumberExprAST::visit() {
  //std::cout << std::get<int>(getLexVal()) << " ";
  std::cout << Val << " ";
};
lexval NumberExprAST::getLexVal() const {
  lexval lval = Val;
  return lval;
};

IdeExprAST::IdeExprAST(std::string &Name): Name(Name) {};
lexval IdeExprAST::getLexVal() const {
  lexval lval = Name;
  return lval;
};
void IdeExprAST::visit() {
  //std::cout << std::get<std::string>(getLexVal()) << " ";
  std::cout << Name << " ";
};

BinaryExprAST::BinaryExprAST(char Op, ExprAST* LHS, ExprAST* RHS): Op(Op), LHS(LHS), RHS(RHS) {};
ExprAST* BinaryExprAST::left() {
  return LHS;
};
ExprAST* BinaryExprAST::right() {
  return RHS;
};
void BinaryExprAST::visit() {
  std::cout << "(" << Op << " ";
  LHS->visit();
  if (RHS!=nullptr) RHS->visit();
  std::cout << ")";
};

UnaryExprAST::UnaryExprAST(char Op, ExprAST* RHS): Op(Op), RHS(RHS) {};
ExprAST* UnaryExprAST::right() {
  return RHS;
};
void UnaryExprAST::visit() {
  std::cout << "(" << Op << " ";
  RHS->visit();
  std::cout << ")";
};

CallExprAST::CallExprAST(std::string Callee, std::vector<ExprAST*> Args): Callee(Callee), Args(std::move(Args)) {};
lexval CallExprAST::getLexVal() const {
  lexval lval = Callee;
  return lval;
};
void CallExprAST::visit() {
  std::cout << std::get<std::string>(getLexVal()) << "( ";
  for (ExprAST* arg : Args) {
    arg->visit();
  };
  std::cout << ')';
};

PrototypeAST::PrototypeAST(std::string Name, bool External, std::vector<std::string> Args):
                           Name(Name), External(External), Args(std::move(Args)) {};
PrototypeAST::PrototypeAST(std::string Name, std::vector<std::string> Args):
                           Name(Name), Args(std::move(Args)) {External=false;};
lexval PrototypeAST::getLexVal() const {
  lexval lval = Name;
  return lval;
};
const std::vector<std::string>& PrototypeAST::getArgs() const {
  return Args;
};
void PrototypeAST::visit() {
  std::cout << "extern " << Name << "( ";
  for (auto it=Args.begin(); it!=Args.end(); ++it) {
    std::cout << *it << ' ';
  };
  std::cout << ')';
};
int PrototypeAST::argsize() {
  return Args.size();
};

FunctionAST::FunctionAST(PrototypeAST* Proto, ExprAST* Body): Proto(Proto), Body(Body) {
  if (Body == nullptr) external=true;
  else external=false;
};
void FunctionAST::visit() {
  std::cout << std::get<std::string>(Proto->getLexVal()) << "( ";
  for (auto it=Proto->getArgs().begin(); it!= Proto->getArgs().end(); ++it) {
    std::cout << *it << ' ';
  };
  std::cout << ')';
  Body->visit();
};
int FunctionAST::nparams() {
  return Proto->argsize();
};
