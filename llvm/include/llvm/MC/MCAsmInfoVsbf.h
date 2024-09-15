//===- llvm/MC/MCAsmInfoELF.h - ELF Asm info --------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_MC_MCASMINFOVSBF_H
#define LLVM_MC_MCASMINFOVSBF_H

#include "llvm/MC/MCAsmInfo.h"
#include "llvm/TargetParser/Triple.h"

namespace llvm {

class MCAsmInfoVsbf : public MCAsmInfo {
public:
  MCAsmInfoVsbf(const Triple &T);
};

} // end namespace llvm

#endif // LLVM_MC_MCASMINFOELF_H
