#pragma warning(disable:4996)
#include "vstring.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
* @param		{const char*}	source			üzerinde arama yapılacak karaketer dizisi
* @param		{const char*}	search_value	source içerisinde arama yapılacak olan karakterler dizisi
* @param		{const int}		ignore_case		0 olması durumunda büyük, küçük karakter durumuna bakılmaz diğer durumlarda büyük, küçük harf duyarlı olur.
* @description	source karakter dizisinin baştaki öğeleri arasında search_value ile gönderilen karakter dizisi aranır.
* @returns		karakterler uyuşuyorsa 0 aksi durumlarda -1
*/
int str_startswith(const char* source, const char* search_value, const int ignore_case)
{
	if (source == NULL || search_value == NULL) return  -1;

	const size_t source_len = strlen(source);
	const size_t search_len = strlen(search_value);

	if (search_len > source_len || search_len == 0 && source_len > 0) {
		return -1;
	}
	unsigned int counter = 0;
	while (counter != search_len && source[counter] != '\0')
	{
		switch (ignore_case)
		{
			case 0:
				if(toupper(source[counter]) != toupper(search_value[counter])) return  -1;
				break;
			default:
				if (source[counter] != search_value[counter]) return -1;
				break;
		}
		++counter;
	}	
	return 0;
}

/*
* @param		{const char*}	source			üzerinde arama yapılacak karaketer dizisi
* @param		{const char*}	search_value	source içerisinde arama yapılacak olan karakterler dizisi
* @param		{const int}		ignore_case		0 olması durumunda büyük, küçük karakter durumuna bakılmaz diğer durumlarda büyük, küçük harf duyarlı olur.
* @description	source karakter dizisinin sondaki öğeleri arasında search_value ile gönderilen karakter dizisi aranır.
* @returns		karakterler uyuşuyorsa 0 aksi durumlarda -1
*/
int str_endswith(const char* source, const char* search_value, const int ignore_case)
{
	if (source == NULL || search_value == NULL) return  -1;

	const size_t source_len = strlen(source);
	const size_t search_len = strlen(search_value);

	if (search_len > source_len || search_len == 0 && source_len > 0) {
		return -1;
	}
	const char *ptemp = source + (source_len - search_len);
	unsigned int counter = 0;
	while (ptemp[counter] != '\0')
	{
		switch (ignore_case)
		{
			case 0:
				if (toupper(ptemp[counter]) != toupper(search_value[counter])) return -1;
				break;
			default:
				if(ptemp[counter] != search_value[counter]) return -1;
				break;
		}
		++counter;
	}
	return 0;
}
/*
 * @param			{const char*}	source			sol tarafına ekleme yapılacak olan karekterler dizisi
 * @param			{unsigned int}	totalwidth		sol başa eklenecek toplam karakter uzunluğu 
 * @param			{char}			pdchr			sol başa eklenecek karakter
 * @description		totalwidth, source dizisinin öğe sayısından büyükse source yazısının sol tarafına aradaki fark kadar pdchr karakterini ekler.
 * returns			başarılı olması durumunda yeni bir char dizisi adresi onun dışındaki durumlarda NULL pointer
 */
char*  str_padleft(const char *source,const unsigned int totalwidth, const char pdchr)
{
	if (source == NULL || totalwidth <= 0) return NULL;

	const size_t source_len = strlen(source);
	if (source_len >= totalwidth) return NULL;

	const size_t size = totalwidth - source_len;
	char *strn =  (char*)malloc(source_len + size + 1);
	if(!strn) return NULL;

	size_t k = 0;
	for(k = 0; k < size; ++k)
	{
		strn[k] = pdchr;
	}
	strn[k] = '\0';
	return strcat(strn, source);
}
/*
* @param			{const char*}	source			sol tarafına ekleme yapılacak olan karekterler dizisi
* @param			{unsigned int}	totalwidth		sol başa eklenecek toplam karakter uzunluğu
* @param			{char}			pdchr			sol başa eklenecek karakter
* @description		totalwidth, source dizisinin öğe sayısından büyükse source yazısının sağ tarafına aradaki fark kadar pdchr karakterini ekler.
* returns			başarılı olması durumunda yeni bir char dizisi adresi onun dışındaki durumlarda NULL pointer
*/
char * str_padright(const char * source, const unsigned int totalwidth, const char pdchr)
{
	if (source == NULL) return NULL;

	const size_t source_len = strlen(source);
	if (source_len >= totalwidth) return NULL;

	const size_t size = totalwidth - source_len;
	char *strn = (char*)malloc(source_len + size + 1);
	if (!strn) return NULL;

	size_t k = 0;

	for (; k < source_len; ++k)
	{
		strn[k] = source[k];
	}
	const size_t tempk = k;
	k = 0;
	for (; k < size; ++k)
	{
		strn[tempk + k] = pdchr;
	}
	strn[tempk + k] = '\0';
	return  strn;
}

char * str_insert(const char * source, const char * insert_value, const unsigned int startpos)
{
	if (source == NULL || insert_value == NULL) return NULL;

	const size_t source_len = strlen(source);
	const size_t insert_len = strlen(insert_value);

	char *nstr = (char*)malloc(source_len + insert_len + 1);
	if (!nstr) return  NULL;

	strncpy(nstr, source, startpos);
	nstr[startpos] = '\0';
	strcat(nstr, insert_value);
	return strcat(nstr, source + startpos);
}

char * str_remove(const char * source, const unsigned int start, const unsigned int count)
{
	const size_t source_len = strlen(source);
	char *nstr = (char*)malloc((source_len - count) + 1);
	const unsigned int tstart = start;
	
	strncpy(nstr,source,start);
	nstr[start] = '\0';
	if (strlen(source) == start + count)
	{
		return nstr;
	}
	
	strcat(&nstr[start], &source[start + count]);
	nstr[source_len - count] = '\0';
	return nstr;
	
}

