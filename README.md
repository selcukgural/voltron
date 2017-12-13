# voltron
C dilinde kendimi geliştirebilmek adına yaptığım yaparken de C# dan esinlendiğim çalışmam...


## str_startswith
```C
int str_startswith(const char* source, const char* search_value, const int ignore_case);
```
Geriye _**boolean int**_ döner. 0 ise başarılı diğer tüm değerler başarısız anlamında.
```C
str_startswith("merhaba dunya", "mer", 0);// true zero
str_startswith("  dunya", " ", 0); //true zero
str_startswith("merhaba dunya", "MerHABA ", 0); //true zero

str_startswith("Rock' In the free world!", "Rock ", 1); //false non zero
str_startswith("kim demiş su olmaz kim demis bu olmaz. kim yazmis kanunlari kim yazmis kitabi?", "Kim", 1);//false non zero
str_startswith("merhaba dunya", "MerHABA ", 1); //false non zero
```

## str_endwith
```C
int str_endswith(const char *source, const char *search_value, const int ignore_case);
```
Geriye _**boolean int**_ döner. 0 ise başarılı diğer tüm değerler başarısız anlamında.
```C
str_endswith("neil young still rock!", " young still rock!", 1); //true zero
str_endswith("merhaba dunya", "Dunya", 0); //true zero
str_endswith("blahh blalh  ", " ", 0); //true zero

str_endswith("merhaba dunya", "  dunya", 0); //false non zero
str_endswith("merhaba dunya", " dunya ", 0); //false non zero
str_endswith("selamlar nasilsin nasil gidiyoR", "GiDiYOr", 1); //false non zero
```

## str_padright
```C
char *str_padright(const char *source, const size_t totalwidth, const char pdchr);
```
* Her şey yolundaysa geriye dinamik yaratılmış bir dizinin adresini döner.
* totalwidth, source ile gelen diziden uzunsa source' un adresi.
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
char *nstr1 = str_padright("11", 4, '0'); //"1100"
//
free(nstr1);

char *nstr2 = str_padright("Turkiy", 7, 'e'); //Turkiye
//
free(nstr2);
```

## str_padright_inplace
```C
void str_padright_inplace(char * source, const size_t totalwidth, const char pdchr);
```
* source char dizisini yerinde değiştirir
* totalwidth, source ile gelen diziden uzunsa source' un adresi.
```C
	char str1[7] = "selam";
	str_padright_inplace(str1, (size_t)6, (const char)'s');
	assert_equal_str(str1, "selams", __LINE__,"str_padright_inplace");

	char str2[17] = "dedi ve gitti";
	str_padright_inplace(str2, (size_t)16, (const char)'.');
	assert_equal_str(str2, "dedi ve gitti...", __LINE__,"str_padright_inplace");

	char str3[25] = "her sey sermaye icin...";
	str_padright_inplace(str3, (size_t)24, (const char)' ');
	assert_equal_str(str3, "her sey sermaye icin... ", __LINE__,"str_padright_inplace");


	char str4[10] = "##here";
	str_padright_inplace(str4, (size_t)8, (const char)'#');
	assert_equal_str(str4, "##here##", __LINE__,"str_padright_inplace");

	char str5[9] = "Manowar";
	str_padright_inplace(str5, (size_t)8, (const char)'#');
	assert_equal_str(str5, "Manowar#", __LINE__,"str_padright_inplace");
```

## str_padleft
```C
char *str_padleft(const char *source, const size_t totalwidth, const char pdchr);
```
* Her şey yolundaysa geriye dinamik yaratılmış bir dizinin adresini döner.
* totalwidth, source ile gelen diziden uzunsa source' un adresi.
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
char *nstr1 = str_padleft("11", 4, '0'); //"0011"
//
free(nstr1);

char *nstr2 = str_padleft("22", 4, '1'); //"1122"
//
free(nstr2);
```

