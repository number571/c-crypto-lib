#include "../append/macro.h"

extern char xor (char * to, const char key, const char * from) {
    for (; *from != END_OF_STRING; ++from)
        *to++ = *from ^ key;

    *to = END_OF_STRING;
    return 0;
}
