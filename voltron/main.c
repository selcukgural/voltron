#pragma  warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>

#include "vstring.h"
#include "vassert.h"

int main() {

////str_endswith
	//assert_equal_int(str_endswith("selamlar nasilsin nasil gidiyoR", "GiDiYOr", 1), -1, __LINE__);
	//assert_equal_int(str_endswith("selamlar nasilsin nasil gidiyoR", "GiDiYOr", 0), 0, __LINE__);
	//assert_equal_int(str_endswith("  ", "", 1), -1, __LINE__); 
	//assert_equal_int(str_endswith("  ", " ", 1), 0, __LINE__);
	//assert_equal_int(str_endswith("merhaba dunya", "  dunya", 1), -1, __LINE__);
	//assert_equal_int(str_endswith("merhaba dunya", " dunya ", 1), -1, __LINE__);
	//assert_equal_int(str_endswith("merhaba dunya", "Dunya", 0), 0, __LINE__);
////end str_endswith

////str_startswith
	//assert_equal_int(str_startswith("merhaba dunya", "mer", 0), 0, __LINE__);
	//assert_equal_int(str_startswith("merhaba dunya", "Mer", 1), -1, __LINE__);
	//assert_equal_int(str_startswith("merhaba dunya", "MerHABA ", 0), 0, __LINE__);
	//assert_equal_int(str_startswith("merhaba dunya", "MerHABA ", 1), -1, __LINE__);
	//assert_equal_int(str_startswith("  dunya", " ", 0), 0, __LINE__);
	//assert_equal_int(str_startswith("  ", "", 0), -1, __LINE__);
////end str_starswith

////str_padright
	//assert_equal_str(str_padright("11", 4, '0'), "1100", __LINE__);
	//assert_equal_str(str_padright("Turkiy", 7, 'e'), "Turkiye", __LINE__);
////end str_padright

////str_padleft
	//assert_equal_str(str_padleft("11", 4, '0'), "0011", __LINE__);
	//assert_equal_str(str_padleft("22", 4, '1'), "1122", __LINE__);
////end str_padleft

////str_insert
	//assert_equal_str(str_insert("lma", "e", 0), "elma", __LINE__);
	//assert_equal_str(str_insert("la", "la", 1), "llaa", __LINE__);
	//assert_equal_str(str_insert("merhaba dunya", "rr", 3), "merrrhaba dunya", __LINE__);
	//assert_equal_str(str_insert("selam", "lma", 2), "selmalam", __LINE__);
////end str_insert

////str_remove
	//assert_equal_str(str_remove("selamlar nasilsin", 5, 3), "selam nasilsin", __LINE__);
	//assert_equal_str(str_remove("nbrsin", 3, 3), "nbr", __LINE__);
	//assert_equal_str(str_remove("hava nasil oralarda", 14, 3), "hava nasil orada", __LINE__);
	//assert_equal_str(str_remove("hav hav", 0, 4), "hav", __LINE__);
////end str_remove

////str_replace
	//assert_equal_str(str_replace("ah bu ben", 'h', 'y'), "ay bu ben", __LINE__);
	//assert_equal_str(str_replace("ah bu ben", ' ', '|'), "ah|bu|ben", __LINE__);
	//assert_equal_str(str_replace("sen ve ben", 's', 'b'), "ben ve ben", __LINE__);
	//assert_equal_str(str_replace("nasil gidiyor.", '.', '?'), "nasil gidiyor?", __LINE__);
	//assert_equal_str(str_replace("vallah", 'v', 'y'), "yallah", __LINE__);
////end str_replace


////str_trim
	/*
	//char chrs1[1] = { 'r' };
	//assert_equal_str(str_trim("rehber", chrs1,1), "ehbe", __LINE__);
	//
	//char chrs2[3] = { 'a','r','n' };
	//assert_equal_str(str_trim("nasil gidiyor", chrs2, 3), "sil gidiyo", __LINE__);

	//char chrs3[1] = { ' '};
	//assert_equal_str(str_trim("    hava da tam kar havasi ha!      ", chrs3, 1), "hava da tam kar havasi ha!", __LINE__);


	//char chrs4[4] = { 'a',' ','c','g' };
	//assert_equal_str(str_trim("    a bcdef   g   a", chrs4, 4), "bcdef", __LINE__);
*/
////end str_trim

////str_trimtstart
	/*
	char chrs1[1] = { 'n' };
	assert_equal_str(str_trimstart("nasil gidiyor", chrs1, 1), "asil gidiyor", __LINE__);

	char chrs2[4] = { ' ','c','k','o' };
	assert_equal_str(str_trimstart("cok yorgunum beni bekleme kaptan!", chrs2, 4), "yorgunum beni bekleme kaptan!", __LINE__);

	char chrs3[1] = { ' '};
	assert_equal_str(str_trimstart(" bir sevmek bin defa olmekmis!", chrs3, 1), "bir sevmek bin defa olmekmis!", __LINE__);

	char chrs4[4] = { '*',' ','?','/' };
	assert_equal_str(str_trimstart("? / *gecenin ucunde ? *", chrs4, 4), "gecenin ucunde ? *", __LINE__);

	char chrs5[1] = { '.'};
	assert_equal_str(str_trimstart("...gitmemesi gerekiyordu.", chrs5, 1), "gitmemesi gerekiyordu.", __LINE__);
	*/
////end str_trimstart


////str_trimend
	/*
	char chrs1[1] = { 'r' };
	assert_equal_str(str_trimend("nasil gidiyor", chrs1, 1), "nasil gidiyo", __LINE__);

	char chrs2[] = { '!',' ' };
	assert_equal_str(str_trimend("onumden cekilirsen istanbul gorunecek  !  ", chrs2, 2), "onumden cekilirsen istanbul gorunecek", __LINE__);

	char chrs3[] = {  '~',' ' };
	assert_equal_str(str_trimend("master of the wind ~", chrs3, 2), "master of the wind", __LINE__);

	char chrs4[] = { '.'};
	assert_equal_str(str_trimend("...ustalastik biraz daha tasi kirmakta, dostu dusmani ayirmakta...", chrs4, 1), "...ustalastik biraz daha tasi kirmakta, dostu dusmani ayirmakta", __LINE__);

	char chrs5[] = { 'h','e','p','.' ,' '};
	assert_equal_str(str_trimend("bir hisimla geldi gecti peh peh peh...", chrs5, 5), "bir hisimla geldi gecti", __LINE__);
	*/
////end str_trimend
	system("pause");
	return 0;
}