## str_padleft_inplace_test
```C
void str_padleft_inplace(char * source, const size_t totalwidth, const char pdchr);
```
* source char dizisini yerinde değiştirir
* totalwidth, source ile gelen diziden uzunsa source' un adresi.
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
	char str1 [7]= "selam";
	str_padleft_inplace(str1,(size_t)6, (const char)'s');
	assert_equal_str(str1, "sselam", __LINE__,"str_padleft_inplace");

	char str2[17] = "dedi ve gitti";
	str_padleft_inplace(str2, (size_t)16, (const char)'.');
	assert_equal_str(str2, "...dedi ve gitti", __LINE__,"str_padleft_inplace");

	char str3[25] = "her sey sermaye icin...";
	str_padleft_inplace(str3, (size_t)24, (const char)' ');
	assert_equal_str(str3, " her sey sermaye icin...", __LINE__,"str_padleft_inplace");


	char str4[10] = "here##";
	str_padleft_inplace(str4, (size_t)8, (const char)'#');
	assert_equal_str(str4, "##here##", __LINE__,"str_padleft_inplace");

	char str5[9] = "Manowar";
	str_padleft_inplace(str5, (size_t)8, (const char)'#');
	assert_equal_str(str5, "#Manowar", __LINE__,"str_padleft_inplace");
```

## str_insert
```C
char *str_insert(const char *source, const char *insert_value, const size_t startpos);
```
* Her şey yolundaysa geriye dinamik yaratılmış bir dizinin adresini döner.
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
char *nstr1 = str_insert("lma", "e", 0); //"elma"
//
free(nstr1);

char *nstr2 = str_insert("merhaba dunya", "rr", 3); //"merrrhaba dunya"
//
free(nstr2);

char *nstr3 = str_insert("la", "la", 1); //llaa
//
free(nstr3);

char *nstr4 = str_insert("selam", "lma", 2); //"selmalam"
//
free(nstr4);
```

## str_remove
```C
char *str_remove(const char *source, const size_t start, const size_t count);
```
* Her şey yolundaysa geriye dinamik yaratılmış bir dizinin adresini döner.
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
char *nstr1 = str_remove("hava nasil oralarda", 14, 3); //"hava nasil orada"
//
free(nstr1);

char *nstr2 = str_remove("hav hav", 0, 4); //"hav"
//
free(nstr2);

char *nstr3 = str_remove("nbrsin", 3, 3); //"nbr"
//
free(nstr3);

char *nstr4 = str_remove("selamlar nasilsin", 5, 3); //"selam nasilsin"
//
free(nstr4);
```

## str_replace
```C
char *str_replace(const char *source, const char chr, const char rep_chr);
```
* Her şey yolundaysa geriye dinamik yaratılmış bir dizinin adresini döner.
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
char *nstr1 = str_replace("ah bu ben", 'h', 'y'); //"ay bu ben"
//
free(nstr1);

char *nstr2 = str_replace("ah bu ben", ' ', '|'); //"ah|bu|ben"
//
free(nstr2);

char *nstr3 = str_replace("sen ve ben", 's', 'b'); //"ben ve ben"
//
free(nstr3);

char *nstr4 = str_replace("nasil gidiyor.", '.', '?'); //"nasil gidiyor?"
//
free(nstr4);

char *nstr5 = str_replace("vallah", 'v', 'y'); //"yallah"
//
free(nstr5);
```

## str_trim
```C
char *str_trim(const char *source, const char *trimchrs, const size_t size);
```
* Her şey yolundaysa geriye dinamik yaratılmış bir dizinin adresini döner.
* Trim edilecek herhangi bir karakter bulunamamışsa _source_ ile gelen değer
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
char chrs1[1] = { 'r' };
char *nstr1 = str_trim("rehber", chrs1, 1); //"ehbe"
//
free(nstr1);

char chrs2[3] = { 'a','r','n' };
char *nstr2 = str_trim("nasil gidiyor", chrs2, 3); //"sil gidiyo"
//
free(nstr2);

char chrs3[1] = { ' ' };
char *nstr3 = str_trim("    hava da tam kar havasi ha!      ", chrs3, 1); //"hava da tam kar havasi ha!"
//
free(ntsr3);

