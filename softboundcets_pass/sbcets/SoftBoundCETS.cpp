#include "SoftBoundCETS.h"
#include "llvm/IR/CallSite.h"  
#include "llvm/IR/ConstantFolder.h"
#include "llvm/ADT/SCCIterator.h" 
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/StringRef.h"


bool SoftBoundCETS::runOnModule(Module &M) {

  LLVMContext &C = M.getContext();


  for (auto &F : M) {
    if (F.isDeclaration()) continue;
    F.dump();
  }

  return true;
}



void addSOFTBOUNDCETSPass(const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
  PM.add(new SoftBoundCETS());
}

RegisterStandardPasses SOpt(PassManagerBuilder::EP_OptimizerLast,
    addSOFTBOUNDCETSPass);
RegisterStandardPasses S(PassManagerBuilder::EP_EnabledOnOptLevel0,
    addSOFTBOUNDCETSPass);

char SoftBoundCETS::ID = 0;
static const RegisterPass<SoftBoundCETS> Y("softboundcets", "instrument for memory safety", false, false);
