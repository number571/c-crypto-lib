#include <string.h>

#include "macro.h"

static char __alpha_one_substitute[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUWXYZ";
static char __alpha_two_substitute[MAX_LENGTH] = "zyxwutsrqponmlkjihgfedcba";

static char _char_substitute (const char * const to, const char ch, char * const from) {
    for (char *p = from; *p != END_OF_STRING; ++p)
        if (ch == *p)
            return to[p - from];
    return ch;
}

extern char set_alpha_substitute (char * const alph1, char * const alph2) {
    const size_t length = strlen(alph1);

    if (length >= MAX_LENGTH)
        return 1;

    if (length != strlen(alph2))
        return 2;

    unsigned char i = 0;

    while (i < length) {
        __alpha_one_substitute[i] = alph1[i];
        __alpha_two_substitute[i] = alph2[i];
        ++i;
    }

    __alpha_one_substitute[i] = __alpha_two_substitute[i] = END_OF_STRING;

    return 0;
}

extern char substitute (
    char * to, 
    const char mode, 
    const char * from
) {
    if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
        return 1;

    const char * const to_vector = (mode == ENCRYPT_MODE) ? __alpha_two_substitute : __alpha_one_substitute;
    char * const from_vector = (mode == DECRYPT_MODE) ? __alpha_two_substitute : __alpha_one_substitute;

    for (; *from != END_OF_STRING; ++from)
        *to++ = _char_substitute(to_vector, *from, from_vector);
    
    *to = END_OF_STRING;

    return 0;
}