#include "s21_string.h"
#include <stdio.h>

// реализация функции s21_memchr
void *s21_memchr(const void *str, int c, s21_size_t n) {
    const unsigned char *p = (const unsigned char *)str;
    for (s21_size_t i = 0; i < n; i++) {
        if (p[i] == (unsigned char) c) {
            return (void *)(p + i);
        }
    }
    return S21_NULL;
}

// реализация функции s21_memcmp
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *p1 = (const unsigned char *)str1;
    const unsigned char *p2 = (const unsigned char *)str2;
    for (s21_size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return (int)p1[i] - (int)p2[i];
        }
    }
    return 0;
}

// реализация функции s21_memcpy
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    unsigned char *p1 = (unsigned char *)dest;
    const unsigned char *p2 = (const unsigned char *)src;
    for (s21_size_t i = 0; i < n; i++) {
        p1[i] = p2[i];
    }
    return dest;
}

// реализация функции s21_memset
void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *p = (unsigned char *)str;
    for (s21_size_t i = 0; i < n; i++) {
        p[i] = (unsigned char)c;
    }
    return str;
}

// реализация функции s21_strncat
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t dest_last_index = s21_strlen(dest);
    s21_size_t copied = 0;
    for (s21_size_t i = 0; i < n && src[i] != '\0'; i++) {
        dest[dest_last_index + i] = src[i];
        copied++;
    }
    dest[dest_last_index + copied] = '\0';
    return dest;
}

// реализация функции s21_strchr
char *s21_strchr(const char *str, int c) {
    while (*str) {
        if (*str == (char)c) return (char *)str;
        str++;
    }

    if ((char)c == '\0') return (char *)str;
    return S21_NULL;
}

// реализация функции s21_strncmp
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    unsigned char *p1 = (unsigned char *)str1;
    unsigned char *p2 = (unsigned char *)str2;
    for (s21_size_t i = 0; (i < n) && (p1[i] != '\0' || p2[i] != '\0'); i++) {
        if (p1[i] != p2[i]) {
            return p1[i] - p2[i];
        }
    }
    return 0;
}

