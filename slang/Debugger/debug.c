//
//  debug.c
//  slang
//
//  Created by Ketib Oldiais on 11/7/22.
//

#include "debug.h"
#include "value.h"

void disassembleBytecode(Bytecode* bytecode, const char* name) {
  printf("== %s ==\n", name);
  for (int offset = 0; offset < bytecode->count;) {
    offset = disassembleInstruction(bytecode, offset);
  }
}

static int constantInstruction(const char* name, Bytecode* bytecode, int offset) {
  uint8_t constant = bytecode->code[offset+1];
  printf("%-16s %4d '", name, constant);
  printValue(bytecode->constants.values[constant]);
  printf("'\n");
  return offset+2;
}

static int simpleInstruction(const char* name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

int disassembleInstruction(Bytecode* bytecode, int offset) {
  printf("%04d ", offset);
  if (offset > 0 && bytecode->lines[offset] == bytecode->lines[offset-1]) {
    printf("    | ");
  } else {
    printf("%4d ", bytecode->lines[offset]);
  }
  uint8_t instruction = bytecode->code[offset];
  switch (instruction) {
    case OP_CONSTANT:
      return constantInstruction("OP_CONSTANT", bytecode, offset);
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    default:
      printf("Unknown opcode %d\n", instruction);
      return offset+1;
  }
}
