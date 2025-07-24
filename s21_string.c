#include "s21_string.h"

// реализация функции s21_memchr
void *s21_memchr(const void *str, int c, s21_size_t n) {
    const unsigned char *p = (const unsigned char *)str;
    for (s21_size_t i = 0; i < n; i++) {
        if (p[i] == (unsigned char) c) {
            return (void *)(p + i);
        }
    }
    return S21_NULL;
}