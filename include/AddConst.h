//
// Created by Rajveer Singh on 15/07/24.
//

#ifndef ADDCONSTLLVMPASS_ADDCONST_H
#define ADDCONSTLLVMPASS_ADDCONST_H

#include "llvm/IR/PassManager.h"
#include "llvm/IR/InstrTypes.h"

namespace addconst {
 struct AddConstAnalysis : public llvm::AnalysisInfoMixin<AddConstAnalysis> {
   using Result = llvm::SmallVector<llvm::BinaryOperator *, 0>;
   Result run(llvm::Function &, llvm::FunctionAnalysisManager &);
   static llvm::AnalysisKey Key;
 };

 struct AddConstPrinterPass : public llvm::PassInfoMixin<AddConstPrinterPass> {
   explicit AddConstPrinterPass(llvm::raw_ostream &OS) : OS(OS) {}
   llvm::PreservedAnalyses run(llvm::Function &, llvm::FunctionAnalysisManager &);
  private:
   llvm::raw_ostream &OS;
 };

  struct AddConstPass : public llvm::PassInfoMixin<AddConstPass> {
    llvm::PreservedAnalyses run(llvm::Function &, llvm::FunctionAnalysisManager &);
  };
} // namespace addconst

#endif //ADDCONSTLLVMPASS_ADDCONST_H
