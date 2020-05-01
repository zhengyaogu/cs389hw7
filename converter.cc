/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

#include <stdlib.h>
#include <string.h>


quote_t qtoi(char* qt)
{
    quote_t qt_num = 0;
    for (unsigned i = 0; i < strlen(qt); i++)
    {
        qt_num = qt_num * 10 + qt[i] - 48; 
    }
    return qt_num;
}


void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    nums[i] = qtoi(lines[i]);
  }
}
