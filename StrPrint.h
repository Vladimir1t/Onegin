#ifndef STRPRINT_H_INCLUDED
#define STRPRINT_H_INCLUDED

#include <stdio.h>
#include <string.h>

#include "struct.h"

void StrPrint (int const nStrings, struct Strings* stringP/*char** const strPointer, int* stringSizeP*/);

void SortedStrPrint (int const nStrings, struct Strings* stringsP/*char** const strPointer, int* stringSizeP*/);

void SortedStrPrintEnding (int const nStrings, struct Strings* stringsP/*char** const strPointer, int* stringSizeP*/);

void PrintSymbols (char* textPointer, int const size);

#endif // STRPRINT_H_INCLUDED
