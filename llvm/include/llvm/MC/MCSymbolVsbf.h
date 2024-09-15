#ifndef LLVM_MC_MCSYMBOLVSBF_H
#define LLVM_MC_MCSYMBOLVSBF_H

#include "llvm/MC/MCSymbol.h"

namespace llvm {
class MCSymbolVsbf : public MCSymbol {
  public:
    MCSymbolVsbf(const MCSymbolTableEntry *Name, bool isTemporary)
      : MCSymbol(SymbolKindVsbf, Name, isTemporary) {}
};
}

#endif