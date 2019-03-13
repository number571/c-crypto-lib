#include <stdio.h>
#include <stdint.h>

#include "crypto/utils/funcs/expmod.h"

int main(void) {
	// Diffie-Hellman protocol
	uint64_t x = 852131, q = 4521101;
	uint64_t a = 274212;
	uint64_t A = _expmod(x, a, q);

	// Alice -> A, x, q -> Bob
	uint64_t b = 142197;
	uint64_t B = _expmod(x, b, q);
	printf("Key: %llu\n", _expmod(A, b, q));

	// Bob -> B -> Alice
	printf("Key: %llu\n", _expmod(B, a, q));

    return 0;
}
