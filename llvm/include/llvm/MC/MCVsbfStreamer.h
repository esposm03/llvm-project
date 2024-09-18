#ifndef LLVM_MC_MCVSBFSTREAMER_H
#define LLVM_MC_MCVSBFSTREAMER_H

#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCObjectStreamer.h"
#include "llvm/MC/MCObjectWriter.h"

/*
Useful fields:
- CurFrag is the current fragment; there can be multiple fragments, and they form a tree structure
*/

namespace llvm {
class MCVsbfStreamer : public MCObjectStreamer {
public:
  MCVsbfStreamer(MCContext &Context, std::unique_ptr<MCAsmBackend> TAB, std::unique_ptr<MCObjectWriter> OW, std::unique_ptr<MCCodeEmitter> Emitter);

  void initSections(bool NoExecStack, const MCSubtargetInfo &STI) override;
  void changeSection(MCSection *Section, uint32_t Subsection = 0) override;
  void emitLabel(MCSymbol *Symbol, SMLoc Loc = SMLoc()) override;
  void emitLabelAtPos(MCSymbol *Symbol, SMLoc Loc, MCDataFragment &F,
                      uint64_t Offset) override;
  void emitAssemblerFlag(MCAssemblerFlag Flag) override;
  // void emitThumbFunc(MCSymbol *Func) override;
  void emitWeakReference(MCSymbol *Alias, const MCSymbol *Symbol) override;
  bool emitSymbolAttribute(MCSymbol *Symbol, MCSymbolAttr Attribute) override;
  void emitSymbolDesc(MCSymbol *Symbol, unsigned DescValue) override;
  void emitCommonSymbol(MCSymbol *Symbol, uint64_t Size,
                        Align ByteAlignment) override;

  void emitZerofill(MCSection *Section, MCSymbol *Symbol = nullptr,
                    uint64_t Size = 0, Align ByteAlignment = Align(1),
                    SMLoc L = SMLoc()) override;
  // void emitTBSSSymbol(MCSection *Section, MCSymbol *Symbol, uint64_t Size,
  //                     Align ByteAlignment = Align(1)) override;
  // void emitValueImpl(const MCExpr *Value, unsigned Size,
  //                    SMLoc Loc = SMLoc()) override;

  // void emitIdent(StringRef IdentString) override;

  // void emitValueToAlignment(Align, int64_t, unsigned, unsigned) override;

  // void emitCGProfileEntry(const MCSymbolRefExpr *From,
  //                         const MCSymbolRefExpr *To, uint64_t Count) override;

private:
  // bool isBundleLocked() const;
  // void emitInstToFragment(const MCInst &Inst, const MCSubtargetInfo &) override;
  void emitInstToData(const MCInst &Inst, const MCSubtargetInfo &) override;

  // void fixSymbolsInTLSFixups(const MCExpr *expr);
  // void finalizeCGProfileEntry(const MCSymbolRefExpr *&S, uint64_t Offset);
  // void finalizeCGProfile();
};

MCStreamer *createVsbfStreamer(MCContext &Context,
                               std::unique_ptr<MCAsmBackend> TAB,
                               std::unique_ptr<MCObjectWriter> OW,
                               std::unique_ptr<MCCodeEmitter> Emitter);
} // namespace llvm

#endif