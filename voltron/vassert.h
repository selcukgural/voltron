#ifndef VASSERT_INCLUDE
#define VASSERT_INCLUDE

int assert_equal_int(const int actual, const int except, const int line);
int assert_notequal_int(const int actual, const int except, const int line);
int assert_equal_str(const char *actual, const char *except, const int line);

#endif
