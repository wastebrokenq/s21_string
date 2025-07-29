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


// -------------------------ТЕСТЫ strncpy------------------------------

// базовый случай
START_TEST(test_s21_strncpy_basic) {
    char src[] = "Hello";

    char dest_expected[10] = "";
    char dest_actual[10] = "";

    s21_size_t n = 5;

    char *expected = strncpy(dest_expected, src, n);
    char *actual = s21_strncpy(dest_actual, src, n);

    ck_assert_mem_eq(actual, expected, n);
    ck_assert_str_eq(actual, expected);
}
END_TEST

// граничные случаи

START_TEST(test_s21_strncpy_zero_padding) {
    char src[] = "Hi";

    char dest_expected[5] = {'X', 'X', 'X', 'X', 'X'};
    char dest_actual[5] = {'X', 'X', 'X', 'X', 'X'};

    s21_size_t n = 5;

    char *expected = strncpy(dest_expected, src, n);
    char *actual = s21_strncpy(dest_actual, src, n);

    ck_assert_mem_eq(actual, expected, n);
    ck_assert_str_eq(actual, expected);
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


// -------------------------ТЕСТЫ strlen------------------------------

// базовый случай
START_TEST(test_s21_strlen_basic) {
    char str[] = "Hello, world!";

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

    // группа тестов для memset
    TCase *tc_memset = tcase_create("memset");
    tcase_add_test(tc_memset, test_s21_memset_basic);

    // группа тестов для strncat
    TCase *tc_strncat = tcase_create("strncat");
    tcase_add_test(tc_strncat, test_s21_strncat_basic);

    // группа тестов для strchr
    TCase *tc_strchr = tcase_create("strchr");
    tcase_add_test(tc_strchr, test_s21_strchr_basic);

    // группа тестов для strncmp
    TCase *tc_strncmp = tcase_create("strncmp");
    tcase_add_test(tc_strncmp, test_s21_strncmp_basic);

    // группа тестов для strncpy
    TCase *tc_strncpy = tcase_create("strncpy");
    tcase_add_test(tc_strncpy, test_s21_strncpy_basic);
    tcase_add_test(tc_strncpy, test_s21_strncpy_zero_padding);

    // группа тестов для strcspn
    TCase *tc_strcspn = tcase_create("strcspn");
    tcase_add_test(tc_strcspn, test_s21_strcspn_basic);

    // группа тестов для strerror
    TCase *tc_strerror = tcase_create("strerror");
    tcase_add_test(tc_strerror, test_s21_strerror_basic);

    // группа тестов для strlen
    TCase *tc_strlen = tcase_create("strlen");
    tcase_add_test(tc_strlen, test_s21_strlen_basic);

    // группа тестов для strpbrk
    TCase *tc_strpbrk = tcase_create("strpbrk");
    tcase_add_test(tc_strpbrk, test_s21_strpbrk_basic);

    // группа тестов для strrchr
    TCase *tc_strrchr = tcase_create("strrchr");
    tcase_add_test(tc_strrchr, test_s21_strrchr_basic);

    // группа тестов для strstr
    TCase *tc_strstr = tcase_create("strstr");
    tcase_add_test(tc_strstr, test_s21_strstr_basic);

    // группа тестов для strtok
    TCase *tc_strtok = tcase_create("strtok");
    tcase_add_test(tc_strtok, test_s21_strtok_basic);


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