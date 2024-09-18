#include "llvm/MC/MCVsbfStreamer.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCAssembler.h"
#include "llvm/MC/MCDirectives.h"
#include "llvm/MC/MCFragment.h"
#include "llvm/MC/MCObjectFileInfo.h"
#include "llvm/MC/MCObjectStreamer.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/Support/Debug.h"
#include <cassert>

using namespace llvm;

MCVsbfStreamer::MCVsbfStreamer(
    MCContext &Context, std::unique_ptr<MCAsmBackend> TAB,
    std::unique_ptr<MCObjectWriter> OW, std::unique_ptr<MCCodeEmitter> Emitter)
    : MCObjectStreamer(Context, std::move(TAB), std::move(OW), std::move(Emitter)) {
        assert(getContext().getAsmInfo()->getExceptionHandlingType() == ExceptionHandling::None);
    }


void MCVsbfStreamer::initSections(bool NoExecStack, const MCSubtargetInfo &STI) {
    dbgs() << "TODO: initSections " << NoExecStack << "\n";
    MCObjectStreamer::initSections(NoExecStack, STI);
}

void MCVsbfStreamer::changeSection(MCSection *Section, uint32_t Subsection) {
    dbgs() << "TODO: changeSection " << Section->getName() << " " << Subsection << "\n";
    MCObjectStreamer::changeSection(Section,  Subsection);
}

void MCVsbfStreamer::emitZerofill(MCSection *Section, MCSymbol *Symbol,
                        uint64_t Size, Align ByteAlignment,
                        SMLoc Loc) {}

void MCVsbfStreamer::emitInstToData(const MCInst &Inst,
                            const MCSubtargetInfo &STI) {
    dbgs() << "TODO: emitInstToData " << Inst << "\n";

    MCAssembler &Assembler = getAssembler();
    MCDataFragment *DF = getOrCreateDataFragment(&STI);

    // Emit instruction directly into data fragment.
    size_t FixupStartIndex = DF->getFixups().size();
    size_t CodeOffset = DF->getContents().size();
    Assembler.getEmitter().encodeInstruction(Inst, DF->getContents(),
                                            DF->getFixups(), STI);

    auto Fixups = MutableArrayRef(DF->getFixups()).slice(FixupStartIndex);
    for (auto &Fixup : Fixups) {
        Fixup.setOffset(Fixup.getOffset() + CodeOffset);
    }

    DF->setHasInstructions(STI);
}

void MCVsbfStreamer::emitLabel(MCSymbol *S, SMLoc Loc) {
    dbgs() << "TODO: emitLabel " << *S << "\n";
}

void MCVsbfStreamer::emitLabelAtPos(MCSymbol *Symbol, SMLoc Loc, MCDataFragment &F, uint64_t Offset) {
    dbgs() << "TODO: emitLabelAtPos " << *Symbol << " " << *F.getAtom() << " " << Offset << "\n";
}

void MCVsbfStreamer::emitAssemblerFlag(MCAssemblerFlag flag) {
    dbgs() << "TODO: emitAssemblerFlag " << flag << "\n";
}

void MCVsbfStreamer::emitWeakReference(MCSymbol *Alias, const MCSymbol *Symbol) {
    dbgs() << "TODO: emitWeakReference " << *Alias << " " << *Symbol << "\n";
}

bool MCVsbfStreamer::emitSymbolAttribute(MCSymbol *Symbol, MCSymbolAttr Attribute) {
    dbgs() << "TODO: emitSymbolAttribute " << *Symbol << " " << Attribute << "\n";
    return true;
}

void MCVsbfStreamer::emitSymbolDesc(MCSymbol *Symbol, unsigned int DescValue) {
    dbgs() << "TODO: emitSymbolDesc " << *Symbol << " " << DescValue << "\n";
}

void MCVsbfStreamer::emitCommonSymbol(MCSymbol *Symbol, uint64_t Size, Align ByteAlignment) {
    dbgs() << "TODO: emitCommonSymbol " << *Symbol << " " << Size << " " << ByteAlignment.value() << "\n";
}


MCStreamer *llvm::createVsbfStreamer(MCContext &Context,
                                  std::unique_ptr<MCAsmBackend> TAB,
                                  std::unique_ptr<MCObjectWriter> OW,
                                  std::unique_ptr<MCCodeEmitter> Emitter) {
  return new MCVsbfStreamer(Context, std::move(TAB), std::move(OW),
                                   std::move(Emitter));
}