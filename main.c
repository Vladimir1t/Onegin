#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "FileSize.h"
#include "FileReadingCheck.h"
#include "StringRead.h"
#include "StrSort.h"
#include "StrPrint.h"
#include "struct.h"

int main(int argc, char* argv[])
{
    printf ("main open\n");
    FILE* const fileP = fopen (argv[1], "rb");                     // gets the fileName from command line
    assert (fileP != NULL);

    size_t size = 0;
    size = FileSize (fileP, ftell(fileP));
    printf ("size of file: %d\n", size);                           // measures the size of a text

    char* textPointer = (char*) calloc (size + 1, sizeof(char));

    size_t factualSize = fread (textPointer, sizeof(char), size, fileP);
    if (factualSize != size)
        {
            printf ("Error.\n");
            return 0;
        }
    fclose (fileP);
    //FileReadingCheck (fileP, factualSize);
    printf ("factual size: %d\n", factualSize);

    PrintSymbols (textPointer, size);                               // prints all symbols from the file.txt

    size_t nStrings = 0;
    int const isR = StringsCount (textPointer, size, &nStrings);    // counts the number of strings and check if there are '\r'

    struct Strings* stringsP = (Strings*) calloc (nStrings, sizeof(Strings));

    StringsPointerRead (stringsP, textPointer, size, nStrings, isR); // puts strings in array

    StrPrint (nStrings, stringsP);                                   // prints unsorted strings

    StrSort (stringsP, nStrings, BEGINNING);                         // sorts string by alphabetic order
    SortedStrPrint (nStrings, stringsP, BEGINNING, argv[2]);         // prints sorted strings and put them in file onegin1.txt

    StrSort (stringsP, nStrings, ENDING);                                    // sorts string by alphabetic order of their endings
    SortedStrPrint (nStrings, stringsP, ENDING, argv[3]);            // prints sorted string and put them in file onegin2.txt

    printf ("main close");
}




