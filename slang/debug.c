//
//  debug.c
//  slang
//
//  Created by Ketib Oldiais on 11/7/22.
//

#include "debug.h"

void disassembleBytecode(Bytecode* bytecode, const char* name) {
  printf("== %s ==\n", name);
  for (int offset = 0; offset < bytecode->count;) {
    offset = disassembleInstruction(bytecode, offset);
  }
}

static int simpleInstruction(const char* name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

int disassembleInstruction(Bytecode* bytecode, int offset) {
  printf("%04d ", offset);
  uint8_t instruction = bytecode->code[offset];
  switch (instruction) {
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    default:
      printf("Unknown opcode %d\n", instruction);
      return offset+1;
  }
}
