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

START_TEST(test_s21_memchr_null_pointer) {
    ck_assert_ptr_eq(s21_memchr(S21_NULL, 'a', 5), S21_NULL);
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

START_TEST(test_s21_memcmp_null_pointers) {
    char str[] = "test";
    ck_assert_int_eq(s21_memcmp(S21_NULL, S21_NULL, 5), 0);
    ck_assert_int_eq(s21_memcmp(S21_NULL, str, 5), -1);
    ck_assert_int_eq(s21_memcmp(str, S21_NULL, 5), 1);
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

START_TEST(test_s21_memcpy_null_pointers) {
    char src[] = "test";
    ck_assert_ptr_eq(s21_memcpy(S21_NULL, src, 5), S21_NULL);
    ck_assert_ptr_eq(s21_memcpy(src, S21_NULL, 5), S21_NULL);
    ck_assert_ptr_eq(s21_memcpy(S21_NULL, S21_NULL, 5), S21_NULL);
}
END_TEST

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


// -------------------------ТЕСТЫ strlen------------------------------

// базовый случай
START_TEST(test_s21_strlen_basic) {
    char str[] = "Hello, world!";

    s21_size_t expected = strlen(str);
    s21_size_t actual = s21_strlen(str);

    ck_assert_int_eq(actual, expected);
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
    tcase_add_test(tc_memchr, test_s21_memchr_null_pointer);

    // группа тестов memcmp
    TCase *tc_memcmp = tcase_create("memcmp");
    tcase_add_test(tc_memcmp, test_s21_memcmp_basic);
    tcase_add_test(tc_memcmp, test_s21_memcmp_diff_first_byte);
    tcase_add_test(tc_memcmp, test_s21_memcmp_diff_middle_byte);
    tcase_add_test(tc_memcmp, test_s21_memcmp_diff_last_byte);
    tcase_add_test(tc_memcmp, test_s21_memcmp_zero_length);
    tcase_add_test(tc_memcmp, test_s21_memcmp_null_pointers);

    // группа тестов memcpy
    TCase *tc_memcpy = tcase_create("memcpy");
    tcase_add_test(tc_memcpy, test_s21_memcpy_basic);
    tcase_add_test(tc_memcpy, test_s21_memcpy_null_pointers);
    tcase_add_test(tc_memcpy, test_s21_memcpy_zero_length);

    // группа тестов для memset
    TCase *tc_memset = tcase_create("memset");
    tcase_add_test(tc_memset, test_s21_memset_basic);

    // группа тестов для strncat
    TCase *tc_strncat = tcase_create("strncat");
    tcase_add_test(tc_strncat, test_s21_strncat_basic);

    // группа тестов для strlen
    TCase *tc_strlen = tcase_create("strlen");
    tcase_add_test(tc_strlen, test_s21_strlen_basic);


    // добавление групп тестов (TCase) в набор групп тестов (Suite)
    suite_add_tcase(s, tc_memchr);
    suite_add_tcase(s, tc_memcmp);
    suite_add_tcase(s, tc_memcpy);
    suite_add_tcase(s, tc_memset);
    suite_add_tcase(s, tc_strncat);
    suite_add_tcase(s, tc_strlen);

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