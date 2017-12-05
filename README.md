# voltron
C# string extension methodlarının C diline implementasyonu


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
