#ifndef STRSORT_H_INCLUDED
#define STRSORT_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "StringStruct.h"

void StrSort     (struct Strings* StrP, int (*comperator)(String*, String*));

int StrcmpEnding (struct String* stringsP1, struct String* stringsP2);

int Strcmp       (struct String* stringsP1, struct String* stringsP2);

void SwapString  (struct String* stringsP1, struct String* stringsP2);

#endif // STRSORT_H_INCLUDED
