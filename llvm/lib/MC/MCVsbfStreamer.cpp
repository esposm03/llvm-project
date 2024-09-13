#include "llvm/MC/MCVsbfStreamer.h"
#include "llvm/MC/MCObjectStreamer.h"

using namespace llvm;

MCVsbfStreamer::MCVsbfStreamer(
    MCContext &Context, std::unique_ptr<MCAsmBackend> TAB,
    std::unique_ptr<MCObjectWriter> OW, std::unique_ptr<MCCodeEmitter> Emitter)
    : MCObjectStreamer(Context, std::move(TAB), std::move(OW), std::move(Emitter)) {}

bool MCVsbfStreamer::emitSymbolAttribute(MCSymbol *Symbol, MCSymbolAttr Attribute) {
    return false;
}

void MCVsbfStreamer::emitCommonSymbol(MCSymbol *Symbol, uint64_t Size, Align ByteAlignment) {}

void MCVsbfStreamer::emitZerofill(MCSection *Section, MCSymbol *Symbol,
                        uint64_t Size, Align ByteAlignment,
                        SMLoc Loc) {}

void MCVsbfStreamer::emitInstToData(const MCInst &Inst,
                            const MCSubtargetInfo &) {}

MCStreamer *llvm::createVsbfStreamer(MCContext &Context,
                                  std::unique_ptr<MCAsmBackend> TAB,
                                  std::unique_ptr<MCObjectWriter> OW,
                                  std::unique_ptr<MCCodeEmitter> Emitter) {
  return new MCVsbfStreamer(Context, std::move(TAB), std::move(OW),
                                   std::move(Emitter));
}