#include "FileMeasure.h"

int FileMeasure (FILE* const fPointer)
{
    assert (fPointer != NULL);
    size_t len = 0;
    fseek (fPointer, 0, SEEK_END);
    len = (size_t) ftell (fPointer);

    rewind (fPointer);

    return len;
}
