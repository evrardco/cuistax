#include <string>
#include <stdarg.h>
#define MAX_STR_FORMAT_LEN 256

inline void str_fmt(std::string& out, const char * fmt, ...) {
    char buff[MAX_STR_FORMAT_LEN];
    va_list args;
    va_start(args, fmt);
    std::vsnprintf(buff, MAX_STR_FORMAT_LEN, fmt, args);
    va_end(args);
    out.assign(buff);
}