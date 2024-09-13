#include "llvm/MC/VsbfObjectWriter.h"
#include "llvm/MC/MCValue.h"

void VsbfObjectWriter::recordRelocation(MCAssembler &Asm, const MCFragment *Fragment,
                      const MCFixup &Fixup, MCValue Target,
                      uint64_t &FixedValue) {}

uint64_t VsbfObjectWriter::writeObject(MCAssembler &Asm) {
    uint64_t StartOffset = W.OS.tell();

    // Write the VSBF header
    W.OS << 'V' << 'S' << 'B' << 'F';
    W.write<uint16_t>(0); // arch
    W.write<uint16_t>(0); // os
    W.write<uint16_t>(0); // num segments
    W.write<uint16_t>(0); // num sections
    W.write<uint64_t>(0); // next header

    return W.OS.tell() - StartOffset;
}

std::unique_ptr<MCObjectWriter>
llvm::createVsbfObjectWriter(raw_pwrite_stream &OS) {
  return std::make_unique<VsbfObjectWriter>(OS);
}