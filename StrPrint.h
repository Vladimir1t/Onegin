#ifndef STRPRINT_H_INCLUDED
#define STRPRINT_H_INCLUDED

#include <stdio.h>
#include <string.h>

#include "struct.h"

void StrPrint (int const nStrings, struct Strings* const stringP);

void SortedStrPrint (int const nStrings, struct Strings* stringsP, int const mod, char* fileName);

void SortedStrPrintEnding (int const nStrings, struct Strings* stringsP);

void PrintSymbols (char* textPointer, int const size);

#endif // STRPRINT_H_INCLUDED
