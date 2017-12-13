#include <stdio.h>
#include <string.h>
#include "vassert.h"


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
	const int result = strcmp(actual, except);
	if (!result)
	{
		return  0;
	}
	printf("line: %d error: %s(actual:%s,except:%s);\n", line, funcname,actual, except);
	return -1;
}
