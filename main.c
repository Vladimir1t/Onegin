#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "FileMeasure.h"
#include "FileReadingCheck.h"

int main()
{
    printf ("main open\n");
    FILE* const fileP = fopen ("file.txt", "r");
    assert (fileP != NULL);

    size_t size = 0;

    size = FileMeasure (fileP);
    printf ("size of file: %d\n", size);

    char* textPointer = (char*) calloc (size /*+ 1*/, sizeof(char));

    //if (fseek (fileP, 0, SEEK_SET) != 0)
    //    printf("error in fseek().\n");

    size_t factualSize = fread (textPointer, sizeof(char), size, fileP);

    FileReadingCheck (fileP, factualSize);

    for (size_t i = 0; i < size; i++)
    {
        printf ( "%c",    textPointer[i]);
        printf ("(%d)\n", textPointer[i]);
    }

    size_t nStrings = 0;
    for (size_t j = 0; j < size; j++)
    {
        if (textPointer[j] == '\n')
        {
            textPointer[j] =  '\0';
            nStrings++;
        }
    }
    nStrings += 1;
    printf ("number of strings: %d\n", nStrings);

    char** strPointer = (char**) calloc (nStrings, sizeof(char*));

    //strPointer[j] = &pointer[0]; //
    size_t j = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (textPointer[i] == '\0' and j < nStrings)
        {
            strPointer[j] = textPointer + (i + 1);
            printf ("--%d--\n", i + 1);
            printf ("address of %d string: %d\n", j + 1, strPointer[j]);
            j++;
        }
        else if (i == 0)
        {
            strPointer[j] = textPointer;
            printf ("--%d--\n", i);
            printf ("address of %d string: %d\n", j + 1, strPointer[j]);
            j++;
        }
    }

    for (size_t n = 0; n < nStrings; n++)
    {
        printf ("%d) %s\n", n + 1, strPointer[n]);
        printf ("string length: %d\n", strlen(strPointer[n]));
    }

    printf ("main close");
}




