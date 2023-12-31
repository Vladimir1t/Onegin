#include "StrSort.h"

int StrcmpEnding (struct String* stringsP1, struct String* stringsP2);
int Strcmp       (struct String* stringsP1, struct String* stringsP2);
void Swap        (void* a, void* b, int nBytes);

void StrSort (struct Strings* StrP, int (*comperator) (String*, String*))
{
    assert (StrP->stringsP != NULL);

    //printf ("<< the first type of sorting >>\n");
    for (int pass = 0; pass < StrP->nStrings; pass++)
    {
        //printf ("< pass %d >\n", pass);
        unsigned int count = 0;
        for (int i = 0; i < StrP->nStrings - pass - 1; i++)
        {
            if (comperator (&StrP->stringsP[i], &StrP->stringsP[i + 1]) > 0)
            {
                SwapString (&StrP->stringsP[i], &StrP->stringsP[i + 1], sizeof(&StrP->stringsP[0]));

                //Swap (&StrP->stringsdata, )

                printf ("str[%d] <-> str[%d]\n", i + 1, i + 2);
                count++;
            }
        }
        if (count == 0)
            break;
    }
}

int StrcmpEnding (struct String* stringsP1, struct String* stringsP2)
{
    for (int pos = 1; stringsP1->size >= pos &&
                      stringsP2->size >= pos; pos++)
    {
        if (stringsP1->pointer[stringsP1->size - pos] > stringsP2->pointer[stringsP2->size - pos])
        {
            //printf ("1) %c  2) %c\n", stringsP1->pointer[stringsP1->size - pos], stringsP2->pointer[stringsP2->size - pos]);
            return 1;
        }
        else if (stringsP1->pointer[stringsP1->size - pos] < stringsP2->pointer[stringsP2->size - pos])
        {
            //printf ("1) %c  2) %c\n", str1[sizeStr1 - pos], str2[sizeStr2 - pos]);
            return -1;
        }
    }
    if (stringsP2->size > stringsP1->size)
        return 1;

    return 0;
}

int Strcmp (struct String* stringsP1, struct String* stringsP2)
{
    //printf ("size1: %d, size2: %d\n", sizeStr1, sizeStr2);
    for (int pos = 0; stringsP1->size >= pos &&
                      stringsP2->size >= pos; pos++)
    {
        if (stringsP1->pointer[pos] > stringsP2->pointer[pos])
        {
            //printf ("1) %c  2) %c\n", stringsP1->pointer[pos], stringsP2->pointer[pos]);
            return 1;
        }
        else if (stringsP1->pointer[pos] < stringsP2->pointer[pos])
        {
            //printf ("1) %c  2) %c\n", str1[sizeStr1 - pos], str2[sizeStr2 - pos]);
            return -1;
        }
    }
    if (stringsP2->size > stringsP1->size)
        return 1;

    return 0;
}

void Swap (void* a, void* b, int nBytes)
{
    (char*) a1 = (char*) a;
    (char*) b1 = (char*) b;
    unsigned char c = 0;

    for (int i = 0; i < nBytes, i++)
    {
        c = a1[i];
            a1[i] = b1[i];
                    b1[i] = c;
    }
}


