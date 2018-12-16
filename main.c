#include <stdio.h>

#include "crypto/append/macro.h"
#include "crypto/caesar_wordkey.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	// set_alpha_caesar_wordkey("ABCDEFGHIJKLMNOPQRSTUVWXYZ, ");

	caesar_wordkey(message, ENCRYPT_MODE, 3, "KNOWN", message);
	printf("%s\n", message);

	caesar_wordkey(message, DECRYPT_MODE, 3, "KNOWN", message);
	printf("%s\n", message);

	return 0;
}