#pragma once

#include <stdint.h>
#include <stdlib.h>

#include "../types/integer.h"

static uint8_t * __matr (uint8_t * matrix, uint8_t n, int x) {
    uint8_t * res = (uint8_t *)malloc((n - 1) * sizeof(uint8_t));
    for (uint8_t i = 1; i < n; ++i)
        for (uint8_t j = 0, k = 0; j < n; ++j, ++k){
            if (j == x) {
                --k;
                continue;
            }
            res[(i - 1) * (n - 1) + k] = matrix[i * n + j];
        }
    return res;
}

static int _determinant (uint8_t * matrix, uint8_t n) {
    switch (n) {
        case 1:
            return matrix[0 * n + 0];
        break;
        case 2:
            return matrix[1 * n + 1] * matrix[0 * n + 0] - matrix[0 * n + 1] * matrix[1 * n + 0];
        default: {
            int ans = 0;
            int8_t sig = 1;
            for (int i = 0; i < n; ++i) {
                ans += (sig * matrix[0 * n + i] * _determinant(__matr(matrix, n, i), n - 1));
                sig *= -1;
            }
            return ans;
        }
    }
}

static uint8_t _inverse_determinant (const __INTEGER__ det, const uint8_t length) {
    for (uint8_t i = 0; i < length; ++i)
        if (i * det % length == 1)
            return i;
}
