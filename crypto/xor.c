#include "macro.h"

extern void xor (char * to, const char key, const char * from) {
    for (; *from != END_OF_STRING; ++from)
        *to++ = *from ^ key;
    *to = END_OF_STRING;
}