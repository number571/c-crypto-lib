#include <string.h>

#include "macro.h"
#include "funcs.h"

#undef MAX_LENGTH
#define MAX_LENGTH 100

static char __alpha_polybius[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static unsigned char __sqrt_length_polybius = 6;

static void _encrypt_polybius (char * to, const char * from) {
    for (; *from != END_OF_STRING; ++from) {
        Point pos = get_coordinates(*from, __alpha_polybius, __sqrt_length_polybius);
        *to++ = (pos.x == -1) ? (*from + END_OF_NUMBER) : ((pos.x + 1) * 10 + (pos.y + 1));
    }

    *to = END_OF_NUMBER;
}

static void _decrypt_polybius (char * to, const char * from) {
    for (; *from != END_OF_NUMBER; ++from)
        *to++ = (*from < 11) ? 
            (*from - END_OF_NUMBER) :
                __alpha_polybius[(*from / 10 - 1) * __sqrt_length_polybius + (*from % 10 - 1)];

    *to = END_OF_STRING;
}

extern char set_alpha_polybius (const char * const alpha) {
    const size_t length = strlen(alpha);
    if (length >= MAX_LENGTH)
        return 1;

    unsigned char sqrt = 1;
    while (SQUARE(sqrt) < length)
        ++sqrt;

    if (SQUARE(sqrt) >= MAX_LENGTH) 
        return 2;

    __sqrt_length_polybius = sqrt;
    strcpy(__alpha_polybius, alpha);

    return 0;
}

extern char polybius (char * const to, const char mode, const char * const from) {
    switch (mode) {
        case ENCRYPT_MODE:
            _encrypt_polybius(to, from);
        break;

        case DECRYPT_MODE:
            _decrypt_polybius(to, from);
        break;

        default: return 1;
    }
    return 0;
}