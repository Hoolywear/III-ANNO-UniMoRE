
bool runOnBasicBlock(BasicBlock &B) {
    
  /*
  
  // Preleviamo le prime due istruzioni del BB
  Instruction &Inst1st = *B.begin(), &Inst2nd = *(++B.begin());
  
  // L'indirizzo della prima istruzione deve essere uguale a quello del 
  // primo operando della seconda istruzione (per costruzione dell'esempio)
  assert(&Inst1st == Inst2nd.getOperand(0));
  
  // Stampa la prima istruzione
  outs() << "PRIMA ISTRUZIONE: " << Inst1st << "\n";
  // Stampa la prima istruzione come operando
  outs() << "COME OPERANDO: ";
  Inst1st.printAsOperand(outs(), false);
  outs() << "\n";
  
  // User-->Use-->Value
  outs() << "I MIEI OPERANDI SONO:\n";
  for (auto *Iter = Inst1st.op_begin(); Iter != Inst1st.op_end(); ++Iter) {
    Value *Operand = *Iter;
    
    if (Argument *Arg = dyn_cast<Argument>(Operand)) {
      outs() << "\t" << *Arg << ": SONO L'ARGOMENTO N. " << Arg->getArgNo() 
      <<" DELLA FUNZIONE " << Arg->getParent()->getName()
      << "\n";
      }
      if (ConstantInt *C = dyn_cast<ConstantInt>(Operand)) {
        outs() << "\t" << *C << ": SONO UNA COSTANTE INTERA DI VALORE " << C->getValue()
        << "\n";
        }
        }
        
        outs() << "LA LISTA DEI MIEI USERS:\n";
        for (auto Iter = Inst1st.user_begin(); Iter != Inst1st.user_end(); ++Iter) {
          outs() << "\t" << *(dyn_cast<Instruction>(*Iter)) << "\n";
          }
          
          outs() << "E DEI MIEI USI (CHE E' LA STESSA):\n";
          for (auto Iter = Inst1st.use_begin(); Iter != Inst1st.use_end(); ++Iter) {
            outs() << "\t" << *(dyn_cast<Instruction>(Iter->getUser())) << "\n";
            outs() << "\t" << *(dyn_cast<Instruction>(Iter->get())) << "\n";
            }
            
            
            // Manipolazione delle istruzioni
            Instruction *NewInst = BinaryOperator::Create(
              Instruction::Add, Inst1st.getOperand(0), Inst1st.getOperand(0));
              
              NewInst->insertAfter(&Inst1st);
              // Si possono aggiornare le singole references separatamente?
              // Controlla la documentazione e prova a rispondere.
              Inst1st.replaceAllUsesWith(NewInst);
              
              // outs() << "itera sugli usi di %3" << "\n";
              // for (auto Iter = Inst1st.use_begin(); Iter != Inst1st.use_end(); ++Iter) {
                //   outs() << "before sub" << *(dyn_cast<Instruction>(Iter->getUser())) << "\n";
                //   Iter->set(NewInst);
                //   outs() << "after sub" << *(dyn_cast<Instruction>(Iter->getUser())) << "\n";
    // }

  */

    for (Instruction& I : B) {
      outs() << I << "\n";
      if (I.getOpcode() == Instruction::Mul) {
        outs() << "Found a multiplication\n";


        // for (Use& U : I.operands()) {
        //   Value* Op = U.get();
        //   outs() << "\tOperand: " << *Op;
        //   if (ConstantInt *C = dyn_cast<ConstantInt>(Op)) {
        //     outs() << "\t SONO UNA COSTANTE INTERA DI VALORE " << C->getValue();
        //     if (C->getValue().isPowerOf2()) {
        //       outs() << " E' POTENZA DI 2\n";
        //       Instruction *NewInst = BinaryOperator::Create(
        //         Instruction::Shl, I.getOperand(0), ConstantInt::get(C->getType(), C->getValue().logBase2()));
        //     } else {
        //       outs() << " NON E' POTENZA DI 2\n";
        //     }
        //   }
        //   outs() << "\n";
        // }

        ConstantInt *C1 = dyn_cast<ConstantInt>(I.getOperand(0)), *C2 = dyn_cast<ConstantInt>(I.getOperand(1));
        if (C1 && C1->getValue().isPowerOf2()) {
          outs() << "Operand 1 is a power of 2\n";
          Instruction *NewInst = BinaryOperator::Create(
            Instruction::Shl, I.getOperand(1), ConstantInt::get(C1->getType(), C1->getValue().logBase2()));
          NewInst->insertAfter(&I);
          outs() << "Replacing ";
          I.printAsOperand(outs(), false);
          outs() << " with ";
          NewInst->printAsOperand(outs(), false);
          outs() << "\n";
          I.replaceAllUsesWith(NewInst);
          // I.eraseFromParent();
        } else if (C2 && C2->getValue().isPowerOf2()) {
          outs() << "Operand 2 is a power of 2\n";
          Instruction *NewInst = BinaryOperator::Create(
            Instruction::Shl, I.getOperand(0), ConstantInt::get(C2->getType(), C2->getValue().logBase2()));
          NewInst->insertAfter(&I);
          outs() << "Replacing ";
          I.printAsOperand(outs(), false);
          outs() << " with ";
          NewInst->printAsOperand(outs(), false);
          outs() << "\n";
          I.replaceAllUsesWith(NewInst);
          // I.eraseFromParent();
        }

        // Value* Op1 = I.getOperand(0);
        // Value* Op2 = I.getOperand(1);
        // outs() << "\tOperand 1: " << *Op1 << "\n";
        // outs() << "\tOperand 2: " << *Op2 << "\n";
        // if (ConstantInt *C = dyn_cast<ConstantInt>(Op1)) {
        //   outs() << "\t" << *C << ": SONO UNA COSTANTE INTERA DI VALORE " << C->getValue()
        //   << "\n";
        //   }
        // if (ConstantInt *C = dyn_cast<ConstantInt>(Op2)) {
        //   outs() << "\t" << *C << ": SONO UNA COSTANTE INTERA DI VALORE " << C->getValue()
        //   << "\n";
        //   }
      }
    }

    return true;
  }


bool runOnFunction(Function &F) {
  bool Transformed = false;

  for (auto Iter = F.begin(); Iter != F.end(); ++Iter) {
    if (runOnBasicBlock(*Iter)) {
      Transformed = true;
    }
  }

  return Transformed;
}
