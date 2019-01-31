#pragma once

#include <stdlib.h>

#include "../types/char.h"
#include "../types/integer.h"

static uchar_t * matr(uchar_t * matrix, uchar_t n, int x) {
    uchar_t * res = (uchar_t *)malloc((n - 1) * sizeof(uchar_t));
    for (uchar_t i = 1; i < n; ++i)
        for (uchar_t j = 0, k = 0; j < n; ++j, ++k){
            if (j == x) {
                --k;
                continue;
            }
            res[(i - 1) * (n - 1) + k] = matrix[i * n + j];
        }
    return res;
}

static int get_determinant(uchar_t * matrix, uchar_t n) {
    switch (n) {
        case 1:
            return matrix[0 * n + 0];
        break;
        case 2:
            return matrix[1 * n + 1] * matrix[0 * n + 0] - matrix[0 * n + 1] * matrix[1 * n + 0];
        default: {
            int ans = 0;
            schar_t sig = 1;
            for (int i = 0; i < n; ++i) {
                ans += (sig * matrix[0 * n + i] * get_determinant(matr(matrix, n, i), n - 1));
                sig *= -1;
            }
            return ans;
        }
    }
}

static uchar_t get_inverse_determinant (const INTEGER_TYPE det, const uchar_t length) {
    for (uchar_t i = 0; i < length; ++i)
        if (i * det % length == 1)
            return i;
}
