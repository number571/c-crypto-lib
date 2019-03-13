#pragma once

#define SHIFTR(Type, from, len) \
	({ \
	    Type temp = from[len-1]; \
	    for (size_t i = len-1; i > 0; i--) \
	        from[i] = from[i-1]; \
	    from[0] = temp; \
	})

#define SHIFTL(Type, from, len) \
	({ \
		Type temp = from[0]; \
		size_t i = 1; \
	    while (i < len) { \
	        from[i-1] = from[i]; \
	        ++i; \
	    } \
	    from[i-1] = temp; \
	})
