#include <string.h>

#include "../append/macro.h"

static char __alpha_one_substitute[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUWXYZ";
static char __alpha_two_substitute[MAX_LENGTH] = "zyxwutsrqponmlkjihgfedcba";

static char _char_substitute (const char * const to, const char ch, char * const from) {
    for (char *p_from = from; *p_from != END_OF_STRING; ++p_from)
        if (ch == *p_from)
            return to[p_from - from];

    return ch;
}

extern char set_alpha_substitute (const char * const alph1, const char * const alph2) {
    const size_t length = strlen(alph1);

    if (length >= MAX_LENGTH)
        return 1;

    if (length != strlen(alph2))
        return 2;

    strcpy(__alpha_one_substitute, alph1);
    strcpy(__alpha_two_substitute, alph2);

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
