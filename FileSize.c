#include "FileSize.h"

int FileSize (FILE* const fPointer, int const startPosition)
{
    assert (fPointer != NULL);
    size_t len = 0;

    rewind (fPointer);
    fseek (fPointer, 0, SEEK_END);
    len = (size_t) ftell (fPointer);

    fseek (fPointer, startPosition, SEEK_SET);

    return len;
}