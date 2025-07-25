#include "s21_string.h"

// реализация функции s21_memchr
void *s21_memchr(const void *str, int c, s21_size_t n) {
    if (str == S21_NULL) return S21_NULL;
    const unsigned char *p = (const unsigned char *)str;
    for (s21_size_t i = 0; i < n; i++) {
        if (p[i] == (unsigned char) c) {
            return (void *)(p + i);
        }
    }
    return S21_NULL;
}

// реализация функции s21_memcmp
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    if (str1 == S21_NULL || str2 == S21_NULL) {
        return (str1 == str2) ? 0 : (str1 == S21_NULL ? -1 : 1);
    }
    const unsigned char *p1 = (const unsigned char *)str1;
    const unsigned char *p2 = (const unsigned char *)str2;
    for (s21_size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return (int)p1[i] - (int)p2[i];
        }
    }
    return 0;
}

// реализация функции s21_memcpy
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    if (dest == S21_NULL || src == S21_NULL) return S21_NULL;
    unsigned char *p1 = (unsigned char *)dest;
    const unsigned char *p2 = (const unsigned char *)src;
    for (s21_size_t i = 0; i < n; i++) {
        p1[i] = p2[i];
    }
    return dest;
}