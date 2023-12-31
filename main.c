#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "FileSize.h"
#include "FileReadingCheck.h"
#include "StringRead.h"
#include "StrSort.h"
#include "StrPrint.h"
#include "StringStruct.h"
#include "Destruct.h"

int main(int argc, char* argv[])
{
    struct Strings Str = {};

    FILE* const fileP = fopen (argv[1], "rb");         // gets the fileName from command line
    assert (fileP != NULL);

    Str.fileSize = FileSize (fileP);
    printf ("size of file: %d\n", Str.fileSize);       // measures the size of a text

    Str.textPointer = (char*) calloc (Str.fileSize + 1, sizeof(char));

    size_t factualSize = fread (Str.textPointer, sizeof(char), Str.fileSize, fileP);
    if (factualSize != Str.fileSize)
    {
        printf ("Error. Wrong size of file\n");
        return 0;
    }
    fclose (fileP);

    printf ("factual size: %d\n", factualSize);

    PrintSymbols (&Str);                               // prints all symbols from the file.txt

    int const isR = StringsCount (&Str);               // counts the number of strings and check if there are '\r'

    Str.stringsP = (String*) calloc (Str.nStrings, sizeof(Strings));

    StringsPointerRead (&Str, isR);                    // puts strings in array

    StrPrint (&Str);                                   // prints unsorted strings

    StrSort (&Str, Strcmp);                            // sorts string by alphabetic order
    SortedStrPrint (&Str, BEGINNING, argv[2]);         // prints sorted strings and put them in file onegin1.txt

    StrSort (&Str, StrcmpEnding);                      // sorts string by alphabetic order of their endings
    SortedStrPrint (&Str, ENDING, argv[3]);            // prints sorted string and put them in file onegin2.txt

    ClearMemory (&Str);
}




