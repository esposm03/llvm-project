#ifndef LLVM_MC_MCVSBFOBJECTWRITER_H
#define LLVM_MC_MCVSBFOBJECTWRITER_H

#include "llvm/ADT/bit.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/Support/EndianStream.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace llvm {

class VsbfObjectWriter final : public MCObjectWriter {
public:
  support::endian::Writer W;

  VsbfObjectWriter(raw_pwrite_stream &OS) : MCObjectWriter(), W(OS, endianness::little) {}

  void recordRelocation(MCAssembler &Asm, const MCFragment *Fragment,
                        const MCFixup &Fixup, MCValue Target,
                        uint64_t &FixedValue) override;

  uint64_t writeObject(MCAssembler &Asm) override;
};

std::unique_ptr<MCObjectWriter>
createVsbfObjectWriter(raw_pwrite_stream &OS);

} // namespace llvm

#endif // LLVM_MC_MCVSBFBJECTWRITER_H