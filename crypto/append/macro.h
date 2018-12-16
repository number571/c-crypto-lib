#pragma once

#define ENCRYPT_MODE  1
#define DECRYPT_MODE -1

#define END_OF_LINE   '\n'
#define END_OF_STRING '\0'
#define END_OF_NUMBER -128

#define LEN_ALPHA  26
#define MAX_LENGTH 127

#define SQUARE(x) ((x) * (x))

#define copy(to, Type, from, end) \
	({ \
		Type *p = from; \
		while (*p != end) { \
			to[p - from] = *p; \
			++p; \
		} \
		to[p - from] = end; \
	})

#define shiftr(Type, from, len) \
	({ \
	    Type temp = from[len-1]; \
	    for (size_t i = len-1; i > 0; i--) \
	        from[i] = from[i-1]; \
	    from[0] = temp; \
	})

#define shiftl(Type, from, len) \
	({ \
		Type temp = from[0]; \
		size_t i = 1; \
	    while (i < len) { \
	        from[i-1] = from[i]; \
	        ++i; \
	    } \
	    from[i-1] = temp; \
	})

#define print_nums(Type, from) \
	({ \
		for (Type *p = from; *p != END_OF_NUMBER; ++p) \
			printf("%d ", *p); \
	})

#define println_nums(Type, from) \
	({ \
		print_nums(Type, from); \
		putchar('\n'); \
	})

#define print_chars(Type, from) \
	({ \
		for (Type *p = from; *p != END_OF_STRING; ++p) \
			printf("%c", *p); \
	})

#define println_chars(Type, from) \
	({ \
		print_chars(Type, from); \
		putchar('\n'); \
	})

#define print_byte(from) \
	({ \
		unsigned char *p = &from; \
		Byte x = {.byte = *p}; \
		printf("%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu ", \
			x.bit._7, x.bit._6, x.bit._5, x.bit._4, \
			x.bit._3, x.bit._2, x.bit._1, x.bit._0); \
	}) \

#define println_byte(from) \
	({ \
		print_byte(from); \
		putchar('\n'); \
	})

#define print_bytes(from) \
	({ \
		for (char *p = from; *p != END_OF_NUMBER; ++p) { \
			Byte x = {.byte = *p}; \
			printf("%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu ", \
				x.bit._7, x.bit._6, x.bit._5, x.bit._4, \
				x.bit._3, x.bit._2, x.bit._1, x.bit._0); \
		} \
	})

#define println_bytes(from) \
	({ \
		print_bytes(from); \
		putchar('\n'); \
	})
