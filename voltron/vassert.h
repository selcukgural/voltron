#ifndef VASSERT_INCLUDE
#define VASSERT_INCLUDE

int assert_equal_int(const int actual, const int except, const int line, const char *funcname);
int assert_notequal_int(const int actual, const int except, const int line, const char *funcname);
int assert_equal_str(const char * actual, const char * except, const int line, const char *funcname);
int assert_condition_int(const int actual, const struct condition con, const int line, const char *funcname);
#endif
