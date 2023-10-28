#include "StrSort.h"

int StrcmpEnding (char* str1, int const sizeStr1, char* str2, int const sizeStr2);
template <class X> void Swap (X &a, X &b);

void StrSort (struct Strings* stringsP, int nStrings, int const mod)
{
    //assert (stringSizeP != NULL);
    assert (stringsP != NULL);

    printf ("<< the first type of sorting >>\n");
    for (int pass = 0; pass < nStrings; pass++)
    {
        printf("pass --%d--\n", pass + 1);
        unsigned int count = 0;
        for (int i = 0; i < nStrings - pass - 1; i++)
        {
            if ((mod == BEGINNING && strcmp (stringsP[i].pointer, stringsP[i + 1].pointer) > 0) ||
                 (mod == ENDING && StrcmpEnding (stringsP[i].pointer, stringsP[i].size,
                 stringsP[i + 1].pointer, stringsP[i + 1].size) > 0))
            {
                Swap (stringsP[i].pointer, stringsP[i + 1].pointer);
                Swap (stringsP[i].size, stringsP[i + 1].size);
                printf ("str[%d] <-> str[%d]\n", i + 1, i + 2);
                count++;
            }
        }
        if (count == 0)
            break;
    }
}

/*void StrSortEnding (struct Strings* stringsP, int nStrings)
{
    assert (stringsP != NULL);

    printf ("<< the second type of sorting >>\n");
    for (int pass = 0; pass < nStrings; pass++)
    {
        printf("pass --%d--\n", pass + 1);
        unsigned int count = 0;
        for (int i = 0; i < nStrings - pass - 1; i++)
        {
            if (StrcmpEnding (stringsP[i].pointer, stringsP[i].size,
                              stringsP[i + 1].pointer, stringsP[i + 1].size) > 0)
            {
                Swap (stringsP[i].pointer, stringsP[i + 1].pointer);
                SwapSize (stringsP[i].size, stringsP[i + 1].size);
                printf ("str[%d] <-> str[%d]\n", i + 1, i + 2);
                count++;
            }
        }
        if (count == 0)
            break;
    }
} */

int StrcmpEnding (char* str1, int const sizeStr1, char* str2, int const sizeStr2)
{
    printf ("size1: %d, size2: %d\n", sizeStr1, sizeStr2);
    for (int pos = 1;sizeStr1 >= pos &&
                     sizeStr2 >= pos; pos++)
    {
        if (str1[sizeStr1 - pos] > str2[sizeStr2 - pos])
        {
            printf ("1) %c  2) %c\n", str1[sizeStr1 - pos], str2[sizeStr2 - pos]);
            return 1;
        }
        else if (str1[sizeStr1 - pos] < str2[sizeStr2 - pos])
        {
            printf ("1) %c  2) %c\n", str1[sizeStr1 - pos], str2[sizeStr2 - pos]);
            return -1;
        }
    }
    if (sizeStr2 > sizeStr1)
        return 1;
    return 0;
}

template <class X> void Swap (X &a, X &b)
{
    X temp;
    temp = a;
    a = b;
    b = temp;
}

