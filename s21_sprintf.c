#include "s21_sprintf.h"
#include "s21_string.h"

void s21_parse_flags(const char **format, FormatFlags *flags) {
    while (1) {
        switch (**format) {
            case '-': flags->minus = 1; break;
            case '+': flags->plus = 1; break;
            case ' ': flags->space = 1; break;
            default: return;
        }
        (*format)++;
    }
}

void s21_parse_width(const char **format, FormatFlags *flags, va_list *args) {
    if (**format == '*') {
        flags->width = va_arg(*args, int);
        (*format)++;
    } else {
        while (**format >= '0' && **format <= '9') {
            flags->width = flags->width * 10 + (**format - '0');
            (*format)++;
        }
    }
}

void s21_parse_precision(const char **format, FormatFlags *flags, va_list *args) {
    if (**format == '.') {
        flags->is_precision_set = 1;
        (*format)++;
        if (**format == '*') {
            flags->precision = va_arg(*args, int);
            (*format)++;
            if (flags->precision < 0) {
                flags->is_precision_set = 0;
                flags->precision = 0;
            }
        } else {
            flags->precision = 0;
            while (**format >= '0' && **format <= '9') {
                flags->precision = flags->precision * 10 + (**format - '0');
                (*format)++;
            }
        }
    }
}

void s21_parse_length(const char **format, FormatFlags *flags) {
    if (**format == 'h' || **format == 'l') {
        flags->length = **format;
        (*format)++;
    }
}

void s21_parse_specifier(const char **format, FormatFlags *flags) {
    flags->specifier = **format;
    (*format)++;
}

void s21_parse_format(const char **format, FormatFlags *flags, va_list *args) {
    s21_parse_flags(format, flags);
    s21_parse_width(format, flags, args);
    s21_parse_precision(format, flags, args);
    s21_parse_length(format, flags);
    s21_parse_specifier(format, flags);
}

void s21_add_padding_before(char *str, int *index, int padding) {
    for (int i = 0; i < padding; i++) {
        str[(*index)++] = ' ';
    }
}

void s21_add_padding_after(char *str, int *index, int padding) {
    for (int i = 0; i < padding; i++) {
        str[(*index)++] = ' ';
    }
}

void s21_add_sign(char *str, int *index, int is_negative, FormatFlags *flags) {
    if (is_negative) {
        str[(*index)++] = '-';
    } else if (flags->plus) {
        str[(*index)++] = '+';
    } else if (flags->space) {
        str[(*index)++] = ' ';
    }
}

void s21_add_leading_zeros(char *str, int *index, int zeros_count) {
    for (int j = 0; j < zeros_count; j++) {
        str[(*index)++] = '0';
    }
}

void s21_reverse_buffer_to_str(char *str, int *index, const char *buffer, int len) {
    for (int j = len - 1; j >= 0; j--) {
        str[(*index)++] = buffer[j];
    }
}

void s21_process_char(char *str, int *index, char c, FormatFlags *flags) {
    if (flags->width > 1 && !flags->minus) {
        s21_add_padding_before(str, index, flags->width - 1);
    }
    str[(*index)++] = c;
    if (flags->width > 1 && flags->minus) {
        s21_add_padding_after(str, index, flags->width - 1);
    }
}

void s21_process_string(char *str, int *index, const char *s, FormatFlags *flags) {
    s21_size_t len = s ? s21_strlen(s) : 6; // Длина "(null)" = 6
    if (!s) s = "(null)";

    if (flags->is_precision_set && flags->precision < (int)len) {
        len = flags->precision;
    }

    int padding = flags->width - len;
    if (padding > 0 && !flags->minus) {
        s21_add_padding_before(str, index, padding);
    }

    s21_strncpy(&str[*index], s, len);
    *index += len;

    if (padding > 0 && flags->minus) {
        s21_add_padding_after(str, index, padding);
    }
}

