//
// Created by Rajveer Singh on 16/07/24.
//

#include "AddConst.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/Constants.h"
using namespace llvm;

namespace addconst {
  void ReplaceAddInstWithConstant(BinaryOperator *BO) {
    auto first = cast<Constant>(BO->getOperand(0));
    auto second = cast<Constant>(BO->getOperand(1));
    auto sum = ConstantExpr::getAdd(first, second);
    BO->replaceAllUsesWith(sum);
    BO->eraseFromParent();
  }

  PreservedAnalyses AddConstPass::run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM) {
    auto &AddInsts = FAM.getResult<AddConstAnalysis>(F);
    for (auto BO: AddInsts)
      ReplaceAddInstWithConstant(BO);
    auto PA = llvm::PreservedAnalyses::all();
    PA.abandon<AddConstAnalysis>();
    return PA;
  }
}
