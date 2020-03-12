//===-SoftBoundCETS.h  - Interface ---------------------------------*- C++ -*-===//
//
//
//
//===----------------------------------------------------------------------===//
//
// This pass instruments operations for memory safety
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/DebugInfo.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include <fstream>
#include <queue>

using namespace llvm;

namespace {
  struct SoftBoundCETS : public ModulePass {
  
  public:
    SoftBoundCETS() : ModulePass(ID) {}

    virtual bool runOnModule(Module &module);
    static char ID; // Pass identification
    
  private:
  };
}

