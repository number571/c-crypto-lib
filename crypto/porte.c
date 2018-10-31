#include <string.h>

#include "macro.h"
#include "types.h"

static char __alpha_porte[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char __default_char_porte = 'Z';

static unsigned char __length_porte = LEN_ALPHA;

static unsigned int _get_length (short * const from, const char end) {
    short *p = from;
    while (*p != end)
        ++p;
    return p - from;
}

static void _encrypt_porte (short * to, short * const from) {
    const size_t length = _get_length(from, END_OF_STRING);
    short buffer[length + 2];

    copy(short, buffer, from, END_OF_STRING);

    if (length % 2 != 0) {
        buffer[length] = __default_char_porte;
        buffer[length + 1] = END_OF_STRING;
    }
    
    for (short *p = buffer; *p != END_OF_STRING; p += 2) {
        Point pos = {0, 0};
        bool flag[2] = {false, false};

        for (unsigned char i = 0; i < __length_porte; ++i) {
            if (*p == __alpha_porte[i]) {
                pos.x = i;
                flag[0] = true;
            }

            if (*(p + 1) == __alpha_porte[i]) {
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
    const size_t length = _get_length(from, END_OF_NUMBER) * 2;

    short buffer[length + 1];
    short *p = buffer;

    for (; *from != END_OF_NUMBER; ++from) {
        *p++ = __alpha_porte[*from / __length_porte];
        *p++ = __alpha_porte[*from % __length_porte];
    }

    *p = END_OF_STRING;
    copy(short, to, buffer, END_OF_STRING);
}

extern void set_char_porte (const char ch) {
    __default_char_porte = ch;
}

extern char set_alpha_porte (char * const alpha) {
    const size_t length = strlen(alpha);
    if (length >= MAX_LENGTH)
        return 1;

    __length_porte = (unsigned char)length;
    copy(char, __alpha_porte, alpha, END_OF_STRING);

    return 0;
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