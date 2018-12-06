#include <stdio.h>
#include <string.h>
#include <math.h>

extern void variants (const char * const str, const unsigned char size) {
    const size_t length = strlen(str);
    for (size_t x = 0; x < pow(length, size); ++x) {
        for (int y = size - 1; y >= 0; --y)
           putchar(str[(unsigned char) (x / pow(length, y)) % length]);
        putchar('\n');
    }
}
