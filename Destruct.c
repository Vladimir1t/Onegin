#include "Destruct.h"

void ClearMemory (struct Strings* StrP)
{
    free (StrP->stringsP);
    free (StrP->textPointer);

    StrP->stringsP = NULLptr;
    StrP->textPointer = NULLptr;
}