// реализация функции s21_strncpy
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i = 0;
    for (; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

// реализация функции s21_strcspn
s21_size_t s21_strcspn(const char *str, const char *reject) {
    s21_size_t i = 0;
    while (str[i] != '\0') {
        s21_size_t j = 0;
        while (reject[j] != '\0') {
            if (str[i] == reject[j]) {
                return i;
            }
            j++;
        }
        i++;
    }
    return i;
}

// реализация функции s21_strerror
#ifdef __linux__
static const char *s21_errors[] = {
    "Success",                         // 0
    "Operation not permitted",         // 1 (EPERM)
    "No such file or directory",       // 2 (ENOENT)
    "No such process",                 // 3 (ESRCH)
    "Interrupted system call",         // 4 (EINTR)
    "Input/output error",              // 5 (EIO)
    "No such device or address",       // 6 (ENXIO)
    "Argument list too long",          // 7 (E2BIG)
    "Exec format error",               // 8 (ENOEXEC)
    "Bad file descriptor",             // 9 (EBADF)
    "No child processes",              // 10 (ECHILD)
    "Resource temporarily unavailable",// 11 (EAGAIN/EWOULDBLOCK)
    "Cannot allocate memory",          // 12 (ENOMEM)
    "Permission denied",               // 13 (EACCES)
    "Bad address",                     // 14 (EFAULT)
    "Block device required",           // 15 (ENOTBLK)
    "Device or resource busy",         // 16 (EBUSY)
    "File exists",                     // 17 (EEXIST)
    "Invalid cross-device link",       // 18 (EXDEV)
    "No such device",                  // 19 (ENODEV)
    "Not a directory",                 // 20 (ENOTDIR)
    "Is a directory",                  // 21 (EISDIR)
    "Invalid argument",                // 22 (EINVAL)
    "Too many open files in system",   // 23 (ENFILE)
    "Too many open files",             // 24 (EMFILE)
    "Inappropriate ioctl for device",  // 25 (ENOTTY)
    "Text file busy",                  // 26 (ETXTBSY)
    "File too large",                  // 27 (EFBIG)
    "No space left on device",         // 28 (ENOSPC)
    "Illegal seek",                    // 29 (ESPIPE)
    "Read-only file system",           // 30 (EROFS)
    "Too many links",                  // 31 (EMLINK)
    "Broken pipe",                     // 32 (EPIPE)
    "Numerical argument out of domain",// 33 (EDOM)
    "Numerical result out of range",   // 34 (ERANGE)
    "Resource deadlock avoided",       // 35 (EDEADLK/EDEADLOCK)
    "File name too long",              // 36 (ENAMETOOLONG)
    "No locks available",              // 37 (ENOLCK)
    "Function not implemented",        // 38 (ENOSYS)
    "Directory not empty",             // 39 (ENOTEMPTY)
    "Too many levels of symbolic links", // 40 (ELOOP)
    "Unknown error 41",                // 41 (EWOULDBLOCK, псевдоним EAGAIN)
    "No message of desired type",      // 42 (ENOMSG)
    "Identifier removed",              // 43 (EIDRM)
    "Channel number out of range",     // 44 (ECHRNG)
    "Level 2 not synchronized",        // 45 (EL2NSYNC)
    "Level 3 halted",                  // 46 (EL3HLT)
    "Level 3 reset",                   // 47 (EL3RST)
    "Link number out of range",        // 48 (ELNRNG)
    "Protocol driver not attached",    // 49 (EUNATCH)
    "No CSI structure available",      // 50 (ENOCSI)
    "Level 2 halted",                  // 51 (EL2HLT)
    "Invalid exchange",                // 52 (EBADE)
    "Invalid request descriptor",      // 53 (EBADR)
    "Exchange full",                   // 54 (EXFULL)
    "No anode",                        // 55 (ENOANO)
    "Invalid request code",            // 56 (EBADRQC)
    "Invalid slot",                    // 57 (EBADSLT)
    "Unknown error 58",                // 58 (EDEADLOCK, псевдоним EDEADLK)
    "Bad font file format",            // 59 (EBFONT)
    "Device not a stream",             // 60 (ENOSTR)
    "No data available",               // 61 (ENODATA)
    "Timer expired",                   // 62 (ETIME)
    "Out of streams resources",        // 63 (ENOSR)
    "Machine is not on the network",   // 64 (ENONET)
    "Package not installed",           // 65 (ENOPKG)
    "Object is remote",                // 66 (EREMOTE)
    "Link has been severed",           // 67 (ENOLINK)
    "Advertise error",                 // 68 (EADV)
    "Srmount error",                   // 69 (ESRMNT)
    "Communication error on send",     // 70 (ECOMM)
    "Protocol error",                  // 71 (EPROTO)
    "Multihop attempted",              // 72 (EMULTIHOP)
    "RFS specific error",              // 73 (EDOTDOT)
    "Bad message",                     // 74 (EBADMSG)
    "Value too large for defined data type", // 75 (EOVERFLOW)
    "Name not unique on network",      // 76 (ENOTUNIQ)
    "File descriptor in bad state",    // 77 (EBADFD)
    "Remote address changed",          // 78 (EREMCHG)
    "Can not access a needed shared library", // 79 (ELIBACC)
    "Accessing a corrupted shared library", // 80 (ELIBBAD)
    ".lib section in a.out corrupted", // 81 (ELIBSCN)
    "Attempting to link in too many shared libraries", // 82 (ELIBMAX)
    "Cannot exec a shared library directly", // 83 (ELIBEXEC)
    "Invalid or incomplete multibyte or wide character", // 84 (EILSEQ)
    "Interrupted system call should be restarted", // 85 (ERESTART)
    "Streams pipe error",              // 86 (ESTRPIPE)
    "Too many users",                  // 87 (EUSERS)
    "Socket operation on non-socket",  // 88 (ENOTSOCK)
    "Destination address required",    // 89 (EDESTADDRREQ)
    "Message too long",                // 90 (EMSGSIZE)
    "Protocol wrong type for socket",  // 91 (EPROTOTYPE)
    "Protocol not available",          // 92 (ENOPROTOOPT)
    "Protocol not supported",          // 93 (EPROTONOSUPPORT)
    "Socket type not supported",       // 94 (ESOCKTNOSUPPORT)
    "Operation not supported",         // 95 (EOPNOTSUPP)
    "Protocol family not supported",   // 96 (EPFNOSUPPORT)
    "Address family not supported by protocol", // 97 (EAFNOSUPPORT)
    "Address already in use",          // 98 (EADDRINUSE)
    "Cannot assign requested address", // 99 (EADDRNOTAVAIL)
    "Network is down",                 // 100 (ENETDOWN)
    "Network is unreachable",          // 101 (ENETUNREACH)
    "Network dropped connection on reset", // 102 (ENETRESET)
    "Software caused connection abort", // 103 (ECONNABORTED)
    "Connection reset by peer",        // 104 (ECONNRESET)
    "No buffer space available",       // 105 (ENOBUFS)
    "Transport endpoint is already connected", // 106 (EISCONN)
    "Transport endpoint is not connected", // 107 (ENOTCONN)
    "Cannot send after transport endpoint shutdown", // 108 (ESHUTDOWN)
    "Too many references: cannot splice", // 109 (ETOOMANYREFS)
    "Connection timed out",            // 110 (ETIMEDOUT)
    "Connection refused",              // 111 (ECONNREFUSED)
    "Host is down",                    // 112 (EHOSTDOWN)
    "No route to host",                // 113 (EHOSTUNREACH)
    "Operation already in progress",   // 114 (EALREADY)
    "Operation now in progress",       // 115 (EINPROGRESS)
    "Stale file handle",               // 116 (ESTALE)
    "Structure needs cleaning",        // 117 (EUCLEAN)
    "Not a XENIX named type file",     // 118 (ENOTNAM)
    "No XENIX semaphores available",   // 119 (ENAVAIL)
    "Is a named type file",            // 120 (EISNAM)
    "Remote I/O error",                // 121 (EREMOTEIO)
    "Disk quota exceeded",             // 122 (EDQUOT)
    "No medium found",                 // 123 (ENOMEDIUM)
    "Wrong medium type",               // 124 (EMEDIUMTYPE)
    "Operation canceled",              // 125 (ECANCELED)
    "Required key not available",      // 126 (ENOKEY)
    "Key has expired",                 // 127 (EKEYEXPIRED)
    "Key has been revoked",            // 128 (EKEYREVOKED)
    "Key was rejected by service",     // 129 (EKEYREJECTED)
    "Owner died",                      // 130 (EOWNERDEAD)
    "State not recoverable",           // 131 (ENOTRECOVERABLE)
    "Operation not possible due to RF-kill", // 132 (ERFKILL)
    "Memory page has hardware error"   // 133 (EHWPOISON)
};
#define MAX_ERROR 133
#elif defined __APPLE__
static const char *s21_errors[] = {
    "Undefined error: 0",              // 0
    "Operation not permitted",         // 1 (EPERM)
    "No such file or directory",       // 2 (ENOENT)
    "No such process",                 // 3 (ESRCH)
    "Interrupted system call",         // 4 (EINTR)
    "Input/output error",              // 5 (EIO)
    "Device not configured",           // 6 (ENXIO)
    "Argument list too long",          // 7 (E2BIG)
    "Exec format error",               // 8 (ENOEXEC)
    "Bad file descriptor",             // 9 (EBADF)
    "No child processes",              // 10 (ECHILD)
    "Resource deadlock avoided",       // 11 (EDEADLK)
    "Cannot allocate memory",          // 12 (ENOMEM)
    "Permission denied",               // 13 (EACCES)
    "Bad address",                     // 14 (EFAULT)
    "Block device required",           // 15 (ENOTBLK)
    "Resource busy",                   // 16 (EBUSY)
    "File exists",                     // 17 (EEXIST)
    "Cross-device link",               // 18 (EXDEV)
    "Operation not supported by device", // 19 (ENODEV)
    "Not a directory",                 // 20 (ENOTDIR)
    "Is a directory",                  // 21 (EISDIR)
    "Invalid argument",                // 22 (EINVAL)
    "Too many open files in system",   // 23 (ENFILE)
    "Too many open files",             // 24 (EMFILE)
    "Inappropriate ioctl for device",  // 25 (ENOTTY)
    "Text file busy",                  // 26 (ETXTBSY)
    "File too large",                  // 27 (EFBIG)
    "No space left on device",         // 28 (ENOSPC)
    "Illegal seek",                    // 29 (ESPIPE)
    "Read-only file system",           // 30 (EROFS)
    "Too many links",                  // 31 (EMLINK)
    "Broken pipe",                     // 32 (EPIPE)
    "Numerical argument out of domain", // 33 (EDOM)
    "Result too large",                // 34 (ERANGE)
    "Resource temporarily unavailable", // 35 (EAGAIN/EWOULDBLOCK)
    "Operation now in progress",       // 36 (EINPROGRESS)
    "Operation already in progress",   // 37 (EALREADY)
    "Socket operation on non-socket",  // 38 (ENOTSOCK)
    "Destination address required",    // 39 (EDESTADDRREQ)
    "Message too long",                // 40 (EMSGSIZE)
    "Protocol wrong type for socket",  // 41 (EPROTOTYPE)
    "Protocol not available",          // 42 (ENOPROTOOPT)
    "Protocol not supported",          // 43 (EPROTONOSUPPORT)
    "Socket type not supported",       // 44 (ESOCKTNOSUPPORT)
    "Operation not supported",         // 45 (ENOTSUP/EOPNOTSUPP)
    "Protocol family not supported",   // 46 (EPFNOSUPPORT)
    "Address family not supported by protocol family", // 47 (EAFNOSUPPORT)
    "Address already in use",          // 48 (EADDRINUSE)
    "Can't assign requested address",  // 49 (EADDRNOTAVAIL)
    "Network is down",                 // 50 (ENETDOWN)
    "Network is unreachable",          // 51 (ENETUNREACH)
    "Network dropped connection on reset", // 52 (ENETRESET)
    "Software caused connection abort", // 53 (ECONNABORTED)
    "Connection reset by peer",         // 54 (ECONNRESET)
    "No buffer space available",       // 55 (ENOBUFS)
    "Socket is already connected",     // 56 (EISCONN)
    "Socket is not connected",         // 57 (ENOTCONN)
    "Can't send after socket shutdown", // 58 (ESHUTDOWN)
    "Too many references: can't splice", // 59 (ETOOMANYREFS)
    "Operation timed out",             // 60 (ETIMEDOUT)
    "Connection refused",              // 61 (ECONNREFUSED)
    "Too many levels of symbolic links", // 62 (ELOOP)
    "File name too long",              // 63 (ENAMETOOLONG)
    "Host is down",                    // 64 (EHOSTDOWN)
    "No route to host",                // 65 (EHOSTUNREACH)
    "Directory not empty",             // 66 (ENOTEMPTY)
    "Too many processes",              // 67 (EPROCLIM)
    "Too many users",                  // 68 (EUSERS)
    "Disc quota exceeded",             // 69 (EDQUOT)
    "Stale NFS file handle",           // 70 (ESTALE)
    "Too many levels of remote in path", // 71 (EREMOTE)
    "RPC struct is bad",               // 72 (EBADRPC)
    "RPC version wrong",               // 73 (ERPCMISMATCH)
    "RPC prog. not avail",             // 74 (EPROGUNAVAIL)
    "Program version wrong",           // 75 (EPROGMISMATCH)
    "Bad procedure for program",       // 76 (EPROCUNAVAIL)
    "No locks available",              // 77 (ENOLCK)
    "Function not implemented",        // 78 (ENOSYS)
    "Inappropriate file type or format", // 79 (EFTYPE)
    "Authentication error",            // 80 (EAUTH)
    "Need authenticator",              // 81 (ENEEDAUTH)
    "Device power is off",             // 82 (EPWROFF)
    "Device error",                    // 83 (EDEVERR)
    "Value too large to be stored in data type", // 84 (EOVERFLOW)
    "Bad executable (or shared library)", // 85 (EBADEXEC)
    "Bad CPU type in executable",      // 86 (EBADARCH)
    "Shared library version mismatch", // 87 (ESHLIBVERS)
    "Malformed Mach-o file",           // 88 (EBADMACHO)
    "Operation canceled",              // 89 (ECANCELED)
    "Identifier removed",              // 90 (EIDRM)
    "No message of desired type",      // 91 (ENOMSG)
    "Illegal byte sequence",           // 92 (EILSEQ)
    "Attribute not found",             // 93 (ENOATTR)
    "Bad message",                     // 94 (EBADMSG)
    "EMULTIHOP (Reserved)",            // 95 (EMULTIHOP)
    "No message available on STREAM",  // 96 (ENODATA)
    "ENOLINK (Reserved)",              // 97 (ENOLINK)
    "No STREAM resources",             // 98 (ENOSR)
    "Not a STREAM",                    // 99 (ENOSTR)
    "Protocol error",                  // 100 (EPROTO)
    "STREAM ioctl timeout",            // 101 (ETIME)
    "Operation not supported on socket", // 102 (EOPNOTSUPP)
    "Policy not found",                // 103 (ENOPOLICY)
    "State not recoverable",           // 104 (ENOTRECOVERABLE)
    "Previous owner died",             // 105 (EOWNERDEAD)
    "Interface output queue is full"   // 106 (EQFULL)
};
#define MAX_ERROR 106
#endif

char *s21_strerror(int errnum) {
    if (errnum >= 0 && errnum <= MAX_ERROR) {
        return (char *)s21_errors[errnum];
    }
    static char buffer[50];
    snprintf(buffer, sizeof(buffer), "Unknown error %d", errnum);
    return buffer;
}

// реализация функции s21_strlen
s21_size_t s21_strlen(const char *str) {
    s21_size_t n = 0;
    while (str[n] != '\0') {
        n++;
    }
    return n;
}

// реализация функции s21_strpbrk
char *s21_strpbrk(const char *str1, const char *str2) {
    s21_size_t i = 0;
    while (str1[i] != '\0') {
        s21_size_t j = 0;
        while (str2[j] != '\0') {
            if (str1[i] == str2[j]) {
                return (char *)(str1 + i);
            }
            j++;
        }
        i++;
    }
    return S21_NULL;
}

// реализация функции s21_strrchr
char *s21_strrchr(const char *str, int c) {
    const char *last = S21_NULL;
    while (*str) {
        if (*str == (char)c) {
            last = str;
        }
        str++;
    }

    if ((char)c == '\0') return (char *)str;
    return (char *)last;
}

// реализация функции s21_strstr
char *s21_strstr(const char *haystack, const char *needle) {
    if (!*needle) return (char *)haystack; 
    
    for (; *haystack; haystack++) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }

        if (!*n) return (char *)haystack;
    }
    return S21_NULL;
}

// реализация функции s21_strtok
char *s21_strtok(char *str, const char *delim) {
    static char *last = S21_NULL; // статичный указатель - сохраняет значение между вызовами

    if (str != S21_NULL) { // если str не NULL то копируем указатель на str в last
        last = str;
    } else if (last == S21_NULL) { // если у нас прошлое условие не выполнилось то возвращаем NULL
        return S21_NULL;
    }

    // пропускаем все начальные разделители
    while (*last != '\0' && s21_strchr(delim, *last) != S21_NULL) {
        last++;
    }
    if (*last == '\0') { // если дошли до конца строки - возвращаем NULL
        last = S21_NULL;
        return S21_NULL;
    }

    char *token_start = last; // указываем на начало текущего токена
    last = s21_strpbrk(token_start, delim); // ищем следующий символ-разделитель после начала токена

    if (last != S21_NULL) { // если найдем разделитель, то завершаем токен нулем и сдвигаем указатель
        *last = '\0';
        last++;
    }

    return token_start; // возвращаем токен
}