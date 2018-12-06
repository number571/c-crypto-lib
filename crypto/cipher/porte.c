#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../append/macro.h"
#include "../append/types.h"
#include "../append/funcs.h"

static char __alpha_porte[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char __default_char_porte = 'Z';

static unsigned char __length_porte = LEN_ALPHA;

static void _encrypt_porte (short * to, short * const from) {
    const size_t length = get_length('s', from, END_OF_STRING);
    short buffer[length + 2];

    copy(buffer, short, from, END_OF_STRING);

    if (length % 2 != 0) {
        buffer[length] = __default_char_porte;
        buffer[length + 1] = END_OF_STRING;
    }
    
    for (short *p_buffer = buffer; *p_buffer != END_OF_STRING; p_buffer += 2) {
        Point pos = {0, 0};
        bool flag[2] = {false, false};

        for (unsigned char i = 0; i < __length_porte; ++i) {
            if (*p_buffer == __alpha_porte[i]) {
                pos.x = i;
                flag[0] = true;
            }

            if (*(p_buffer + 1) == __alpha_porte[i]) {
                pos.y = i;
                flag[1] = true;
            }

            if (flag[0] && flag[1])
                break;
        }

        *to++ = (pos.x * __length_porte) + pos.y;
    }

    *to = END_OF_NUMBER;
}

static void _decrypt_porte (short * const to, short * from) {
    const size_t length = get_length('s', from, END_OF_NUMBER) * 2;

    short buffer[length + 1];
    short *p_buffer = buffer;

    for (; *from != END_OF_NUMBER; ++from) {
        *p_buffer++ = __alpha_porte[*from / __length_porte];
        *p_buffer++ = __alpha_porte[*from % __length_porte];
    }

    *p_buffer = END_OF_STRING;
    copy(to, short, buffer, END_OF_STRING);
}

extern void set_char_porte (const char ch) {
    __default_char_porte = ch;
}

extern char set_alpha_porte (char * const alpha) {
    const size_t length = strlen(alpha);

    if (length >= MAX_LENGTH)
        return 1;

    __length_porte = (unsigned char)length;
    strcpy(__alpha_porte, alpha);

    return 0;
}

extern void to_string_porte (short * to, const short * from) {
    const size_t length = get_length('s', from, END_OF_NUMBER);

    short buffer[length * 6 + 1];
    short *p_buffer = buffer;

    for (; *from != END_OF_NUMBER; ++from) {
        char temp[7];
        sprintf(temp, "%d ", *from);

        for (char *p_temp = temp; *p_temp != END_OF_STRING; ++p_temp)
            *p_buffer++ = *p_temp;
    }

    *--p_buffer = END_OF_STRING;
    copy(to, short, buffer, END_OF_STRING);
}

extern void to_bytes_porte (short * to, const short * from) {
    char temp[7];
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

extern char porte (
    short * const to,
    const char mode,
    short * const from
) {
    switch (mode) {
        case ENCRYPT_MODE:
            _encrypt_porte(to, from);
        break;
        case DECRYPT_MODE:
            _decrypt_porte(to, from);
        break;
        default: return 1;
    }
    
    return 0;
}
