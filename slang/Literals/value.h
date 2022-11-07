//
//  value.h
//  slang
//
//  Created by Ketib Oldiais on 11/7/22.
//

#ifndef value_h
#define value_h

#include <stdio.h>
#include "common.h"

typedef double Value;

typedef struct {
  int capacity;
  int count;
  Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif /* value_h */
