CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -fprofile-arcs -ftest-coverage
LDLIBS = -lcheck -lm -lpthread

# Определяем систему
UNAME_S := $(shell uname -s)

# Добавляем -lsubunit для Linux
ifeq ($(UNAME_S),Linux)
    LDLIBS += -lsubunit
endif

SOURCES = s21_string.c s21_sprintf.c
OBJECTS = $(SOURCES:.c=.o)
LIBRARY = s21_string.a
TEST_DIR = tests
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
TEST_EXECUTABLES = $(patsubst %.c,%,$(TEST_SOURCES))
ALL_SRC = $(wildcard *.c */*.c *.h */*.h)

.PHONY: all test clean gcov_report clang control cppcheck

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_EXECUTABLES): %: %.o $(LIBRARY)
	$(CC) $(CFLAGS) $< $(LIBRARY) $(LDLIBS) -o $@

test: $(LIBRARY) $(TEST_EXECUTABLES)
	for test in $(TEST_EXECUTABLES); do ./$$test; done

clean:
	rm -rf $(LIBRARY) $(OBJECTS) $(TEST_OBJECTS) $(TEST_EXECUTABLES) *.gcno *.gcda *.gcov tests/*.gcda tests/*.gcov tests/*.gcno coverage.info report/ coverage_report/

gcov_report: test
	lcov -t "gcov_report" -o coverage.info -c -d .
	genhtml coverage.info -o report/
ifeq ($(UNAME_S),Darwin)
	open report/index.html
endif

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i $(ALL_SRC)

control: CFLAGS += -DVALGRIND
control: clean $(LIBRARY) $(TEST_EXECUTABLES)
	for test in $(TEST_EXECUTABLES); do CK_FORK=no valgrind --tool=memcheck --leak-check=yes ./$$test; done

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(ALL_SRC)