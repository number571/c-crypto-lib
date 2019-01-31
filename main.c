#include <stdio.h>

#include "crypto/append/macro/consts.h"
#include "crypto/hill.h"

int main(void) {
    char message[100] = "HELLO, WORLD";
    
    set_alpha_hill("ABCDEFGHIJKLMNOPQRSTUVWXYZ,. ");

    hill(message, ENCRYPT_MODE, "QWERTYUIO", message);
    printf("%s\n", message);

    hill(message, DECRYPT_MODE, "QWERTYUIO", message);
    printf("%s\n", message);

    return 0;
}
