# CCryptoLIB
> From ancient to modern Cryptography.
  
#### Example:
  
```c
#include <stdio.h>

#include "crypto/append/macro.h"
#include "crypto/trithemius.h"

char func_key(const char x) {
	return x * 2 + 1;
}

int main(void) {
	char message[100] = "HELLO, WORLD";

	set_alpha_trithemius("ABCDEFGHIJKLMNOPQRSTUVWXYZ, ");

	trithemius(message, ENCRYPT_MODE, func_key, message);
	printf("%s\n", message);

	trithemius(message, DECRYPT_MODE, func_key, message);
	printf("%s\n", message);

	return 0;
}
```
  
  
#### Compile and Run:
  
```
$ gcc main.c crypto/cipher/trithemius.c -o main
$ ./main

IHQSXJMJDIE,
HELLO, WORLD
```
