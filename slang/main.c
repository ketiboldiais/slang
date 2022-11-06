//
//  main.c
//  slang
//
//  Created by Ketib Oldiais on 11/6/22.
//

#include <stdio.h>
#include "bytecode.h"

int main(int argc, const char * argv[]) {
  Bytecode bytecode;
  initBytecode(&bytecode);
  writeBytecode(&bytecode, OP_RETURN);
  freeBytecode(&bytecode);
  return 0;
}
