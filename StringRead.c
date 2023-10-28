#include "StringRead.h"

void StringsPointerRead (/*char** const strPointer,*/ struct Strings* stringsP, char* const textPointer, size_t const size, int const nStrings);

int StringsCount (char* const textPointer, size_t const size)
{
    assert (textPointer != NULL);

    size_t nStrings = 0;
    for (size_t j = 0; j < size + 1; j++)
    {
        if (textPointer[j] == '\r')
        {
            textPointer[j] =  '\0';
            nStrings++;
        }
        else if (textPointer[j] == '\0')
            nStrings++;
    }
    printf ("number of strings: %d\n", nStrings);

    return nStrings;
}

void StringsPointerRead (/*char** const strPointer,*/ struct Strings* stringsP, char* const textPointer, size_t const size, int const nStrings)
{
    assert (stringsP != NULL);          // ���������� ������ ��������
    assert (textPointer != NULL);

    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (textPointer[i] == '\0' && j < nStrings)
        {
            stringsP[j].pointer = textPointer + (i + 2);
            printf ("--%d--\n", i + 2);
            printf ("address of %d string: %d\n", j + 1, stringsP[j].pointer);
            stringsP[j].size = strlen(stringsP[j].pointer);
            j++;
        }
        else if (i == 0)
        {
            stringsP[j].pointer = textPointer;
            printf ("--%d--\n", i);
            printf ("address of %d string: %d\n", j + 1, stringsP[j]);
            j++;
        }
    }
}
