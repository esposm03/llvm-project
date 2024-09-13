#include "X86VsbfObjectTargetWriter.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/TargetParser/Triple.h"
#include <memory>

using namespace llvm;

std::unique_ptr<MCObjectTargetWriter> createX86VsbfObjectWriter() {
    return std::make_unique<X86VsbfObjectTargetWriter>();
}

Triple::ObjectFormatType X86VsbfObjectTargetWriter::getFormat() const {
    return Triple::Vsbf;
}