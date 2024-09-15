#include "llvm/MC/MCAsmInfoVsbf.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/TargetParser/Triple.h"
#include <cassert>

using namespace llvm;

MCAsmInfoVsbf::MCAsmInfoVsbf(const Triple &T) : MCAsmInfo() {
    HasIdentDirective = true;
    WeakRefDirective = "\t.weak\t";
    PrivateGlobalPrefix = ".L";
    PrivateLabelPrefix = ".L";

    // Use Intel syntax for assembly; for example of how to use it, look at X86MCAsmInfo.cpp
    AssemblerDialect = 1;

    assert(T.getArch() == Triple::x86_64 && "Vsbf only supports x86_64 right now");
    CodePointerSize = 8;
    CalleeSaveStackSlotSize = 8;

    // Use the `nop` instruction to align code
    TextAlignFillValue = 0x90;

    SupportsDebugInformation = false;
    ExceptionsType = ExceptionHandling::None;
}