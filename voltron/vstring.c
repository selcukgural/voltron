#pragma warning(disable:4996)
#include "vstring.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



static char *toupper_or_tolower(const char *source, const size_t lou);

/*
* @param		{const char*}	source			üzerinde arama yapılacak karaketer dizisi
* @param		{const char*}	search_value	source içerisinde arama yapılacak olan karakterler dizisi
* @param		{const int}		ignore_case		0 olması durumunda büyük, küçük karakter durumuna bakılmaz diğer durumlarda büyük, küçük harf duyarlı olur.
* @description	source karakter dizisinin baştaki öğeleri arasında search_value ile gönderilen karakter dizisi aranır.
* @returns		karakterler uyuşuyorsa 0 aksi durumlarda -1
*/
int str_startswith(const char* source, const char* search_value, const int ignore_case)
{
	const size_t source_len = strlen(source);
	const size_t search_len = strlen(search_value);

	if (search_len > source_len || search_len == 0 && source_len > 0) {
		return -1;
	}
	size_t counter = 0;
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
	const size_t source_len = strlen(source);
	const size_t search_len = strlen(search_value);

	if (search_len > source_len || search_len == 0 && source_len > 0) {
		return -1;
	}
	const char *ptemp = source + (source_len - search_len);
	size_t counter = 0;
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
 * @param			{const size_t}	totalwidth		sol başa eklenecek toplam karakter uzunluğu 
 * @param			{char}			pdchr			sol başa eklenecek karakter
 * @description		totalwidth, source dizisinin öğe sayısından büyükse source yazısının sol tarafına aradaki fark kadar pdchr karakterini ekler.
 * returns			başarılı olması durumunda yeni bir char dizisi adresi onun dışındaki durumlarda NULL pointer
 */
char *str_padleft(const char *source,const size_t totalwidth, const char pdchr)
{
	const size_t source_len = strlen(source);
	if (source_len >= totalwidth) return NULL;

	const size_t size = totalwidth - source_len;
	char *nstr; 
	if((nstr = (char*)malloc(source_len + size + 1))==NULL) return NULL;

	size_t k;
	for(k = 0; k < size; ++k)
		nstr[k] = pdchr;

	nstr[k] = '\0';
	return strcat(nstr, source);
}
/*
* @param			{const char*}	source			sol tarafına ekleme yapılacak olan karekterler dizisi
* @param			{const size_t}	totalwidth		sol başa eklenecek toplam karakter uzunluğu
* @param			{char}			pdchr			sol başa eklenecek karakter
* @description		totalwidth, source dizisinin öğe sayısından büyükse source yazısının sağ tarafına aradaki fark kadar pdchr karakterini ekler.
* returns			başarılı olması durumunda yeni bir char dizisi adresi onun dışındaki durumlarda NULL pointer
*/
char *str_padright(const char * source, const size_t totalwidth, const char pdchr)
{

	const size_t source_len = strlen(source);
	if (source_len >= totalwidth) return NULL;

	const size_t size = totalwidth - source_len;
	char *nstr;
	if ((nstr = (char*)malloc(source_len + size + 1)) == NULL) return NULL;

	size_t k = 0;

	for (; k < source_len; ++k)
		nstr[k] = source[k];

	const size_t tempk = k;
	k = 0;

	for (; k < size; ++k)
		nstr[tempk + k] = pdchr;

	nstr[tempk + k] = '\0';
	return  nstr;
}
/*
 * @param			{const char * source}			source			kaynak char dizi adresi
 * @param			{const char * insert_value}		insert_value	kaynak char dizisine eklenecek olan char dizisi
 * @param			{const size_t startpos}	startpos		eklemenin yapılacağı başlangıç pozisyonu
 * @description		startpos parametresi ile gönderilen pozisyondan başlayarak insert_value ilen gelen char dizisini ekler.
 * @returns			Başarılı olması durumunda yeni bir char dizisi adresi aksi durumda NULL pointer.
 */
char *str_insert(const char * source, const char * insert_value, const size_t startpos)
{
	const size_t source_len = strlen(source);
	const size_t insert_len = strlen(insert_value);

	char *nstr;
	if((nstr = (char*)malloc(source_len + insert_len + 1))==NULL) return  NULL;

	memcpy(nstr, source, startpos);
	nstr[startpos] = '\0';
	strcat(nstr, insert_value);
	return strcat(nstr, source + startpos);
}
/*
 * @param			{const char * source}		source		kaynak char dizi adresi
 * @param			{const size_t start}	start		silinmeye başlanacak pozisyon
 * @param			{const size_t count}	count		silinecek karakter sayısı
 * @description		kaynak char dizisi içerisinde belirtilen uzunlukta karakter siler.
 * @returns			Başarılı olması durumunda yeni bir char dizisi adresi aksi durumda NULL pointer.
 */
char *str_remove(const char * source, const size_t start, const size_t count)
{
	const size_t source_len = strlen(source);
	char *nstr;
	if ((nstr = (char*)malloc(source_len - count + 1)) == NULL) return  NULL;

	memcpy(nstr, source,source_len + 1);
	nstr[start] = '\0';
	if (strlen(source) == start + count) return nstr;

	strcat(&nstr[start], &source[start + count]);
	nstr[source_len - count] = '\0';
	return nstr;
}
/*
 * @param			{const char* source}		source		kaynak char dizi adresi
 * @param			{const char find_chr}		find_chr	kaynak char dizisi içerisinde arama yapılacak olan karakter
 * @param			{const char rep_chr}		rep_chr		find_chr karakteri ile eşleşen karakterlerin yerine yazılacak karakter
 * @description		kaynak char dizisi içerinde aranan karakterleri bulup yerlerine rep_chr ile gönderilen karaketeri yazar.
 * @returns			Başarılı olması durumunda yeni bir char dizisi adresi aksi durumda NULL pointer. 
 */
char *str_replace(const char* source, const char find_chr, const char rep_chr)
{
	const size_t source_len = strlen(source);
	char *nstr;
	if((nstr = (char*)malloc(source_len))==NULL) return  NULL;

	memcpy(nstr, source,source_len + 1);

	for(size_t k = 0; k < nstr[k] != '\0';++k)
		if (nstr[k] == find_chr) 
			nstr[k] = rep_chr;

	return nstr;
}
/*
 * @param		{const char* source}			source		arama yapılacak kaynak char dizi adresi
 * @param		{const char *trimchrs}			trimchrs	source içerisinde aranacak olan karakterler dizisi adresi
 * @param		{const size_t size}				size		trimchrs parametresi ile gelen karakter dizisinin uzunluğu
 * @description	source kaynak dizisinin başında ve sonunda trimchrs ile gönderilen karakterleri arar ve bulunan karakterlerin olmadığı yeni bir char dizisi adresi geriye döner.
 * trimchrs ile silinmesi istenilen karakterler source dizisinin başında ve sonunda yoksa source dizisinin adresini döner.
 * @returns		yeni bir char dizisi adresi. herhangi bir değişilik yapılmayacaksa source' un adresi.
 */
char *str_trim(const char* source, const char *trimchrs, const size_t size)
{
	const size_t source_len = strlen(source);
	size_t start = 0, end = source_len - 1;

	for (; start < source_len; ++start)
	{
		size_t i;
		const char chr = source[start];

		for (i = 0; i < size; ++i)
			if (trimchrs[i] == chr) break;

		if (i == size) break;
	}
	for (; end >= start; --end)
	{
		size_t i;
		const char chr = source[end];

		for (i = 0; i < size; ++i)
			if (trimchrs[i] == chr) break;

		if (i == size) break;
	}

	const size_t nlen = end - start + 1;
	if (nlen == source_len) return (char*)source;

	char *nstr;
	if ((nstr = (char*)malloc(nlen)) == NULL) return  NULL;

	memcpy(nstr, source + start, nlen);
	nstr[nlen] = '\0';
	return  nstr;
}
/*
* @param		{const char* source}			source		arama yapılacak kaynak char dizi adresi
* @param		{const char *trimchrs}			trimchrs	source içerisinde aranacak olan karakterler dizisi adresi
* @param		{const size_t size}				size		trimchrs parametresi ile gelen karakter dizisinin uzunluğu
* @description	source kaynak dizisinin başında trimchrs ile gönderilen karakterleri arar ve bulunan karakterlerin olmadığı yeni bir char dizisi adresi geriye döner.
* trimchrs ile silinmesi istenilen karakterler source dizisinin başında yoksa source dizisinin adresini döner.
* @returns		yeni bir char dizisi adresi. herhangi bir değişilik yapılmayacaksa source' un adresi.
*/
char *str_trimstart(const char* source, const char* trimchrs, const size_t size)
{
	const size_t source_len = strlen(source);
	size_t start = 0;
	for(;start < source_len;++start)
	{
		size_t i;
		const char chr = source[start];

		for (i = 0; i < size; ++i)
			if (trimchrs[i] == chr) break;

		if (i == size) break;
	}
	const size_t nlen = source_len - start;
	if (nlen == source_len) return (char*)source;

	char *nstr;
	if((nstr = (char*)malloc(nlen)) == NULL) return  NULL;

	memcpy(nstr, source + start, nlen);
	nstr[nlen] = '\0';
	return  nstr;
}
/*
* @param		{const char* source}			source		arama yapılacak kaynak char dizi adresi
* @param		{const char *trimchrs}			trimchrs	source içerisinde aranacak olan karakterler dizisi adresi
* @param		{const size_t size}				size		trimchrs parametresi ile gelen karakter dizisinin uzunluğu
* @description	source kaynak dizisinin sonunda trimchrs ile gönderilen karakterleri arar ve bulunan karakterlerin olmadığı yeni bir char dizisi adresi geriye döner.
* trimchrs ile silinmesi istenilen karakterler source dizisinin soununda yoksa source dizisinin adresini döner.
* @returns		yeni bir char dizisi adresi. herhangi bir değişilik yapılmayacaksa source' un adresi.
*/
char *str_trimend(const char* source, const char* trimchrs, const size_t size)
{
	const size_t source_len = strlen(source);
	size_t end = source_len;
	while(--end)
	{
		size_t i;
		const char chr = source[end - 1];

		for (i = 0; i < size; ++i)
			if (trimchrs[i] == chr) break;

		if (i == size) break;
	}
	if (end == source_len) return (char*)source;

	char *nstr;
	if((nstr = (char*)malloc(end + 1)) == NULL) return  NULL;

	memcpy(nstr, source, end + 1);
	nstr[end] = '\0';
	return  nstr;
}
/*
 * @param		{const char *source}		source			kaynak char dizi adresi
 * @param		{const int start_index}		start_index		bölünmeye başlanacak indis numarası
 * @param		{length}					length			bölünecek char dizisinin uzunluğu
 * @description	source ile adresini gösterdiği char dizisinde start_index' e denk gelen indisinden length ile belirtilen uzunluk kadar char alınır length 0 ise start_index' ten başlayarak
 * geriye kalan tüm karakterler eklenir.
 * @returns		yeni bir char dizisi adresi. istenilen uzunluk değerleri source ile gelen değerin uzunluğundan büyükse veya eşitse source' un kendi adresi 
 */
char *str_substring(const char *source, const size_t start_index, const size_t length)
{
	const size_t source_len = strlen(source);
	if (source_len < start_index + length) return NULL;

	const size_t size = length == 0 ? (source_len - start_index) : length;
	if (size == source_len) return (char*)source;

	char *nstr;
	if ((nstr = (char*)malloc(size)) == NULL) return  NULL;

	memcpy(nstr, &source[start_index], size);
	nstr[size] = '\0';
	return  nstr;
}

char * str_toupper(const char * source)
{
	return toupper_or_tolower(source, 2);
}

 char * str_tolower(const char * source)
 {
	 return toupper_or_tolower(source, 1);
 }

 static char * toupper_or_tolower(const char * source, const size_t lou)
 {
	 const size_t source_len = strlen(source);
	 char *nstr;
	 if ((nstr = (char*)malloc(source_len)) == NULL) return NULL;

	 size_t counter = 0;
	 while (source_len > counter)
	 {
		 nstr[counter] = lou == 2 ? toupper(source[counter]) : tolower(source[counter]);
		 ++counter;
	 }
	 nstr[source_len] = '\0';
	 return nstr;
 }
