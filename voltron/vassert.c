#include <stdio.h>
#include <string.h>
#include "vassert.h"
#include "voltron.h"


/*
 * @param			{const int actual}		actual parameter
 * @param			{const int except}		except parameter
 * @param			{const int line}		error line
 * @param			{const char *funcname}	function name
 * @description		if actual parameter equal except parameter then 0 otherwise return -1 
 */
int assert_equal_int(const int actual, const int except,const int line, const char *funcname)
{
	if(actual == except)
	{
		return  0;
	}
	printf("line: %d error: %s(actual:%d,except:%d);\n",line,funcname,actual,except);
	return -1;
}
/*
* @param			{const int actual}					actual parameter
* @param			{const struct condition con}		condition
* @param			{const int line}					error line
* @param			{const char *funcname}				function name
* @description		if actual parameter equal except parameter then 0 otherwise return -1
*/
int assert_condition_int(const int actual, const struct condition *con, const int line, const char *funcname)
{
	switch (con->predicate)
	{
	case GREATER:
		if (actual > con->predicate_value)
		{
			return  0;
		}
		printf("line: %d error: %s(actual:%d,except:%d);\n", line, funcname, actual, con->predicate_value);
		return -1;
	case GREATER_THAN_EQUAL:
		if (actual >= con->predicate_value)
		{
			return  0;
		}
		printf("line: %d error: %s(actual:%d,except:%d);\n", line, funcname, actual, con->predicate_value);
		return -1;
	case LESS_THAN:
		if (actual < con->predicate_value)
		{
			return  0;
		}
		printf("line: %d error: %s(actual:%d,except:%d);\n", line, funcname, actual, con->predicate_value);
		return -1;
	case LESS_THAN_OR_EQUAL:
		if (actual <= con->predicate_value)
		{
			return  0;
		}
		printf("line: %d error: %s(actual:%d,except:%d);\n", line, funcname, actual, con->predicate_value);
		return -1;
	case NOT_EQUAL:
		if (con->predicate_value != actual)
		{
			return  0;
		}
		printf("line: %d error: %s(actual:%d,except:%d);\n", line, funcname, actual, con->predicate_value);
		return -1;
	default:
		printf("line: %d error: %s(actual:%d,except:%d);\n", line, funcname, actual, con->predicate_value);
		return  -1;
	}
}

/*
* @param			{const int actual}		actual parameter
* @param			{const int except}		except parameter
* @param			{const int line}		error line
* @param			{const char *funcname}	function name
* @description		if actual parameter not equal except parameter then 0 otherwise return -1
*/
int assert_notequal_int(const int actual, const int except, const int line, const char *funcname)
{
	if (actual != except)
	{
		return  0;
	}
	printf("line: %d error: %s(actual:%d,except:%d);\n", line, funcname,actual, except);
	return -1;
}
/*
 * @param			{const char *actual}		actual parameter
 * @param			{const char *except}		except parameter
 * @param			{const int line}			error line
 * @param			{const char *funcname}		function name
 * @description		if actual parameter equal except parameter then 0 otherwise return -1
 */
int assert_equal_str(const char * actual, const char * except, const int line,const char *funcname)
{
	if (!strcmp(actual, except))
	{
		return  0;
	}
	printf("line: %d error: %s(actual:%s,except:%s);\n", line, funcname,actual, except);
	return -1;
}
