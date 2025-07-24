#include "check.h"
#include "string.h"
#include "../s21_string.h"

START_TEST(test_s21_memchr_basic) {
    char str[] = "Hello, world!";
    int c = 'o';
    s21_size_t n = 13;

    void *expected = memchr(str, c, n);
    void *actual = s21_memchr(str, c, n);

    ck_assert_ptr_eq(actual, expected); // проверяем равны ли два указателя
}
END_TEST

// сборка тестов в test-suite
Suite *s21_string_suite(void) {
    Suite *s = suite_create("s21_string");

    TCase *tc_memchr = tcase_create("memchr");
    tcase_add_test(tc_memchr, test_s21_memchr_basic);

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