#include <string.h>

#include "macro.h"

static char __alpha_trithemius[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static unsigned char __length_trithemius = LEN_ALPHA;

static char _char_trithemius (const char mode, char key, const char ch) {
    const unsigned char length = __length_trithemius;
    
    for (char *p = __alpha_trithemius; *p != END_OF_STRING; ++p)
        if (*p == ch) {
            key = ( (key < 0) ? (length + (key % length)) : (key % length) ) * mode;
            return __alpha_trithemius[(p - __alpha_trithemius + key + length) % length];
        }
    
    return ch;
}

extern char set_alpha_trithemius (const char * const alpha) {
    const size_t length = strlen(alpha);
    if (length >= MAX_LENGTH)
        return 1;

    __length_trithemius = (unsigned char)length;
    strcpy(__alpha_trithemius, alpha);

    return 0;
}

extern char trithemius (
    char * const to, 
    const char mode, 
    char (* const key) (const char x), 
    char * const from
) {
    if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
        return 1;

    char *p = NULL;
    
    for (p = from; *p != END_OF_STRING; ++p)
        to[p - from] = _char_trithemius(mode, key((char) (p - from)), *p);
            
    to[p - from] = END_OF_STRING;

    return 0;
}
