#include "check.h"
#include "string.h"
#include "../s21_string.h"


// -------------------------ТЕСТЫ memchr-----------------------------

// базовый тест
START_TEST(test_s21_memchr_basic) {
    char str[] = "Hello, world!";
    int c = 'o';
    s21_size_t n = 13;

    void *expected = memchr(str, c, n);
    void *actual = s21_memchr(str, c, n);

    ck_assert_ptr_eq(actual, expected); // проверяем равны ли два указателя
}
END_TEST

// граничные случаи
START_TEST(test_s21_memchr_not_found) {
    char str[] = "abcdeg";
    int c = 'z';
    s21_size_t n = 6;

    void *expected = memchr(str, c, n);
    void *actual = s21_memchr(str, c, n);

    ck_assert_ptr_eq(actual, expected); // ожидаем NULL
}
END_TEST

START_TEST(test_s21_memchr_first_byte) {
    char str[] = "xyz";
    int c = 'x';
    s21_size_t n = 1;

    void *expected = memchr(str, c, n);
    void *actual = s21_memchr(str, c, n);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_memchr_middle) {
    char str[] = "abcde";
    int c = 'c';
    s21_size_t n = 5;

    void *expected = memchr(str, c, n);
    void *actual = s21_memchr(str, c, n);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_memchr_repeated_char) {
    char str[] = "banana";
    int c = 'a';
    s21_size_t n = 6;

    void *expected = memchr(str, c, n);
    void *actual = s21_memchr(str, c, n);

    ck_assert_ptr_eq(actual, expected);
}

START_TEST(test_s21_memchr_last_byte) {
    char str[] = "abcdef";
    int c = 'f';
    s21_size_t n = 6;

    void *expected = memchr(str, c, n);
    void *actual = s21_memchr(str, c, n);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_memchr_zero_length) {
    char str[] = "abc";
    int c = 'a';
    s21_size_t n = 0;

    void *expected = memchr(str, c, n);
    void *actual = s21_memchr(str, c, n);

    ck_assert_ptr_eq(actual, expected);  // оба должны вернуть NULL
}
END_TEST

