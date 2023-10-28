#ifndef STRSORT_H_INCLUDED
#define STRSORT_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "struct.h"

//#define Swap(a, b) do { char* c = a; a = b; b = c; }  while (0)
//#define SwapSize(x, y) { int d = x; x = y; y = d; }

void StrSort (struct Strings* stringsP, int nStrings, int const mod);

int StrcmpEnding (char* str1, int const sizeStr1, char* str2, int const sizeStr2);

template <class X> void Swap (X &a, X &b);

#endif // STRSORT_H_INCLUDED
