#ifndef STRPRINT_H_INCLUDED
#define STRPRINT_H_INCLUDED

#include <stdio.h>
#include <string.h>

#include "StringStruct.h"

void StrPrint             (struct Strings* StrP);

void SortedStrPrint       (struct Strings* StrP, int const mod, char* fileName);

void SortedStrPrintEnding (struct Strings* StrP);

void PrintSymbols         (struct Strings* StrP);

#endif // STRPRINT_H_INCLUDED
