CC = gcc
CFLAGS_BEFORE = -Werror -Wextra -Wall -std=c11 -fprofile-arcs -ftest-coverage
CFLAGS_AFTER = -lcheck -lpthread -lm

FILENAME = s21_string.c tests/test_s21_string.c

.PHONY: all test report full

all: test_s21_string

test_s21_string: $(FILENAME)
	$(CC) $(CFLAGS_BEFORE) $(FILENAME) -o test_s21_string $(CFLAGS_AFTER)

test: test_s21_string
	./test_s21_string

clean:
	rm -rf test_s21_string *.gcno *.gcda *.info report/*

report: test
	lcov -t "gcov_report" -o coverage.info -c -d .
	genhtml coverage.info -o report/
	open report/index.html

full: report