char chrs4[4] = { 'a',' ','c','g' };
char *nstr3 = str_trim("    a bcdef   g   a", chrs4, 4); //"bcdef"
//
free(nstr3);
```

## str_trimstart
```C
char *str_trimstart(const char* source, const char* trimchrs, const size_t size);
```
* Her şey yolundaysa geriye dinamik yaratılmış bir dizinin adresini döner.
* Baştan trim edilecek herhangi bir karakter bulunamamışsa _source_ ile gelen değer
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
char chrs1[1] = { 'n' };
char *nstr1 = str_trimstart("nasil gidiyor", chrs1, 1); //"asil gidiyor"
//
free(nstr1);

char chrs2[4] = { ' ','c','k','o' };
char *nstr2 = str_trimstart("cok yorgunum beni bekleme kaptan!", chrs2, 4); //"yorgunum beni bekleme kaptan!"
//
free(nstr2);

char chrs3[1] = { ' ' };
char *nstr3 = str_trimstart(" bir sevmek bin defa olmekmis!", chrs3, 1); //"bir sevmek bin defa olmekmis!"
//
free(nstr3);

char chrs4[4] = { '*',' ','?','/' };
char *nstr4 = str_trimstart("? / *gecenin ucunde ? *", chrs4, 4); //"gecenin ucunde ? *"
//
free(nstr4);

char chrs5[1] = { '.' };
char *nstr5 = str_trimstart("...gitmemesi gerekiyordu.", chrs5, 1); //"gitmemesi gerekiyordu."
//
free(nstr5);
```

## str_trimend
```C
char *str_trimend(const char *source, const char *trimchrs, const size_t size);
```
* Her şey yolundaysa geriye dinamik yaratılmış bir dizinin adresini döner.
* Sondan trim edilecek herhangi bir karakter bulunamamışsa _source_ ile gelen değer
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
char chrs1[1] = { 'r' };
char *nstr1 = str_trimend("nasil gidiyor", chrs1, 1); //"nasil gidiyo"
//
free(nstr1);

char chrs2[] = { '!',' ' };
char *nstr2 = str_trimend("onumden cekilirsen istanbul gorunecek  !  ", chrs2, 2); //"onumden cekilirsen istanbul gorunecek"
//
free(nstr2);

char chrs3[] = { '~',' ' };
char *nstr3 = str_trimend("master of the wind ~", chrs3, 2); //"master of the wind"
//
free(nstr3);

char chrs4[] = { '.' };
char *nstr4 = str_trimend("...ustalastik biraz daha tasi kirmakta, dostu dusmani ayirmakta...", chrs4, 1); //"...ustalastik biraz daha tasi kirmakta, dostu dusmani ayirmakta"
//
free(nstr4);

char chrs5[] = { 'h','e','p','.' ,' ' };
char *nstr5 = str_trimend("bir hisimla geldi gecti peh peh peh...", chrs5, 5); //"bir hisimla geldi gecti"
//
free(nstr5);
```

## str_substring
```C
char *str_substring(const char *source, const size_t start_index, const size_t length);
```
* Her şey yolundaysa geriye dinamik yaratılmış bir dizinin adresini döner.
* start_index ve length toplamı source' un length den uzunca _NULL_ pointer
* Substring edilecek bir durum yoksa char *source
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
char *nstr1 = str_substring("anacim",0,3); //"ana"
//
free(nstr1);

char *nstr2 = str_substring("Yapraklarim suda balik gibi kivil kivil", 12, 15); //"suda balik gibi"
//
free(nstr2);


char *nstr3 = str_substring("amacim kimseyi kirmak degildi, yanlis anlasildim!", 31, 0); //"yanlis anlasildim!"
//
free(nstr3);


char *nstr4 = str_substring("drama koprusu", 0, 2); //"dr"
//
free(nstr4);
```

## str_toupper
```C
char *str_toupper(const char *source);
```
* Her şey yolundaysa geriye dinamik yaratılmış bir dizinin adresini döner.
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
char *nstr1 = str_toupper("baris manco"), //"BARIS MANCO"
//
free(nstr1);

char *nstr2 = str_toupper("dunyada biraz huzur herseye bedel...ilac neye yarar vade gelmisse eger"); //"DUNYADA BIRAZ HUZUR HERSEYE BEDEL...ILAC NEYE YARAR VADE GELMISSE EGER"
//
free(nstr2);


char *nstr3 = str_toupper("sELaMlaR"); //"SELAMLAR"
//
free(nstr3);


char *nstr4 = str_substring("drama koprusu", 0, 2); //"dr"
//
free(nstr4);
```

## str_tolower
```C
char *str_tolower(const char *source);
```
* Her şey yolundaysa geriye dinamik yaratılmış bir dizinin adresini döner.
* Belleğin yetersiz olması durumunda _NULL_ pointer
```C
char *nstr1 = str_tolower("SELAMLAR"); //"selamlar"
//
free(nstr1);

char *nstr2 = str_tolower("HAYAT baYRam Olsa"); //"hayat bayram olsa"
//
free(nstr2);


char *nstr3 = str_tolower("olmadi ama"); //"olmadi ama"
//
free(nstr3);
```
