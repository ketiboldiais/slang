//
//  bytecode.h
//  slang
//
//  Created by Ketib Oldiais on 11/6/22.
//

#ifndef bytecode_h
#define bytecode_h

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_RETURN,
} OpCode;

typedef struct {
  int count;
  int capacity;
  uint8_t* code;
  int* lines;
  ValueArray constants;
} Bytecode;

void initBytecode(Bytecode* bytecode);
void freeBytecode(Bytecode* bytecode);
void writeBytecode(Bytecode* bytecode, uint8_t byte, int line);
int addConstant(Bytecode* bytecode, Value value);

#endif /* bytecode_h */
