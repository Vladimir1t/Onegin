#include "StringRead.h"

void StringsPointerRead (struct Strings* stringsP, char* const textPointer, size_t const size, int const* nStrings,  int const isR);

int StringsCount (char* const textPointer, size_t const size, size_t* nStrings)
{
    assert (textPointer != NULL);
    yesNo isR = UNDEFINED;

    for (size_t j = 0; j < size + 1; j++)
    {
        if (textPointer[j] == '\r')
        {
            textPointer[j] = '\0';
            (*nStrings)++;
            isR = YES;
            printf ("--%c--\n", textPointer[j - 1]);
            j++;
        }
        else if (textPointer[j] == '\n' && textPointer[j - 1] != '\r')
        {
            textPointer[j] = '\0';
            (*nStrings)++;
            isR = NO;
            printf ("-%c-\n", textPointer[j - 1]);
        }

        else if (textPointer[j] == '\0')
            (*nStrings)++;
    }
    printf ("number of strings: %d\n", *nStrings);
    printf ("r: %d\n", isR);

    return isR;
}

void StringsPointerRead (struct Strings* stringsP, char* const textPointer,
                         size_t const size, int const nStrings, int const isR)
{
    assert (stringsP != NULL);
    assert (textPointer != NULL);

    size_t n = 0;
    stringsP[n].pointer = textPointer;
    printf ("address of 1 string: %d\n", stringsP[n].pointer);
    n++;

    for (size_t i = 0; i < size; i++)
    {
        if (textPointer[i] == '\0' && n < nStrings && isR == YES)
        {
            stringsP[n].pointer = textPointer + (i + 2);
            printf ("address of %d string: %d\n", n + 1, stringsP[n].pointer);
            stringsP[n - 1].size = stringsP[n].pointer - stringsP[n - 1].pointer - 2;
            //printf ("Size(%d) %d\n", n - 1, stringsP[n - 1].size);
            n++;
        }
        if (textPointer[i] == '\0' && n < nStrings && isR == NO)                  // if there are '\r'
        {
            stringsP[n].pointer = textPointer + (i + 1);
            printf ("address of %d string: %d\n", n + 1, stringsP[n].pointer);    // if there are no '\r'
            stringsP[n - 1].size = stringsP[n].pointer - stringsP[n - 1].pointer - 1;
            //printf ("Size(%d) %d\n", n, stringsP[n - 1].size);
            n++;
        }
    }
    stringsP[n - 1].size = strlen (stringsP[n - 1].pointer);
    printf ("Size(%d) %d\n", n, stringsP[n - 1].size);
}