START_TEST(test_s21_memchr_with_null_byte) {
    char data[] = {'a', 'b', '\0', 'c', 'd'};
    int c = '\0';
    s21_size_t n = 5;

    void *expected = memchr(data, c, n);
    void *actual = s21_memchr(data, c, n);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST


// -------------------------ТЕСТЫ memcmp-----------------------------

// базовый тест
START_TEST(test_s21_memcmp_basic) {
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";
    s21_size_t n = 13;

    int expected = memcmp(str1, str2, n);
    int actual = s21_memcmp(str1, str2, n);

    ck_assert_int_eq(actual, expected);
}
END_TEST

// граничные случаи

START_TEST(test_s21_memcmp_diff_first_byte) {
    char str1[] = "abcd";
    char str2[] = "bacd";
    s21_size_t n = 4;

    int expected = memcmp(str1, str2, n);
    int actual = s21_memcmp(str1, str2, n);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_memcmp_diff_middle_byte) {
    char str1[] = "abcdf";
    char str2[] = "abdcf";
    s21_size_t n = 5;

    int expected = memcmp(str1, str2, n);
    int actual = s21_memcmp(str1, str2, n);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_memcmp_diff_last_byte) {
    char str1[] = "abcd";
    char str2[] = "abcf";
    s21_size_t n = 4;

    int expected = memcmp(str1, str2, n);
    int actual = s21_memcmp(str1, str2, n);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_memcmp_zero_length) {
    char str1[] = "abc";
    char str2[] = "xyz";
    s21_size_t n = 0;

    int expected = memcmp(str1, str2, n);
    int actual = s21_memcmp(str1, str2, n);

    ck_assert_int_eq(actual, expected);
}
END_TEST


// -------------------------ТЕСТЫ memcpy-----------------------------

// базовый случай
START_TEST(test_s21_memcpy_basic) {
    char src[] = "For example";
    char dest_expected[50] = {0};
    char dest[50] = {0};
    s21_size_t n = strlen(src) + 1;
    
    memcpy(dest_expected, src, n);
    s21_memcpy(dest, src, n);

    ck_assert_mem_eq(dest, dest_expected, n); // проверяем одинакого скопировалось или нет. в данном случае сравнение указателей не нужно
}

// граничные случаи

START_TEST(test_s21_memcpy_zero_length) {
    char src[] = "unchanged";
    char dest[] = "original";
    char expected[] = "original";

    s21_memcpy(dest, src, 0);
    ck_assert_str_eq(dest, expected); // строка должна не меняться
}
END_TEST

START_TEST(test_s21_memcpy_binary_data) {
    unsigned char src[] = {0xFF, 0x00, 0xAA, 0x55};
    unsigned char dest_expected[4] = {0};
    unsigned char dest_actual[4] = {0};
    s21_size_t n = 4;

    memcpy(dest_expected, src, n);
    s21_memcpy(dest_actual, src, n);

    ck_assert_mem_eq(dest_actual, dest_expected, n);
}
END_TEST

START_TEST(test_s21_memcpy_partial) {
    char src[] = "Hello, world!";
    char dest_expected[50] = {0};
    char dest_actual[50] = {0};
    s21_size_t n = 5;

    memcpy(dest_expected, src, n);
    s21_memcpy(dest_actual, src, n);

    ck_assert_mem_eq(dest_actual, dest_expected, n);
}
END_TEST

START_TEST(test_s21_memcpy_empty) {
    char src[] = "";
    char dest_expected[10] = "test";
    char dest_actual[10] = "test";
    s21_size_t n = 0;

    memcpy(dest_expected, src, n);
    s21_memcpy(dest_actual, src, n);

    ck_assert_mem_eq(dest_actual, dest_expected, 10);
}
END_TEST


// -------------------------ТЕСТЫ memset-----------------------------

// базовый случай
START_TEST(test_s21_memset_basic) {
    char str[] = "Hello, world!";
    char c = 'x';
    s21_size_t n = 5;

    void *expected = memset(str, c, n);
    void *actual = s21_memset(str, c, n);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

// граничные случаи

START_TEST(test_s21_memset_non_ascii) {
    char str[] = "Hello, world!";
    int c = 255; // не ASCII значение
    s21_size_t n = 5;

    void *expected = memset(str, c, n);
    void *actual = s21_memset(str, c, n);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_memset_large_n) {
    char str_expected[100] = "abc";
    char str_actual[100] = "abc";
    int c = 'x';
    s21_size_t n = 100;

    void *expected = memset(str_expected, c, n);
    void *actual = s21_memset(str_actual, c, n);

    ck_assert_ptr_eq(actual, str_actual);
    ck_assert_ptr_eq(expected, str_expected);
    ck_assert_mem_eq(str_actual, str_expected, n);
}
END_TEST

START_TEST(test_s21_memset_empty) {
    char str[] = "";
    int c = 'x';
    s21_size_t n = 0;

    void *expected = memset(str, c, n);
    void *actual = s21_memset(str, c, n);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_memset_zero_fill) {
    char str[] = "Hello, world!";
    int c = 0;
    s21_size_t n = 13;

    void *expected = memset(str, c, n);
    void *actual = s21_memset(str, c, n);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST


// -------------------------ТЕСТЫ strncat-----------------------------

// базовый случай
START_TEST(test_s21_strncat_basic) {
    char src[] = "Hello, world!";
    char dest[100] = "Alex";
    s21_size_t n = 13;

    strncat(dest, src, n);

    char dest2[100] = "Alex";
    s21_strncat(dest2, src, n);

    ck_assert_str_eq(dest2, dest);
}
END_TEST

// граничные случаи

START_TEST(test_s21_strncat_empty_dest) {
    char src[] = "Hello";
    char dest[100] = "";
    char dest2[100] = "";
    s21_size_t n = 5;

    strncat(dest, src, n);
    s21_strncat(dest2, src, n);

    ck_assert_str_eq(dest2, dest);
}
END_TEST

START_TEST(test_s21_strncat_empty_src) {
    char src[] = "";
    char dest[100] = "Test";
    char dest2[100] = "Test";
    s21_size_t n = 5;

    strncat(dest, src, n);
    s21_strncat(dest2, src, n);

    ck_assert_str_eq(dest2, dest);
}
END_TEST

START_TEST(test_s21_strncat_large_n) {
    char src[] = "Hello";
    char dest[100] = "Test";
    char dest2[100] = "Test";
    s21_size_t n = 100;

    strncat(dest, src, n);
    s21_strncat(dest2, src, n);

    ck_assert_str_eq(dest2, dest);
}
END_TEST

START_TEST(test_s21_strncat_with_null_byte) {
    char src[] = "Hel\0lo";
    char dest[100] = "Test";
    char dest2[100] = "Test";
    s21_size_t n = 5;

    strncat(dest, src, n);
    s21_strncat(dest2, src, n);

    ck_assert_str_eq(dest2, dest);
}
END_TEST


// -------------------------ТЕСТЫ strchr------------------------------

// базовый случай
START_TEST(test_s21_strchr_basic) {
    char str[] = "Hello, world!";
    int c = 0;

    char *expected = strchr(str, c);
    char *actual = s21_strchr(str, c);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

// граничные случаи

START_TEST(test_s21_strchr_non_ascii) {
    char str[] = "Hello\200world";
    int c = 128;

    char *expected = strchr(str, c);
    char *actual = s21_strchr(str, c);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strchr_empty_string) {
    char str[] = "";
    int c = 'a';

    char *expected = strchr(str, c);
    char *actual = s21_strchr(str, c);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strchr_not_found) {
    char str[] = "Hello";
    int c = 'z';

    char *expected = strchr(str, c);
    char *actual = s21_strchr(str, c);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strchr_first_char) {
    char str[] = "Hello";
    int c = 'H';

    char *expected = strchr(str, c);
    char *actual = s21_strchr(str, c);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST


// -------------------------ТЕСТЫ strncmp------------------------------

// базовый случай
START_TEST(test_s21_strncmp_basic) {
    char str1[] = "Hello";
    char str2[] = "Hello";
    s21_size_t n = 5;

    int expected = strncmp(str1, str2, n);
    int actual = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(actual, expected);
}
END_TEST

// граничные случаи

START_TEST(test_s21_strncmp_with_null_byte) {
    char str1[] = "Hel\0lo";
    char str2[] = "Hel\0world";
    s21_size_t n = 5;

    int expected = strncmp(str1, str2, n);
    int actual = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strncmp_empty_strings) {
    char str1[] = "";
    char str2[] = "";
    s21_size_t n = 1;

    int expected = strncmp(str1, str2, n);
    int actual = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strncmp_large_n) {
    char str1[] = "abc";
    char str2[] = "abcd";
    s21_size_t n = 100;

    int expected = strncmp(str1, str2, n);
    int actual = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strncmp_partial_match) {
    char str1[] = "abcdef";
    char str2[] = "abcxyz";
    s21_size_t n = 3;

    int expected = strncmp(str1, str2, n);
    int actual = s21_strncmp(str1, str2, n);

    ck_assert_int_eq(actual, expected);
}
END_TEST


// -------------------------ТЕСТЫ strncpy------------------------------

// базовый случай
START_TEST(test_s21_strncpy_basic) {
    char src[] = "Hello";
    char dest_expected[10] = "";
    char dest_actual[10] = "";
    s21_size_t n = 5;

    strncpy(dest_expected, src, n);
    s21_strncpy(dest_actual, src, n);

    ck_assert_mem_eq(dest_actual, dest_expected, n);
    ck_assert_str_eq(dest_actual, dest_expected);
}
END_TEST

// граничные случаи
START_TEST(test_s21_strncpy_zero_padding) {
    char src[] = "Hi";
    char dest_expected[5] = {'X', 'X', 'X', 'X', 'X'};
    char dest_actual[5] = {'X', 'X', 'X', 'X', 'X'};
    s21_size_t n = 5;

    strncpy(dest_expected, src, n);
    s21_strncpy(dest_actual, src, n);

    ck_assert_mem_eq(dest_actual, dest_expected, n);
    ck_assert_str_eq(dest_actual, dest_expected);
}
END_TEST

START_TEST(test_s21_strncpy_empty_src) {
    char src[] = "";
    char dest_expected[10] = "test";
    char dest_actual[10] = "test";
    s21_size_t n = 5;

    strncpy(dest_expected, src, n);
    s21_strncpy(dest_actual, src, n);

    ck_assert_mem_eq(dest_actual, dest_expected, 10);
    ck_assert_str_eq(dest_actual, dest_expected);
}
END_TEST

START_TEST(test_s21_strncpy_large_n) {
    char src[] = "Hi";
    char dest_expected[10] = {0};
    char dest_actual[10] = {0};
    s21_size_t n = 10;

    strncpy(dest_expected, src, n);
    s21_strncpy(dest_actual, src, n);

    ck_assert_mem_eq(dest_actual, dest_expected, 10);
    ck_assert_str_eq(dest_actual, dest_expected);
}
END_TEST

START_TEST(test_s21_strncpy_with_null_byte) {
    char src[] = "Hel\0lo";
    char dest_expected[10] = {0};
    char dest_actual[10] = {0};
    s21_size_t n = 5;

    strncpy(dest_expected, src, n);
    s21_strncpy(dest_actual, src, n);

    ck_assert_mem_eq(dest_actual, dest_expected, n);
    ck_assert_str_eq(dest_actual, dest_expected);
}
END_TEST

START_TEST(test_s21_strncpy_empty_dest) {
    char src[] = "Hello";
    char dest_expected[10] = "";
    char dest_actual[10] = "";
    s21_size_t n = 5;

    strncpy(dest_expected, src, n);
    s21_strncpy(dest_actual, src, n);

    ck_assert_mem_eq(dest_actual, dest_expected, n);
    ck_assert_str_eq(dest_actual, dest_expected);
}
END_TEST


// -------------------------ТЕСТЫ strcspn------------------------------

// базовый случай
START_TEST(test_s21_strcspn_basic) {
    char str[] = "Hello, world!";
    char reject[] = "Hello, world!";

    s21_size_t expected = strcspn(str, reject);
    s21_size_t actual = s21_strcspn(str, reject);

    ck_assert_int_eq(actual, expected);
}
END_TEST

// граничные случаи

START_TEST(test_s21_strcspn_empty_string) {
    char str[] = "";
    char reject[] = "abc";

    s21_size_t expected = strcspn(str, reject);
    s21_size_t actual = s21_strcspn(str, reject);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strcspn_empty_reject) {
    char str[] = "Hello";
    char reject[] = "";

    s21_size_t expected = strcspn(str, reject);
    s21_size_t actual = s21_strcspn(str, reject);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strcspn_no_match) {
    char str[] = "Hello";
    char reject[] = "xyz";

    s21_size_t expected = strcspn(str, reject);
    s21_size_t actual = s21_strcspn(str, reject);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strcspn_non_ascii) {
    char str[] = "Hello\200world";
    char reject[] = "\200";

    s21_size_t expected = strcspn(str, reject);
    s21_size_t actual = s21_strcspn(str, reject);

    ck_assert_int_eq(actual, expected);
}
END_TEST


// -------------------------ТЕСТЫ strerror------------------------------

#ifdef __linux__
#define MAX_ERROR 133
#elif defined __APPLE__
#define MAX_ERROR 106
#endif

START_TEST(test_s21_strerror_basic) {
    for (int errnum = 0; errnum <= MAX_ERROR; errnum++) {
        char *expected = strerror(errnum);
        char *actual = s21_strerror(errnum);

        ck_assert_str_eq(actual, expected);
    }
}
END_TEST

// граничные случаи

START_TEST(test_s21_strerror_negative_errnum) {
    int errnum = -1;

    char *expected = strerror(errnum);
    char *actual = s21_strerror(errnum);

    ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strerror_out_of_range) {
    int errnum = 9999;

    char *expected = strerror(errnum);
    char *actual = s21_strerror(errnum);

    ck_assert_str_eq(actual, expected);
}
END_TEST


// -------------------------ТЕСТЫ strlen------------------------------

// базовый случай
START_TEST(test_s21_strlen_basic) {
    char str[] = "Hello, world!";

    s21_size_t expected = strlen(str);
    s21_size_t actual = s21_strlen(str);

    ck_assert_int_eq(actual, expected);
}
END_TEST

// граничные случаи

START_TEST(test_s21_strlen_empty) {
    char str[] = "";

    s21_size_t expected = strlen(str);
    s21_size_t actual = s21_strlen(str);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strlen_with_null_byte) {
    char str[] = "Hel\0lo";

    s21_size_t expected = strlen(str);
    s21_size_t actual = s21_strlen(str);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strlen_long_string) {
    char str[1000];
    memset(str, 'a', 999);
    str[999] = '\0';

    s21_size_t expected = strlen(str);
    s21_size_t actual = s21_strlen(str);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strlen_non_ascii) {
    char str[] = "Hello\200world";

    s21_size_t expected = strlen(str);
    s21_size_t actual = s21_strlen(str);

    ck_assert_int_eq(actual, expected);
}
END_TEST


// -------------------------ТЕСТЫ strpbrk------------------------------

// базовый случай
START_TEST(test_s21_strpbrk_basic) {
    char str1[] = "Hello, world!";
    char str2[] = "SJJJJ, world!";

    char *expected = strpbrk(str1, str2);
    char *actual = s21_strpbrk(str1, str2);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

// граничные случаи

START_TEST(test_s21_strpbrk_empty_string) {
    char str1[] = "";
    char str2[] = "abc";

    char *expected = strpbrk(str1, str2);
    char *actual = s21_strpbrk(str1, str2);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_empty_accept) {
    char str1[] = "Hello";
    char str2[] = "";

    char *expected = strpbrk(str1, str2);
    char *actual = s21_strpbrk(str1, str2);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_no_match) {
    char str1[] = "Hello";
    char str2[] = "xyz";

    char *expected = strpbrk(str1, str2);
    char *actual = s21_strpbrk(str1, str2);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_non_ascii) {
    char str1[] = "Hello\200world";
    char str2[] = "\200";

    char *expected = strpbrk(str1, str2);
    char *actual = s21_strpbrk(str1, str2);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST


// -------------------------ТЕСТЫ strrchr------------------------------

// базовый случай
START_TEST(test_s21_strrchr_basic) {
    char str[] = "Hello, world!";
    int c = '!';

    char *expected = strrchr(str, c);
    char *actual = s21_strrchr(str, c);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

// граничные случаи

START_TEST(test_s21_strrchr_empty_string) {
    char str[] = "";
    int c = 'a';

    char *expected = strrchr(str, c);
    char *actual = s21_strrchr(str, c);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strrchr_not_found) {
    char str[] = "Hello";
    int c = 'z';

    char *expected = strrchr(str, c);
    char *actual = s21_strrchr(str, c);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strrchr_non_ascii) {
    char str[] = "Hello\200world";
    int c = 128;

    char *expected = strrchr(str, c);
    char *actual = s21_strrchr(str, c);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strrchr_null_byte) {
    char str[] = "Hello";
    int c = '\0';

    char *expected = strrchr(str, c);
    char *actual = s21_strrchr(str, c);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST


// -------------------------ТЕСТЫ strstr-------------------------------

// базовый случай
START_TEST(test_s21_strstr_basic) {
    char haystack[] = "Hello, world!";
    char needle[] = "world";

    char *expected = strstr(haystack, needle);
    char *actual = s21_strstr(haystack, needle);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

// граничные случаи 

START_TEST(test_s21_strstr_empty_haystack) {
    char haystack[] = "";
    char needle[] = "world";

    char *expected = strstr(haystack, needle);
    char *actual = s21_strstr(haystack, needle);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strstr_empty_needle) {
    char haystack[] = "Hello, world!";
    char needle[] = "";

    char *expected = strstr(haystack, needle);
    char *actual = s21_strstr(haystack, needle);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strstr_not_found) {
    char haystack[] = "Hello, world!";
    char needle[] = "xyz";

    char *expected = strstr(haystack, needle);
    char *actual = s21_strstr(haystack, needle);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strstr_start_match) {
    char haystack[] = "Hello, world!";
    char needle[] = "Hello";

    char *expected = strstr(haystack, needle);
    char *actual = s21_strstr(haystack, needle);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strstr_with_null_byte) {
    char haystack[] = "Hel\0lo, world!";
    char needle[] = "Hel";

    char *expected = strstr(haystack, needle);
    char *actual = s21_strstr(haystack, needle);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST


// -------------------------ТЕСТЫ strtok-------------------------------

// базовый случай
START_TEST(test_s21_strtok_basic) {
    char str1[] = "hello,world,test";
    char str2[] = "hello,world,test";
    char delim[] = ",";

    char *expected = strtok(str2, delim);
    char *actual = s21_strtok(str1, delim);

    ck_assert_str_eq(actual, expected);

    // Проверяем последующие токены
    expected = strtok(NULL, delim);
    actual = s21_strtok(S21_NULL, delim);
    ck_assert_str_eq(actual, expected);

    expected = strtok(NULL, delim);
    actual = s21_strtok(S21_NULL, delim);
    ck_assert_str_eq(actual, expected);

    expected = strtok(NULL, delim);
    actual = s21_strtok(S21_NULL, delim);
    ck_assert_ptr_eq(actual, expected); // Оба должны быть NULL
}
END_TEST

// граничные случаи

START_TEST(test_s21_strtok_empty_string) {
    char str1[] = "";
    char str2[] = "";
    char delim[] = ",";

    char *expected = strtok(str2, delim);
    char *actual = s21_strtok(str1, delim);

    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strtok_empty_delim) {
    char str1[] = "hello,world";
    char str2[] = "hello,world";
    char delim[] = "";

    char *expected = strtok(str2, delim);
    char *actual = s21_strtok(str1, delim);

    ck_assert_ptr_eq(actual, str1);     // Проверяем, что s21_strtok возвращает str1
    ck_assert_ptr_eq(expected, str2);   // Проверяем, что strtok возвращает str2
    ck_assert_str_eq(actual, expected); // Проверяем, что содержимое строк одинаково
}
END_TEST

START_TEST(test_s21_strtok_no_delim) {
    char str1[] = "hello";
    char str2[] = "hello";
    char delim[] = ",";

    char *expected = strtok(str2, delim);
    char *actual = s21_strtok(str1, delim);

    ck_assert_str_eq(actual, expected);

    expected = strtok(NULL, delim);
    actual = s21_strtok(S21_NULL, delim);
    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strtok_consecutive_delims) {
    char str1[] = "hello,,world,,test";
    char str2[] = "hello,,world,,test";
    char delim[] = ",";

    char *expected = strtok(str2, delim);
    char *actual = s21_strtok(str1, delim);

    ck_assert_str_eq(actual, expected);

    expected = strtok(NULL, delim);
    actual = s21_strtok(S21_NULL, delim);
    ck_assert_str_eq(actual, expected);

    expected = strtok(NULL, delim);
    actual = s21_strtok(S21_NULL, delim);
    ck_assert_str_eq(actual, expected);

    expected = strtok(NULL, delim);
    actual = s21_strtok(S21_NULL, delim);
    ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strtok_delims_at_ends) {
    char str1[] = ",hello,world,";
    char str2[] = ",hello,world,";
    char delim[] = ",";

    char *expected = strtok(str2, delim);
    char *actual = s21_strtok(str1, delim);

    ck_assert_str_eq(actual, expected);

    expected = strtok(NULL, delim);
    actual = s21_strtok(S21_NULL, delim);
    ck_assert_str_eq(actual, expected);

    expected = strtok(NULL, delim);
    actual = s21_strtok(S21_NULL, delim);
    ck_assert_ptr_eq(actual, expected);
}
END_TEST


// сборка тестов в test-suite
Suite *s21_string_suite(void) {
    Suite *s = suite_create("s21_string");

    // группа тестов memchr
    TCase *tc_memchr = tcase_create("memchr");
    tcase_add_test(tc_memchr, test_s21_memchr_basic);
    tcase_add_test(tc_memchr, test_s21_memchr_not_found);
    tcase_add_test(tc_memchr, test_s21_memchr_first_byte);
    tcase_add_test(tc_memchr, test_s21_memchr_middle);
    tcase_add_test(tc_memchr, test_s21_memchr_repeated_char);
    tcase_add_test(tc_memchr, test_s21_memchr_last_byte);
    tcase_add_test(tc_memchr, test_s21_memchr_zero_length);
    tcase_add_test(tc_memchr, test_s21_memchr_with_null_byte);

    // группа тестов memcmp
    TCase *tc_memcmp = tcase_create("memcmp");
    tcase_add_test(tc_memcmp, test_s21_memcmp_basic);
    tcase_add_test(tc_memcmp, test_s21_memcmp_diff_first_byte);
    tcase_add_test(tc_memcmp, test_s21_memcmp_diff_middle_byte);
    tcase_add_test(tc_memcmp, test_s21_memcmp_diff_last_byte);
    tcase_add_test(tc_memcmp, test_s21_memcmp_zero_length);

    // группа тестов memcpy
    TCase *tc_memcpy = tcase_create("memcpy");
    tcase_add_test(tc_memcpy, test_s21_memcpy_basic);
    tcase_add_test(tc_memcpy, test_s21_memcpy_zero_length);
    tcase_add_test(tc_memcpy, test_s21_memcpy_binary_data);
    tcase_add_test(tc_memcpy, test_s21_memcpy_partial);
    tcase_add_test(tc_memcpy, test_s21_memcpy_empty);

    // группа тестов для memset
    TCase *tc_memset = tcase_create("memset");
    tcase_add_test(tc_memset, test_s21_memset_basic);
    tcase_add_test(tc_memset, test_s21_memset_non_ascii);
    tcase_add_test(tc_memset, test_s21_memset_large_n);
    tcase_add_test(tc_memset, test_s21_memset_empty);
    tcase_add_test(tc_memset, test_s21_memset_zero_fill);

    // группа тестов для strncat
    TCase *tc_strncat = tcase_create("strncat");
    tcase_add_test(tc_strncat, test_s21_strncat_basic);
    tcase_add_test(tc_strncat, test_s21_strncat_empty_dest);
    tcase_add_test(tc_strncat, test_s21_strncat_empty_src);
    tcase_add_test(tc_strncat, test_s21_strncat_large_n);
    tcase_add_test(tc_strncat, test_s21_strncat_with_null_byte);

    // группа тестов для strchr
    TCase *tc_strchr = tcase_create("strchr");
    tcase_add_test(tc_strchr, test_s21_strchr_basic);
    tcase_add_test(tc_strchr, test_s21_strchr_non_ascii);
    tcase_add_test(tc_strchr, test_s21_strchr_empty_string);
    tcase_add_test(tc_strchr, test_s21_strchr_not_found);
    tcase_add_test(tc_strchr, test_s21_strchr_first_char);

    // группа тестов для strncmp
    TCase *tc_strncmp = tcase_create("strncmp");
    tcase_add_test(tc_strncmp, test_s21_strncmp_basic);
    tcase_add_test(tc_strncmp, test_s21_strncmp_with_null_byte);
    tcase_add_test(tc_strncmp, test_s21_strncmp_empty_strings);
    tcase_add_test(tc_strncmp, test_s21_strncmp_large_n);
    tcase_add_test(tc_strncmp, test_s21_strncmp_partial_match);

    // группа тестов для strncpy
    TCase *tc_strncpy = tcase_create("strncpy");
    tcase_add_test(tc_strncpy, test_s21_strncpy_basic);
    tcase_add_test(tc_strncpy, test_s21_strncpy_zero_padding);
    tcase_add_test(tc_strncpy, test_s21_strncpy_empty_src);
    tcase_add_test(tc_strncpy, test_s21_strncpy_large_n);
    tcase_add_test(tc_strncpy, test_s21_strncpy_with_null_byte);
    tcase_add_test(tc_strncpy, test_s21_strncpy_empty_dest);

    // группа тестов для strcspn
    TCase *tc_strcspn = tcase_create("strcspn");
    tcase_add_test(tc_strcspn, test_s21_strcspn_basic);
    tcase_add_test(tc_strcspn, test_s21_strcspn_empty_string);
    tcase_add_test(tc_strcspn, test_s21_strcspn_empty_reject);
    tcase_add_test(tc_strcspn, test_s21_strcspn_no_match);
    tcase_add_test(tc_strcspn, test_s21_strcspn_non_ascii);

    // группа тестов для strerror
    TCase *tc_strerror = tcase_create("strerror");
    tcase_add_test(tc_strerror, test_s21_strerror_basic);
    tcase_add_test(tc_strerror, test_s21_strerror_negative_errnum);
    tcase_add_test(tc_strerror, test_s21_strerror_out_of_range);

    // группа тестов для strlen
    TCase *tc_strlen = tcase_create("strlen");
    tcase_add_test(tc_strlen, test_s21_strlen_basic);
    tcase_add_test(tc_strlen, test_s21_strlen_empty);
    tcase_add_test(tc_strlen, test_s21_strlen_with_null_byte);
    tcase_add_test(tc_strlen, test_s21_strlen_long_string);
    tcase_add_test(tc_strlen, test_s21_strlen_non_ascii);

    // группа тестов для strpbrk
    TCase *tc_strpbrk = tcase_create("strpbrk");
    tcase_add_test(tc_strpbrk, test_s21_strpbrk_basic);
    tcase_add_test(tc_strpbrk, test_s21_strpbrk_empty_string);
    tcase_add_test(tc_strpbrk, test_s21_strpbrk_empty_accept);
    tcase_add_test(tc_strpbrk, test_s21_strpbrk_no_match);
    tcase_add_test(tc_strpbrk, test_s21_strpbrk_non_ascii);

    // группа тестов для strrchr
    TCase *tc_strrchr = tcase_create("strrchr");
    tcase_add_test(tc_strrchr, test_s21_strrchr_basic);
    tcase_add_test(tc_strrchr, test_s21_strrchr_empty_string);
    tcase_add_test(tc_strrchr, test_s21_strrchr_not_found);
    tcase_add_test(tc_strrchr, test_s21_strrchr_non_ascii);
    tcase_add_test(tc_strrchr, test_s21_strrchr_null_byte);

    // группа тестов для strstr
    TCase *tc_strstr = tcase_create("strstr");
    tcase_add_test(tc_strstr, test_s21_strstr_basic);
    tcase_add_test(tc_strstr, test_s21_strstr_empty_haystack);
    tcase_add_test(tc_strstr, test_s21_strstr_empty_needle);
    tcase_add_test(tc_strstr, test_s21_strstr_not_found);
    tcase_add_test(tc_strstr, test_s21_strstr_start_match);
    tcase_add_test(tc_strstr, test_s21_strstr_with_null_byte);

    // группа тестов для strtok
    TCase *tc_strtok = tcase_create("strtok");
    tcase_add_test(tc_strtok, test_s21_strtok_basic);
    tcase_add_test(tc_strtok, test_s21_strtok_empty_string);
    tcase_add_test(tc_strtok, test_s21_strtok_empty_delim);
    tcase_add_test(tc_strtok, test_s21_strtok_no_delim);
    tcase_add_test(tc_strtok, test_s21_strtok_consecutive_delims);
    tcase_add_test(tc_strtok, test_s21_strtok_delims_at_ends);


    // добавление групп тестов (TCase) в набор групп тестов (Suite)
    suite_add_tcase(s, tc_memchr);
    suite_add_tcase(s, tc_memcmp);
    suite_add_tcase(s, tc_memcpy);
    suite_add_tcase(s, tc_memset);
    suite_add_tcase(s, tc_strncat);
    suite_add_tcase(s, tc_strchr);
    suite_add_tcase(s, tc_strncmp);
    suite_add_tcase(s, tc_strncpy);
    suite_add_tcase(s, tc_strcspn);
    suite_add_tcase(s, tc_strerror);
    suite_add_tcase(s, tc_strlen);
    suite_add_tcase(s, tc_strpbrk);
    suite_add_tcase(s, tc_strrchr);
    suite_add_tcase(s, tc_strstr);
    suite_add_tcase(s, tc_strtok);

    return s;
}

int main(void) {
    Suite *s = s21_string_suite();
    SRunner *runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0) ? 0 : 1;
}