/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

#include <stdlib.h>
#include <string.h>


quote_t qtoi(char* qt)
{
    __builtin_prefetch(qt, 0, 0);
    quote_t qt_num = 0;
    while (*qt)
    {
        qt_num = qt_num * 10 + *qt++ - 48;
    }
    return qt_num;
}


void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
    char** l = lines;
    quote_t* q = nums;
    for (unsigned i = 0; i < nlines; i++) {
        __builtin_prefetch(l, 0, 0);
        (*q++) = qtoi(*l++);
        //__builtin___clear_cache(q, q+1);
    }
}
