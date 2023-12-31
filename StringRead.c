#include "StringRead.h"

void StringsPointerRead (struct Strings* StrP, fileFormat isR);

int StringsCount (struct Strings* StrP)
{
    assert (StrP->textPointer != NULL);
    fileFormat isR = UNDEFINED;

    for (size_t j = 0; j < StrP->fileSize + 1; j++)
    {
        if (StrP->textPointer[j] == '\r')
        {
            StrP->textPointer[j] = '\0';
            (StrP->nStrings)++;
            j++;
        }
        else if (StrP->textPointer[j] == '\n')
        {
            StrP->textPointer[j] = '\0';
            (StrP->nStrings)++;
        }

        else if (StrP->textPointer[j] == '\0')
            (StrP->nStrings)++;
    }
    printf ("number of strings: %d\n", StrP->nStrings);

    char* elementP = strchr (StrP->textPointer, '\0');
    isR = (strP->nStrings > 1 && *(elementP + 1) == '\n');

    return isR;
}

void StringsPointerRead (struct Strings* StrP, fileForemat isR)
{
    assert (StrP->stringsP    != NULL);
    assert (StrP->textPointer != NULL);

    size_t n = 0, stringLen = 0;
    StrP->stringsP[n].pointer = StrP->textPointer;
    printf ("address of 1 string: %d\n", StrP->stringsP[n].pointer);
    n++;

    for (size_t i = 0; i < StrP->fileSize; i++)
    {
        if (StrP->textPointer[i] == '\0' && n < StrP->nStrings)
        {
            if (isR == YES)
            {
                StrP->stringsP[n].pointer = StrP->textPointer + (i + 2);
                //printf ("Size(%d) %d\n", n - 1, StrP->stringsP[n - 1].size);
                i+=2;
            }
            else if (isR == NO)
            {
                StrP->stringsP[n].pointer = StrP->textPointer + (i + 1);
                i++;
            }
            printf ("address of %d string: %d\n", n + 1, StrP->stringsP[n].pointer);
            StrP->stringsP[n - 1].size = stringLen;
            //printf ("Size(%d) %d\n", n - 1, StrP->stringsP[n - 1].size);
            n++;
            stringLen = 0;
        }

        else if (StrP->textPointer[i] == '\0' && n == StrP->nStrings)
            StrP->stringsP[n - 1].size = stringLen;

    stringLen++;
    }
}
