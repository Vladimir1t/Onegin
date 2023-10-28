#include "FileReadingCheck.h"

void FileReadingCheck (FILE* const fileP, size_t const factualSize)
{
    assert (fileP != NULL);

    size_t size = 0;
    fseek (fileP, 0, SEEK_SET);    // rewind(fileP);
    while (fgetc (fileP) != EOF)   //second variant of reading
        size++;
    printf ("size: %d\n", size);
    rewind (fileP);

    printf ("factual size: %d\n", factualSize);

    if (factualSize != size)
        ("Error. some symbols didn't be read");
    assert (factualSize == size);
}
