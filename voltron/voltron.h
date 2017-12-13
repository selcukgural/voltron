#ifndef VOLTRON_INCLUDE
#define VOLTRON_INCLUDE

#include <stddef.h>

#define  ASIZE(x)		(sizeof((x)) / sizeof((x)[0]))

enum predicate  {
	LESS_THAN = 1,
	LESS_THAN_OR_EQUAL = 2,
	GREATER = 3,
	GREATER_THAN_EQUAL = 4,
	NOT_EQUAL = 5
};
typedef struct condition
{
	enum predicate predicate;
	int predicate_value;
} condition;

int str_startswith(const char *source, const char *search_value, const int ignore_case);
int str_endswith(const char *source, const char *search_value, const int ignore_case);
char *str_padleft(const char *source, const size_t totalwidth, const char pdchr);
void str_padleft_inplace(char * source, const size_t totalwidth, const char pdchr);
char *str_padright(const char *source, const size_t totalwidth, const char pdchr);
void str_padright_inplace(char * source, const size_t totalwidth, const char pdchr);
char *str_insert(const char *source, const char *insert_value, const size_t startpos);
char *str_remove(const char *source, const size_t start, const size_t count);
char *str_replace(const char *source, const char chr, const char rep_chr);
char *str_trim(const char *source, const char *trimchrs, const size_t size);
char *str_trimstart(const char *source, const char *trimchrs, const size_t size);
char *str_trimend(const char *source, const char *trimchrs, const size_t size);
char *str_substring(const char *source, const size_t start_index, const size_t length);
char *str_toupper(const char *source);
char *str_tolower(const char *source);

int *int_removeall(const int *source, const struct condition condition, const size_t source_size, size_t *return_size);
int *int_remove(const int *source, const size_t source_size, const int rvalue, size_t *return_size);
#endif
