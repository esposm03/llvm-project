#ifndef LLVM_MC_MCVSBFSTREAMER_H
#define LLVM_MC_MCVSBFSTREAMER_H

#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCObjectStreamer.h"
#include "llvm/MC/MCObjectWriter.h"

namespace llvm {
class MCVsbfStreamer : public MCObjectStreamer {
public:
  MCVsbfStreamer(MCContext &Context, std::unique_ptr<MCAsmBackend> TAB, std::unique_ptr<MCObjectWriter> OW, std::unique_ptr<MCCodeEmitter> Emitter);

  bool emitSymbolAttribute(MCSymbol *Symbol, MCSymbolAttr Attribute) override;

  virtual void emitCommonSymbol(MCSymbol *Symbol, uint64_t Size,
                                Align ByteAlignment) override;

  virtual void emitZerofill(MCSection *Section, MCSymbol *Symbol = nullptr,
                            uint64_t Size = 0, Align ByteAlignment = Align(1),
                            SMLoc Loc = SMLoc()) override;

  virtual void emitInstToData(const MCInst &Inst,
                              const MCSubtargetInfo &) override;

};

MCStreamer *createVsbfStreamer(MCContext &Context,
                               std::unique_ptr<MCAsmBackend> TAB,
                               std::unique_ptr<MCObjectWriter> OW,
                               std::unique_ptr<MCCodeEmitter> Emitter);
} // namespace llvm

#endif