#include <stdio.h>

#include "crypto/trithemius.h"
#include "crypto/macro.h"

char key (const char ch) {
    return ch * 2 + 1;
}

int main (void) {
    char message[] = "HELLO, WORLD";

    // ENCRYPTION: IHQSX, LFKGA
    trithemius(message, ENCRYPT_MODE, key, message);
    printf("%s\n", message);

    // DECRYPTION: HELLO, WORLD
    trithemius(message, DECRYPT_MODE, key, message);
    printf("%s\n", message);

    return 0;
}
