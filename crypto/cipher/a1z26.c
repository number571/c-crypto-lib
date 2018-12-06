#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../append/macro.h"
#include "../append/types.h"

#define END(x) ((mode == x) ? (END_OF_STRING) : (END_OF_NUMBER))

extern void to_string_a1z26 (char * to, const char * from) {
    const size_t length = strlen(from);

    char buffer[length * 4 + 1];
    char *p_buffer = buffer;

    for (; *from != END_OF_NUMBER; ++from) {
        char temp[5];
        sprintf(temp, "%d ", *from);

        for (char *p_temp = temp; *p_temp != END_OF_STRING; ++p_temp)
            *p_buffer++ = *p_temp;
    }

    *--p_buffer = END_OF_STRING;
    strcpy(to, buffer);
}

extern void to_bytes_a1z26 (char * to, const char * from) {
    char temp[5];
    char *p_temp = temp;

    for (; *from != END_OF_STRING; ++from) {
        if (*from == ' ') {
            *p_temp = END_OF_STRING;
            *to++ = atoi(temp);
            p_temp = temp;
        } else
            *p_temp++ = *from;
    }
    
    *p_temp = END_OF_STRING;
    *to++ = atoi(temp);
    
    *to = END_OF_NUMBER;
}

extern char a1z26 (char * to, const char mode, const char * from) {
    if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
        return 1;

    char buffer[2];

    switch (mode) {
        case ENCRYPT_MODE:
            buffer[0] = 'A';
            buffer[1] = 'Z';
        break;
        case DECRYPT_MODE:
            buffer[0] = 1;
            buffer[1] = 26;
        break;
    }

    for (; *from != END(ENCRYPT_MODE); ++from)
        if (buffer[0] <= *from && *from <= buffer[1])
            *to++ = *from + (-mode * 'A') + mode;
        else
            *to++ = *from + (mode * END_OF_NUMBER);

    *to = END(DECRYPT_MODE);
    
    return 0;
}
