#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/funcs/length.h"

#include "../utils/macro/consts.h"

extern void to_string_a1z26 (uint8_t * const to, const int8_t * from) {
    const size_t length = _length('c', from, END_OF_NUMBER);

    uint8_t buffer[length * 4 + 1];
    uint8_t *p_buffer = buffer;

    for (; *from != END_OF_NUMBER; ++from) {
        uint8_t temp[5];
        sprintf(temp, "%d", *from);

        for (uint8_t *p_temp = temp; *p_temp != END_OF_STRING; ++p_temp)
            *p_buffer++ = *p_temp;

        *p_buffer++ = SPACE;
    }

    *--p_buffer = END_OF_STRING;
    strcpy(to, buffer);
}

extern void to_bytes_a1z26 (int8_t * to, const uint8_t * from) {
    uint8_t temp[5];
    uint8_t *p_temp = temp;

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

extern char a1z26 (
    int8_t * to, 
    const int8_t mode, 
    const int8_t * from
) {
    if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
        return 1;

    uint8_t buffer[2];

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

    const int8_t end_from = (mode == ENCRYPT_MODE) ? (END_OF_STRING) : (END_OF_NUMBER);
    const int8_t end_to = (mode == ENCRYPT_MODE) ? (END_OF_NUMBER) : (END_OF_STRING);

    for (; *from != end_from; ++from)
        if (buffer[0] <= *from && *from <= buffer[1])
             *to++ = *from + (-mode * 'A') + mode;
        else *to++ = *from;

    *to = end_to;

    return 0;
}
