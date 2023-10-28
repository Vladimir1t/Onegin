#ifndef STRINGREAD_H_INCLUDED
#define STRINGREAD_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "struct.h"

enum yesNo
{
    YES       =  1,
    NO        =  0,
    UNDEFINED = -1,
};

int StringsCount (char* const textPointer, size_t const size, size_t* nStrings);

void StringsPointerRead (struct Strings* stringsP, char* const textPointer,
                         size_t const size, int const nStrings, int const isR);

#endif // STRINGREAD_H_INCLUDED
