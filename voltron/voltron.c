#pragma warning(disable:4996)
#include "voltron.h"
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
	if(ignore_case)	{
		return memcmp(source, search_value, search_len);
	}
	size_t k = 0;
	for (; k < search_len && toupper(source[k]) == toupper(search_value[k]); ++k);
	return  k == search_len ? 0 : -1;
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
	if(ignore_case)	{
		return memcmp(&source[source_len - search_len], search_value, search_len);
	}
	size_t k = source_len - search_len,s = 0;
	for (; k != source_len && toupper(source[k]) == toupper(search_value[s]); ++k, ++s);
	return k == source_len ? 0 : -1;
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
	if (source_len >= totalwidth) return (char*)source;

	const size_t size = totalwidth - source_len;
	char *nstr; 
	if((nstr = (char*)malloc(source_len + size + 1))==NULL) return NULL;

	size_t k;
	for(k = 0; k < size; ++k)
		nstr[k] = pdchr;

	nstr[k] = '\0';
	return strcat(nstr, source);
}
void str_padleft_ip(char * source, const size_t totalwidth, const char pdchr)
{

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
	if (source_len >= totalwidth) return (char*)source;

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

void str_padright_ip(char * source, const size_t totalwidth, const char pdchr)
{
	const size_t source_len = strlen(source);
	if (source_len >= totalwidth) return;
	memset(source + source_len +1, pdchr, totalwidth - (source_len - 1));
	source[totalwidth - 1] = '\0';
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


/*
 *	@param			{const int *source}					source			Arama yapılacak olan int dizisinin adresi
 *  @param			{const struct condition condition}	condition		Arama yapılacak kriter
 *	@param			{const size_t source_size}			source_size		Source adresinin gösterdiği dizinin eleman sayısı
 *	@param			{size_t *return_size}				*return_size	Fonsiyonun geri döndüğü int dizisinin eleman sayısı
 *	@description	Kaynak dizi içerisinde condition ile gönderilen parametreye uygun şekilde arama yapar.
 *	@returns		Kritlere uygun aranan tüm değerleri çıkararak dinamik oluşturulan yeni int dizisi adresinde geriye döner.
 *	Aranan değerin bulunmaması durumunda geriye kaynak int dizisinin adresini bellek yetersiz olduğu durumda ise NULL pointer.
 */
int *int_removeall(const int *source, const struct condition condition, const size_t source_size, size_t *return_size)
 {
	 size_t counter = 0;
	 size_t temp = 0;
	 int *narray = NULL;

	 switch (condition.predicate) {
	 case LESS_THAN:
		 for (size_t k = 0; k < source_size; ++k)
			 if (source[k] < condition.predicate_value)
				 ++counter;

		 if (counter == 0) return  (int*)source;
		 if ((narray = (int*)malloc(counter * sizeof(int))) == NULL) return NULL;

		 temp = counter;
		 *return_size = counter;
		 counter = 0;

		 for (size_t k = 0; k < source_size; ++k) {
			 if (source[k] < condition.predicate_value) {
				 narray[counter++] = source[k];
				 if (temp == counter) break;
			 }
		 }
		 return narray;
	 case LESS_THAN_OR_EQUAL:
		 for (size_t k = 0; k < source_size; ++k)
			 if (source[k] <= condition.predicate_value)
				 ++counter;

		 if (counter == 0) return  (int*)source;
		 if ((narray = (int*)malloc(counter * sizeof(int))) == NULL) return NULL;

		 temp = counter;
		 *return_size = counter;
		 counter = 0;

		 for (size_t k = 0; k < source_size; ++k) {
			 if (source[k] <= condition.predicate_value) {
				 narray[counter++] = source[k];
				 if (temp == counter) break;
			 }
		 }
		 return narray;
	 case GREATER:
		 for (size_t k = 0; k < source_size; ++k)
			 if (source[k] > condition.predicate_value)
				 ++counter;

		 if (counter == 0) return  (int*)source;
		 if ((narray = (int*)malloc(counter * sizeof(int))) == NULL) return NULL;

		 temp = counter;
		 *return_size = counter;
		 counter = 0;

		 for (size_t k = 0; k < source_size; ++k) {
			 if (source[k] > condition.predicate_value) {
				 narray[counter++] = source[k];
				 if (temp == counter) break;
			 }
		 }
		 return narray;
	 case GREATER_THAN_EQUAL:
		 for (size_t k = 0; k < source_size; ++k)
			 if (source[k] >= condition.predicate_value)
				 ++counter;

		 if (counter == 0) return  (int*)source;
		 if ((narray = (int*)malloc(counter * sizeof(int))) == NULL) return NULL;

		 temp = counter;
		 *return_size = counter;
		 counter = 0;

		 for (size_t k = 0; k < source_size; ++k) {
			 if (source[k] >= condition.predicate_value) {
				 narray[counter++] = source[k];
				 if (temp == counter) break;
			 }
		 }
		 return narray;
	 case NOT_EQUAL:
		 for (size_t k = 0; k < source_size; ++k)
			 if (source[k] != condition.predicate_value)
				 ++counter;

		 if (counter == 0) return  (int*)source;
		 if ((narray = (int*)malloc(counter * sizeof(int))) == NULL) return NULL;
		 temp = counter;
		 *return_size = counter;
		 counter = 0;

		 for (size_t k = 0; k < source_size; ++k) {
			 if (source[k] != condition.predicate_value) {
				 narray[counter++] = source[k];
				 if (temp == counter) break;
			 }
		 }
		 return narray;
	 default:;
	 }
	 return narray;
 }
/*
  *	@param			{const int *source}				source			Arama yapılacak olan int dizisinin adresi
  *	@param			{const size_t source_size}		source_size		Source adresinin gösterdiği dizinin eleman sayısı
  *	@param			{const int rvalue}				rvalue			Arama yapılacak değer
  *	@param			{size_t *return_size}			*return_size	Fonsiyonun geri döndüğü int dizisinin eleman sayısı
  *	@description	Kaynak dizi içerisinde aranan ilk değeri çıkararak diğer tüm elemanlarını dinamik oluşturulan bir diziye ekler.
  *	@returns		Aranan değer bulunması durumunda ilk bulduğu değer hariçindeki diğer tüm elemanları dinamik oluşturulan int dizisi adresinde geriye döner. 
  *	Aranan değerin bulunmaması durumunda geriye kaynak int dizisinin adresini bellek yetersiz olduğu durumda ise NULL pointer.
  */
int * int_remove(const int *source, const size_t source_size, const int rvalue, size_t *return_size)
 {
	 size_t k = 0;
	 for (; k < source_size && source[k] != rvalue; ++k);

	 if (k == source_size)
	 {
		 *return_size = source_size;
		 return (int*)source;
	 }

	 *return_size = source_size - 1;

	 int *narray = NULL;
	 if ((narray = (int*)malloc((source_size - 1) * sizeof(int))) == NULL) return NULL;
	 
	 memcpy(narray, source , k * sizeof(int));
	 memcpy(narray + k, source + k + 1, (*return_size - k) * sizeof(int));
	 
	 return narray;
 }
