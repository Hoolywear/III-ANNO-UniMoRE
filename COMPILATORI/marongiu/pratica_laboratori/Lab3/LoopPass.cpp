//=============================================================================
// FILE:
//    LoopPass.cpp
//
// DESCRIPTION:
//    Visits all functions in a module and prints their names. Strictly speaking, 
//    this is an analysis pass (i.e. //    the functions are not modified). However, 
//    in order to keep things simple there's no 'print' method here (every analysis 
//    pass should implement it).
//
// USAGE:
//    New PM
//      opt -load-pass-plugin=<path-to>libLoopPass.so -passes="test-pass" `\`
//        -disable-output <input-llvm-file>
//
//
// License: MIT
//=============================================================================
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/LoopInfo.h"

using namespace llvm;

//-----------------------------------------------------------------------------
// LoopPass implementation
//-----------------------------------------------------------------------------
// No need to expose the internals of the pass to the outside world - keep
// everything in an anonymous namespace.
namespace {


// New PM implementation
struct LoopPass: PassInfoMixin<LoopPass> {
  // Main entry point, takes IR unit to run the pass on (&F) and the
  // corresponding pass manager (to be queried if need be)
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM) {

    LoopInfo &LI = AM.getResult<LoopAnalysis>(F);

    if (LI.empty()) { //punto 1: se la funzione non contiene loop, esci immediatamente
      outs() << "-----------------\nLa funzione non contiene nessun loop\n-----------------\n";
    } else {

      // punto 2: scorri i BB del CFG e stampa solo i loop header
      for (auto &B: F) {
        if (LI.isLoopHeader(&B)) { // passo il BB corrente al metodo della classe LoopInfoBase per capire se è header o no
          outs() << "-----------------\nI am a loop header:\n";
          outs() << B << "\n-----------------\n";
        }
      }

      // punto 3: scorri sui loop presenti
      for (auto &L: LI) {
        //punto 3.a: verifico se il loop è in forma normale
        if (L->isLoopSimplifyForm()) outs() << "-----------------\nIl loop è in forma normale\n-----------------\n";

        //punto 3.b: risalgo alla funzione tramite header handle e function handle
        BasicBlock *H = L->getHeader();
        Function *F = H->getParent();
        // stampo il CFG a partire da questa function handle
        outs() << "-----------------\nRistampo l'intero CFG:\n-----------------\n";
        for (auto &B: *F) {
          outs() << B << "\n";
        }
        outs() << "-----------------\n";

        /*punto 3.c: stampo i BB del loop (non uso la forma compatta per l'iteratore perché ho bisogno di
        block_iterator invece di iterator) */
        outs() << "-----------------\nStampo i BB del loop:\n-----------------\n";
        for (Loop::block_iterator B = L->block_begin(); B != L->block_end(); ++B) {
          BasicBlock *BB = *B;
          outs() << *BB << "\n";
        }
        outs() << "-----------------\n";
      }
    }

  	return PreservedAnalyses::all();
  }


  // Without isRequired returning true, this pass will be skipped for functions
  // decorated with the optnone LLVM attribute. Note that clang -O0 decorates
  // all functions with optnone.
  static bool isRequired() { return true; }
};
} // namespace

//-----------------------------------------------------------------------------
// New PM Registration
//-----------------------------------------------------------------------------
llvm::PassPluginLibraryInfo getLoopPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "LoopPass", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "loop-pass") {
                    FPM.addPass(LoopPass());
                    return true;
                  }
                  return false;
                });
          }};
}

// This is the core interface for pass plugins. It guarantees that 'opt' will
// be able to recognize LoopPass when added to the pass pipeline on the
// command line, i.e. via '-passes=test-pass'
extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return getLoopPassPluginInfo();
}
