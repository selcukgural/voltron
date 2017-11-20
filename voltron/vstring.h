#ifndef VSTRING_INCLUDE
#define VSTRING_INCLUDE

int str_startswith(const char *source, const char *search_value, const int ignore_case);
int str_endswith(const char *source, const char *search_value, const int ignore_case);
char *str_padleft(const char *source, const unsigned int totalwidth, const char pdchr);
char *str_padright(const char *source, const unsigned int totalwidth, const char pdchr);
char *str_insert(const char *source, const char *insert_value, const unsigned int startpos);
char *str_remove(const char *source, const unsigned int start, const unsigned int count);

#endif
