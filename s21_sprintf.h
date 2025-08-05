#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

#define BUFFER_SIZE 1024

typedef struct {
    // спецификатор
    char specifier; 

    // Флаги
    int minus;
    int plus;
    int space;

    // ширина
    int width;  
    
    // точность
    int precision;  
    int is_precision_set;  // установлена ли точность
    
    // длина
    char length;
} FormatFlags;

// Парсеры флагов
void s21_parse_flags(const char **format, FormatFlags *flags);
void s21_parse_width(const char **format, FormatFlags *flags, va_list *args);
void s21_parse_precision(const char **format, FormatFlags *flags, va_list *args);
void s21_parse_length(const char **format, FormatFlags *flags);
void s21_parse_specifier(const char **format, FormatFlags *flags);
void s21_parse_format(const char **format, FormatFlags *flags, va_list *args);

// Вспомогательные функции
void s21_add_padding_before(char *str, int *index, int padding);
void s21_add_padding_after(char *str, int *index, int padding);
void s21_add_sign(char *str, int *index, int is_negative, FormatFlags *flags);
void s21_add_leading_zeros(char *str, int *index, int zeros_count);
void s21_reverse_buffer_to_str(char *str, int *index, const char *buffer, int len);

// Обработка спецификаторов
void s21_process_char(char *str, int *index, char c, FormatFlags *flags);                      // c
void s21_process_int(char *str, int *index, long long num, FormatFlags *flags);                // d
void s21_process_float(char *str, int *index, double num, FormatFlags *flags);                 // f
void s21_process_string(char *str, int *index, const char *s, FormatFlags *flags);             // s
void s21_process_unsigned(char *str, int *index, unsigned long long num, FormatFlags *flags);  // u

// Основная функция
int s21_sprintf(char *str, const char *format, ...);

#endif  // S21_SPRINTF_H