void s21_process_int(char *str, int *index, long long num, FormatFlags *flags) {
    if (num == LLONG_MIN || num == LONG_MIN || num == INT_MIN) {
        const char *min_str;
        if (num == LLONG_MIN) {
            min_str = "-9223372036854775808";
        } else if (num == LONG_MIN) {
            min_str = "-2147483648";
        } else {
            min_str = "-2147483648";
        }
        
        s21_size_t len = s21_strlen(min_str);
        int padding = flags->width - len;
        
        if (padding > 0 && !flags->minus) {
            s21_add_padding_before(str, index, padding);
        }
        
        s21_strncpy(&str[*index], min_str, len);
        *index += len;
        
        if (padding > 0 && flags->minus) {
            s21_add_padding_after(str, index, padding);
        }
        return;
    }

    char buffer[BUFFER_SIZE];
    int is_negative = num < 0;
    if (is_negative) num = -num;

    int i = 0;
    do {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    int len = i;
    int precision = flags->is_precision_set ? flags->precision : 1;
    if (precision > len) len = precision;

    int sign_len = is_negative || flags->plus || flags->space ? 1 : 0;
    int total_len = len + sign_len;
    int padding = flags->width - total_len;

    if (padding > 0 && !flags->minus) {
        s21_add_padding_before(str, index, padding);
    }

    s21_add_sign(str, index, is_negative, flags);
    s21_add_leading_zeros(str, index, precision - i);
    s21_reverse_buffer_to_str(str, index, buffer, i);

    if (padding > 0 && flags->minus) {
        s21_add_padding_after(str, index, padding);
    }
}

void s21_process_unsigned(char *str, int *index, unsigned long long num, FormatFlags *flags) {
    if (num == ULLONG_MAX || num == ULONG_MAX || num == UINT_MAX) {
        const char *max_str;
        if (num == ULLONG_MAX) {
            max_str = "18446744073709551615";
        } else if (num == ULONG_MAX) {
            max_str = "4294967295";
        } else {
            max_str = "4294967295";
        }
        
        s21_size_t len = s21_strlen(max_str);
        int padding = flags->width - len;
        
        if (padding > 0 && !flags->minus) {
            s21_add_padding_before(str, index, padding);
        }
        
        s21_strncpy(&str[*index], max_str, len);
        *index += len;
        
        if (padding > 0 && flags->minus) {
            s21_add_padding_after(str, index, padding);
        }
        return;
    }

    char buffer[BUFFER_SIZE];
    int i = 0;
    do {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    int len = i;
    int precision = flags->is_precision_set ? flags->precision : 1;
    if (precision > len) len = precision;

    int padding = flags->width - len;
    if (padding > 0 && !flags->minus) {
        s21_add_padding_before(str, index, padding);
    }

    s21_add_leading_zeros(str, index, precision - i);
    s21_reverse_buffer_to_str(str, index, buffer, i);

    if (padding > 0 && flags->minus) {
        s21_add_padding_after(str, index, padding);
    }
}

void s21_process_float(char *str, int *index, double num, FormatFlags *flags) {
    if (num != num || num == 1.0/0.0 || num == -1.0/0.0) {
        const char *special_str = (num != num) ? "nan" : (num < 0 ? "-inf" : "inf");
        s21_process_string(str, index, special_str, flags);
        return;
    }

    char buffer[BUFFER_SIZE];
    int is_negative = num < 0;
    if (is_negative) num = -num;

    int precision = flags->is_precision_set ? flags->precision : 6;

    long long int_part = (long long)num;
    double frac_part = num - int_part;

    for (int i = 0; i < precision; i++) {
        frac_part *= 10;
    }
    long long frac_int = (long long)(frac_part + 0.5);

    int i = 0;
    do {
        buffer[i++] = (int_part % 10) + '0';
        int_part /= 10;
    } while (int_part > 0);

    int len = i + precision + (precision > 0 ? 1 : 0);
    int sign_len = is_negative || flags->plus || flags->space ? 1 : 0;
    int total_len = len + sign_len;
    int padding = flags->width - total_len;

    if (padding > 0 && !flags->minus) {
        s21_add_padding_before(str, index, padding);
    }

    s21_add_sign(str, index, is_negative, flags);
    s21_reverse_buffer_to_str(str, index, buffer, i);

    if (precision > 0) {
        str[(*index)++] = '.';
        for (int j = precision - 1; j >= 0; j--) {
            str[(*index)++] = (frac_int % 10) + '0';
            frac_int /= 10;
        }
    }

    if (padding > 0 && flags->minus) {
        s21_add_padding_after(str, index, padding);
    }
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);

    int index = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            FormatFlags flags = {0};
            s21_parse_format(&format, &flags, &args);

            switch (flags.specifier) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    s21_process_char(str, &index, c, &flags);
                    break;
                }
                case 'd': {
                    long long num;
                    if (flags.length == 'h') {
                        num = (short)va_arg(args, int);
                    } else if (flags.length == 'l') {
                        num = va_arg(args, long);
                    } else {
                        num = va_arg(args, int);
                    }
                    s21_process_int(str, &index, num, &flags);
                    break;
                }
                case 'f': {
                    double num = va_arg(args, double);
                    s21_process_float(str, &index, num, &flags);
                    break;
                }
                case 's': {
                    const char *s = va_arg(args, const char *);
                    s21_process_string(str, &index, s, &flags);
                    break;
                }
                case 'u': {
                    unsigned long long num;
                    if (flags.length == 'h') {
                        num = (unsigned short)va_arg(args, unsigned int);
                    } else if (flags.length == 'l') {
                        num = va_arg(args, unsigned long);
                    } else {
                        num = va_arg(args, unsigned int);
                    }
                    s21_process_unsigned(str, &index, num, &flags);
                    break;
                }
                case '%': {
                    s21_process_char(str, &index, '%', &flags);
                    break;
                }
                default:
                    break;
            }
        } else {
            str[index++] = *format++;
        }
    }

    str[index] = '\0';
    va_end(args);
    return index;
}