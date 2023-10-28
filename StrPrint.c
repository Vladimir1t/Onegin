#include "StrPrint.h"

void SortedStrPrint (int const nStrings, struct Strings* stringsP, int const mod);
void PrintSymbols (char* textPointer, int const size);
void Putchar (char a);

void StrPrint (int const nStrings, struct Strings* const stringsP)
{
    for (size_t n = 0; n < nStrings; n++)
    {
        printf ("%d) %s\n", n + 1, stringsP[n].pointer);
        //printf ("string length: %d\n", stringsP[n].size);
    }
}

void SortedStrPrint (int const nStrings, struct Strings* stringsP, int const mod, char* fileName)
{
    FILE* filePointerNew = fopen (fileName, "w");   // get name from command line
    if (mod == BEGINNING)
        printf ("-Strings are sorted by the alphabetic order-\n");
    else if (mod == ENDING)
        printf ("-Strings are sorted by the alphabetic order of the end of the lines-\n");
    else
        printf ("Error.");

    for (int n = 0; n < nStrings; n++)
    {
        fputs (stringsP[n].pointer, filePointerNew);
        fputc ('\n', filePointerNew);
    }

    StrPrint (nStrings, stringsP);
}

void PrintSymbols (char* textPointer, int const size)
{
    for (size_t i = 0; i < size; i++)
    {
        Putchar (textPointer[i]);
        printf ("(%d)\n", textPointer[i]);
    }
}

void Putchar (char a)
{
    switch (a)
        {
        case '\r':
            printf ("\\r");
            break;
        case '\n':
            printf ("\\n");
            break;
        case '\0':
            printf ("\\0");
            break;
        case '\t':
            printf ("\\t");
            break;
        default:
            putchar (a);
            break;
        }
}

