#include <string.h>
#include <stdio.h>
#include <check.h>

#include "../s21_sprintf.h"

START_TEST(sprintf_d_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 123;
  const char *format = "|%d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MIN;
  const char *format = "|%d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MAX;
  const char *format = "|%+d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MAX;
  const char *format = "|% d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 0;
  const char *format = "|%+d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 5346457;
  const char *format = "|%015d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 6878;
  const char *format = "|%1d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -315;
  const char *format = "|%4d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -14566;
  const char *format = "|%.1d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 56368;
  const char *format = "|%.10d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -67567;
  const char *format = "|%.6d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_12) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 99999;
  const char *format = "|%015.10d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_13) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -131135;
  int y = 12;
  const char *format = "|%.*d|\n";
  int res1 = s21_sprintf(str1, format, y, x);
  int res2 = sprintf(str2, format, y, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_14) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  int y = 12;
  int z = 16;
  const char *format = "|%*.*d|\n";
  int res1 = s21_sprintf(str1, format, z, y, x);
  int res2 = sprintf(str2, format, z, y, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_15) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  int y = 12;
  int z = 16;
  const char *format = "|%-*.*d|\n";
  int res1 = s21_sprintf(str1, format, z, y, x);
  int res2 = sprintf(str2, format, z, y, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_16) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  const char *format = "|%+-020.15d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_17) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  const char *format = "|%+-015.20d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned int x = UINT_MAX;
  const char *format = "|%+-015.20u|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned long int x = ULLONG_MAX;
  const char *format = "|%+ 15.20lu|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ld_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  long int x = LONG_MAX;
  const char *format = "|%+-015.20ld|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ld_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  long int x = LLONG_MIN;
  const char *format = "|%ld|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hd_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  short int x = SHRT_MIN;
  const char *format = "|%+-015.20hd|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_i_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  const char *format = "|%+-015.20i|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = '1';
  const char *format = "|%c|\n";
  int res1 = s21_sprintf(str1, format, c);
  int res2 = sprintf(str2, format, c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = '\0';
  const char *format = "%c\n";
  int res1 = s21_sprintf(str1, format, c);
  int res2 = sprintf(str2, format, c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = 'A';
  const char *format = "|%lc|\n";
  int res1 = s21_sprintf(str1, format, (unsigned long)c);
  int res2 = sprintf(str2, format, (unsigned long)c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_lc_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  wchar_t ch = L'1';
  const char *format = "|%lc|\n";
  int res1 = s21_sprintf(str1, format, (unsigned long)ch);
  int res2 = sprintf(str2, format, (unsigned long)ch);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "\0";
  const char *format = "|%s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  const char *format = "|%s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  const char *format = "|%.2s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  const char *format = "|%.*s|\n";
  int res1 = s21_sprintf(str1, format, 3, str3);
  int res2 = sprintf(str2, format, 3, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  const char *format = "|%10.5s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  const char *format = "|%10.2s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  const char *format = "|%10.0s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  const char *format = "|%-5s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = NULL;
  const char *format = "|%s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = NULL;
  const char *format = "|%10.5s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = NULL;
  const char *format = "|%-10.6s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ls_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  wchar_t *str3 = NULL;
  const char *format = "|%-10.6ls|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ls_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  wchar_t *str3 = L"";
  const char *format = "|%ls|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ls_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  wchar_t *str3 = L"wchar string test";
  const char *format = "|%ls|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_per_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  const char *format = "|%%\n%d|\n";
  int res1 = s21_sprintf(str1, format, 1);
  int res2 = sprintf(str2, format, 1);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_per_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  const char *format = "|%%%%%% %d|\n";
  int res1 = s21_sprintf(str1, format, 1);
  int res2 = sprintf(str2, format, 1);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 123.34634;
  const char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -4534123.34634;
  const char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.0;
  const char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 9123487;
  const char *format = "|%#.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 9123487.635;
  const char *format = "|%.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -69678363.135768656;
  const char *format = "|%15.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -69678363.135768656;
  const char *format = "|%*.*f|\n";
  int res1 = s21_sprintf(str1, format, 20, 2, x);
  int res2 = sprintf(str2, format, 20, 2, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.00005;
  const char *format = "|%+013f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.0;
  const char *format = "|%.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 99934634632.3;
  const char *format = "|%-+08.3f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_12) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -94634.452463574563;
  const char *format = "|%+010f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_13) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.00000000054524;
  const char *format = "|%#+010.f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_14) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.00000000054524;
  const char *format = "|%#+ 30.10f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_15) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 4.1111e-30;
  const char *format = "|%40.35f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_16) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.0;
  const char *format = "|%.2f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 99934634632.3;
  const char *format = "|%-+15.8f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

extern TCase *tcase_s21_sprintf(void);

TCase *tcase_s21_sprintf(void) {
  TCase *tcase = tcase_create("s21_sprintf");
  tcase_add_test(tcase, sprintf_d_1);
  tcase_add_test(tcase, sprintf_d_2);
  tcase_add_test(tcase, sprintf_d_3);
  tcase_add_test(tcase, sprintf_d_4);
  tcase_add_test(tcase, sprintf_d_5);
  tcase_add_test(tcase, sprintf_d_6);
  tcase_add_test(tcase, sprintf_d_7);
  tcase_add_test(tcase, sprintf_d_8);
  tcase_add_test(tcase, sprintf_d_9);
  tcase_add_test(tcase, sprintf_d_10);
  tcase_add_test(tcase, sprintf_d_11);
  tcase_add_test(tcase, sprintf_d_12);
  tcase_add_test(tcase, sprintf_d_13);
  tcase_add_test(tcase, sprintf_d_14);
  tcase_add_test(tcase, sprintf_d_15);
  tcase_add_test(tcase, sprintf_d_16);
  tcase_add_test(tcase, sprintf_d_17);
  tcase_add_test(tcase, sprintf_u_1);
  tcase_add_test(tcase, sprintf_u_2);
  tcase_add_test(tcase, sprintf_ld_1);
  tcase_add_test(tcase, sprintf_ld_2);
  tcase_add_test(tcase, sprintf_hd_1);
  tcase_add_test(tcase, sprintf_i_1);
  tcase_add_test(tcase, sprintf_c_1);
  tcase_add_test(tcase, sprintf_c_2);
  tcase_add_test(tcase, sprintf_c_3);
  tcase_add_test(tcase, sprintf_lc_1);
  tcase_add_test(tcase, sprintf_s_1);
  tcase_add_test(tcase, sprintf_s_2);
  tcase_add_test(tcase, sprintf_s_3);
  tcase_add_test(tcase, sprintf_s_4);
  tcase_add_test(tcase, sprintf_s_5);
  tcase_add_test(tcase, sprintf_s_6);
  tcase_add_test(tcase, sprintf_s_7);
  tcase_add_test(tcase, sprintf_s_8);
  tcase_add_test(tcase, sprintf_s_9);
  tcase_add_test(tcase, sprintf_s_10);
  tcase_add_test(tcase, sprintf_s_11);
  tcase_add_test(tcase, sprintf_ls_1);
  tcase_add_test(tcase, sprintf_ls_2);
  tcase_add_test(tcase, sprintf_ls_3);
  tcase_add_test(tcase, sprintf_per_1);
  tcase_add_test(tcase, sprintf_per_2);
  tcase_add_test(tcase, sprintf_f_1);
  tcase_add_test(tcase, sprintf_f_2);
  tcase_add_test(tcase, sprintf_f_3);
  tcase_add_test(tcase, sprintf_f_4);
  tcase_add_test(tcase, sprintf_f_5);
  tcase_add_test(tcase, sprintf_f_6);
  tcase_add_test(tcase, sprintf_f_7);
  tcase_add_test(tcase, sprintf_f_8);
  tcase_add_test(tcase, sprintf_f_9);
  tcase_add_test(tcase, sprintf_f_11);
  tcase_add_test(tcase, sprintf_f_12);
  tcase_add_test(tcase, sprintf_f_13);
  tcase_add_test(tcase, sprintf_f_14);
  tcase_add_test(tcase, sprintf_f_15);
  tcase_add_test(tcase, sprintf_f_16);
  tcase_add_test(tcase, sprintf_f_10);

  return tcase;
}

Suite *sscanf_sprintf_suite(void) {
  Suite *s = suite_create("Sscanf sprintf");

  suite_add_tcase(s, tcase_s21_sprintf());

  return s;
}

int main(void) {
  int failed_count = 0;
  Suite *s = sscanf_sprintf_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}