//
//  bytecode.c
//  slang
//
//  Created by Ketib Oldiais on 11/6/22.
//

#include <stdlib.h>
#include "bytecode.h"
#include "memory.h"

void initBytecode(Bytecode* bytecode) {
  bytecode->count = 0;
  bytecode->capacity = 0;
  bytecode->code = NULL;
  bytecode->lines=NULL;
  initValueArray(&bytecode->constants);
}

void freeBytecode(Bytecode* bytecode) {
  FREE_ARRAY(uint8_t, bytecode->code, bytecode->capacity);
  FREE_ARRAY(int, bytecode->lines, bytecode->capacity);
  freeValueArray(&bytecode->constants);
  initBytecode(bytecode);
}

void writeBytecode(Bytecode* bytecode, uint8_t byte, int line) {
  if (bytecode->capacity < bytecode->count+1) {
    int previousCapacity = bytecode->capacity;
    bytecode->capacity = GROW_CAPACITY(previousCapacity);
    bytecode->code = GROW_ARRAY(uint8_t, bytecode->code, previousCapacity, bytecode->capacity);
    bytecode->lines = GROW_ARRAY(int, bytecode->lines, previousCapacity, bytecode->capacity);
  }
  bytecode->code[bytecode->count] = byte;
  bytecode->lines[bytecode->count] = line;
  bytecode->count++;
}

int addConstant(Bytecode* bytecode, Value value) {
  writeValueArray(&bytecode->constants, value);
  return bytecode->constants.count - 1;
}
