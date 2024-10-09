#include "llvm/MC/VsbfObjectWriter.h"
#include "llvm/MC/MCAssembler.h"
#include "llvm/MC/MCSection.h"
#include "llvm/MC/MCValue.h"
#include "llvm/Support/Debug.h"

void VsbfObjectWriter::recordRelocation(MCAssembler &Asm,
                                        const MCFragment *Fragment,
                                        const MCFixup &Fixup, MCValue Target,
                                        uint64_t &FixedValue) {
  dbgs() << "TODO: VsbfObjectWriter::recordRelocation ";
  Fragment->dump();
}

uint64_t VsbfObjectWriter::writeObject(MCAssembler &Asm) {
  uint64_t StartOffset = W.OS.tell();

  auto numSegments = 0;
  auto numSections = Asm.end() - Asm.begin();
  auto dataStart = 0;

  // Write the VSBF header...
  W.OS << 'V' << 'S' << 'B' << 'F';
  W.write<uint16_t>(0); // arch
  W.write<uint16_t>(0); // os
  W.write<uint16_t>(numSegments);
  W.write<uint16_t>(numSections);
  W.write<uint32_t>(0); // strtab size
  W.write<uint32_t>(0); // num symbols
  W.write<uint32_t>(0); // num relocs
  W.write<uint64_t>(0); // next header

  // ... then the segment headers (but this is a .o file, so there aren't any)
  // and the section headers ...
  for (auto &sec : Asm) {
    dbgs() << "Section: " << sec.getVirtualSectionKind() << "\n";
    auto size = Asm.getSectionFileSize(sec);

    W.write<uint8_t>(0);          // typ
    W.write<uint8_t>(7);          // flags
    W.write<uint16_t>(size);      // size
    W.write<uint32_t>(dataStart); // offset
    W.write<uint64_t>(0);         // address

    dataStart += size;
  }

  /// ... and the section data
  for (auto &x : Asm) {
    Asm.writeSectionData(W.OS, &x);
  }

  return W.OS.tell() - StartOffset;
}

std::unique_ptr<MCObjectWriter>
llvm::createVsbfObjectWriter(raw_pwrite_stream &OS) {
  return std::make_unique<VsbfObjectWriter>(OS);
}