//
//  debug.h
//  slang
//
//  Created by Ketib Oldiais on 11/7/22.
//

#ifndef debug_h
#define debug_h

#include <stdio.h>
#include "bytecode.h"

void disassembleBytecode(Bytecode* bytecode, const char* name);
int disassembleInstruction(Bytecode* bytecode, int offset);

#endif /* debug_h */
