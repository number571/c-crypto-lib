#pragma once

#define SQUARE(x) ((x) * (x))

#define ALIGNH(x, len) ((x % len) ? (x + len - (x % len)) : x)
#define ALIGNL(x, len) ((x % len) ? (x - (x % len)) : x)
