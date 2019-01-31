#pragma once

#include "../types/char.h"

static inline void insertion_sort (uchar_t * to, const size_t length) {
    uchar_t temp;
    for (size_t i = 1; i < length; i++)
        for (size_t j = i; j > 0 && to[j] < to[j-1]; j--) {
            temp = to[j];
            to[j] = to[j-1];
            to[j-1] = temp;
        }
}
