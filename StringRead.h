#ifndef STRINGREAD_H_INCLUDED
#define STRINGREAD_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "struct.h"

int StringsCount (char* const textPointer, size_t const size);

void StringsPointerRead (/*char** const strPointer,*/ struct Strings* stringsP, char* const textPointer,
                         size_t const size, int const nStrings);

#endif // STRINGREAD_H_INCLUDED
