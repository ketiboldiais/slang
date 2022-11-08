//
//  main.c
//  slang
//
//  Created by Ketib Oldiais on 11/6/22.
//

#include <stdio.h>
#include "bytecode.h"
#include "debug.h"

int main(int argc, const char * argv[]) {
  Bytecode bytecode;
  initBytecode(&bytecode);
  int constant = addConstant(&bytecode, 1.2);
  writeBytecode(&bytecode, OP_CONSTANT, 123);
  writeBytecode(&bytecode, constant, 123);
  writeBytecode(&bytecode, OP_RETURN, 123);
  disassembleBytecode(&bytecode, "test bytecode");
  freeBytecode(&bytecode);
  return 0;
}
