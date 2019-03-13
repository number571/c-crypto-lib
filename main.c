#include <stdio.h>

#include "crypto/utils/macro/consts.h"
#include "crypto/affine.h"

int main(void) {
	uint8_t message[100] = "HELLO";

	affine(message, ENCRYPT_MODE, 3, 4, message);
	printf("%s\n", message);

	affine(message, DECRYPT_MODE, 3, 4, message);
	printf("%s\n", message);

    return 0;
}
