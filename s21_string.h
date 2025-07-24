#ifndef S21_STRING_H_
#define S21_STRING_H_

// макрос для NULL-указателя
#define S21_NULL ((void*)0)

// тип данных такой же как и size_t (зачастую как unsigned long)
typedef unsigned long s21_size_t;

// инициализация всех основных функций (15 штук)
void *s21_memchr(const void *str, int c, s21_size_t n);

#endif