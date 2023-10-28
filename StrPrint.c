#include "StrPrint.h"

void SortedStrPrint (int const nStrings, struct Strings* stringsP/*char** const strPointer, int* stringSizeP*/);
void SortedStrPrintEnding (int const nStrings, struct Strings* stringsP/*char** const strPointer, int* stringSizeP*/);
void PrintSymbols (char* textPointer, int const size);
void Putchar (char a);

void StrPrint (int const nStrings, struct Strings* stringsP/*char** const strPointer,int* stringSizeP*/)
{
    for (size_t n = 0; n < nStrings; n++)
    {
        printf ("%d) %s\n", n + 1, stringsP[n].pointer);
        //stringSizeP[n] = strlen(strPointer[n]);
        // printf ("string length: %d\n", stringSizeP[n]);
    }
}

void SortedStrPrint (int const nStrings, struct Strings* stringsP/*char** const strPointer, int* stringSizeP*/)
{
    printf ("-Strings are sorted by the alphabetic order-\n");
    FILE* filePointerNew = fopen ("Onegin1.txt", "w");   // get name from command line
    for (int n = 0; n < nStrings; n++)
    {
        fputs (stringsP[n].pointer, filePointerNew);
        fputc ('\n', filePointerNew);
    }

    StrPrint (nStrings, stringsP/*strPointer, stringSizeP*/);
}

void SortedStrPrintEnding (int const nStrings, struct Strings* stringsP/*char** const strPointer, int* stringSizeP*/)
{
    printf ("-Strings are sorted by the alphabetic order of the end of the lines-\n");
    FILE* filePointerNew = fopen ("Onegin2.txt", "w");   // command line
    for (int n = 0; n < nStrings; n++)
    {
        fputs (stringsP[n].pointer, filePointerNew);
        fputc ('\n', filePointerNew);
    }

    StrPrint (nStrings, stringsP/*strPointer, stringSizeP*/);
}

void PrintSymbols (char* textPointer, int const size)
{
    for (size_t i = 0; i < size; i++)
    {
        //printf ( "%c",    textPointer[i]);
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
