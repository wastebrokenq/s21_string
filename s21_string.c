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

// реализация функции s21_memset
void *s21_memset(void *str, int c, s21_size_t n) {
    if (str == S21_NULL) return S21_NULL;
    unsigned char *p = (unsigned char *)str;
    for (s21_size_t i = 0; i < n; i++) {
        p[i] = (unsigned char)c;
    }
    return str;
}

// реализация функции s21_strncat
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    if (dest == S21_NULL || src == S21_NULL) return S21_NULL;
    s21_size_t dest_last_index = s21_strlen(dest);
    s21_size_t copied = 0;
    for (s21_size_t i = 0; i < n && src[i] != '\0'; i++) {
        dest[dest_last_index + i] = src[i];
        copied++;
    }
    dest[dest_last_index + copied] = '\0';
    return dest;
}

// реализация функции s21_strchr
char *s21_strchr(const char *str, int c) {
    if (str == S21_NULL) return S21_NULL;
    s21_size_t length = s21_strlen(str);
    for (s21_size_t i = 0; i <= length; i++) {
        if (str[i] == (char)c) return (char *)(str + i);
    }
    return S21_NULL;
}

// реализация функции s21_strncmp
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    if (str1 == S21_NULL || str2 == S21_NULL) return 0;
    unsigned char *p1 = (unsigned char *)str1;
    unsigned char *p2 = (unsigned char *)str2;
    for (s21_size_t i = 0; (i < n) && (p1[i] != '\0' || p2[i] != '\0'); i++) {
        if (p1[i] != p2[i]) {
            return p1[i] - p2[i];
        }
    }
    return 0;
}

// реализация функции s21_strncpy
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    if (dest == S21_NULL || src == S21_NULL) return S21_NULL;
    s21_size_t i = 0;
    for (; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

// реализация функции s21_strcspn
s21_size_t s21_strcspn(const char *str, const char *reject) {
    if (str == S21_NULL || reject == S21_NULL) return 0;
    s21_size_t i = 0;
    while (str[i] != '\0') {
        s21_size_t j = 0;
        while (reject[j] != '\0') {
            if (str[i] == reject[j]) {
                return i;
            }
            j++;
        }
        i++;
    }
    return i;
}

// реализация функции s21_strlen
s21_size_t s21_strlen(const char *str) {
    if (str == S21_NULL) return 0;
    s21_size_t n = 0;
    while (str[n] != '\0') {
        n++;
    }
    return n;
}