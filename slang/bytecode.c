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
}

void freeBytecode(Bytecode* bytecode) {
  FREE_ARRAY(uint8_t, bytecode->code, bytecode->capacity);
  initBytecode(bytecode);
}

void writeBytecode(Bytecode* bytecode, uint8_t byte) {
  if (bytecode->capacity < bytecode->count+1) {
    int previousCapacity = bytecode->capacity;
    bytecode->capacity = GROW_CAPACITY(previousCapacity);
    bytecode->code = GROW_ARRAY(uint8_t, bytecode->code, previousCapacity, bytecode->capacity);
  }
  bytecode->code[bytecode->count] = byte;
  bytecode->count++;
}
