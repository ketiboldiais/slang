//
//  bytecode.h
//  slang
//
//  Created by Ketib Oldiais on 11/6/22.
//

#ifndef bytecode_h
#define bytecode_h

#include "common.h"

typedef enum {
  OP_RETURN,
} OpCode;

typedef struct {
  int count;
  int capacity;
  uint8_t* code;
} Bytecode;

void initBytecode(Bytecode* bytecode);
void freeBytecode(Bytecode* bytecode);
void writeBytecode(Bytecode* bytecode, uint8_t byte);

#endif /* bytecode_h */
