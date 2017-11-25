#ifndef VSTRING_INCLUDE
#define VSTRING_INCLUDE

#include <stddef.h>

int str_startswith(const char *source, const char *search_value, const int ignore_case);
int str_endswith(const char *source, const char *search_value, const int ignore_case);
char *str_padleft(const char *source, const size_t totalwidth, const char pdchr);
char *str_padright(const char *source, const size_t totalwidth, const char pdchr);
char *str_insert(const char *source, const char *insert_value, const size_t startpos);
char *str_remove(const char *source, const size_t start, const size_t count);
char *str_replace(const char *source, const char chr, const char rep_chr);
char *str_trim(const char *source, const char *trimchrs, const size_t size);
char *str_trimstart(const char *source, const char *trimchrs, const size_t size);
char *str_trimend(const char *source, const char *trimchrs, const size_t size);
char *str_substring(const char *source, const size_t start_index, const size_t length);
char *str_toupper(const char *source);
char *str_tolower(const char *source);

#endif
