#ifndef VSTRING_INCLUDE
#define VSTRING_INCLUDE

#include <stddef.h>

int str_startswith(const char *source, const char *search_value, const int ignore_case);
int str_endswith(const char *source, const char *search_value, const int ignore_case);
char *str_padleft(const char *source, const unsigned int totalwidth, const char pdchr);
char *str_padright(const char *source, const unsigned int totalwidth, const char pdchr);
char *str_insert(const char *source, const char *insert_value, const unsigned int startpos);
char *str_remove(const char *source, const unsigned int start, const unsigned int count);
char *str_replace(const char *source, const char chr, const char rep_chr);
char *str_trim(const char* source, const char *trimchrs, const size_t size);
char *str_trimstart(const char* source, const char *trimchrs, const size_t size);
char *str_trimend(const char* source, const char *trimchrs, const size_t size);

#endif
