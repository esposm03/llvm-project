#ifndef LLVM_TARGET_X86_MCTARGETDESC_X86VSBFOBJECTTARGETWRITER_H
#define LLVM_TARGET_X86_MCTARGETDESC_X86VSBFOBJECTTARGETWRITER_H

#include "llvm/MC/MCObjectWriter.h"
using namespace llvm;

class X86VsbfObjectTargetWriter : public MCObjectTargetWriter {
    virtual Triple::ObjectFormatType getFormat() const override;
};

std::unique_ptr<MCObjectTargetWriter> createX86VsbfObjectWriter();

#endif