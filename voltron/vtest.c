#include <stdlib.h>
#include "voltron.h"
#include "vassert.h"
#include "vtest.h"


static void str_endswith_test(void);
static void str_startswith_test(void);
static void str_padright_test(void);
static void str_padleft_test(void);
static void str_insert_test(void);
static void str_remove_test(void);
static void str_replace_test(void);
static void str_trim_test(void);
static void str_trimstart_test(void);
static void str_trimend_test(void);
static void str_substring_test(void);
static void str_tolower_test(void);
static void str_toupper_test(void);
static void str_padleft_inplace_test(void);
static void str_padright_inplace_test(void);

static void int_removeall_test(void);
static void int_remove_test(void);


void run_all_str_tests(void)
{
	str_trim_test();	
	str_trimstart_test();
	str_trimend_test();
	str_endswith_test();
	str_startswith_test();
	str_padright_test();
	str_padleft_test();
	str_insert_test();
	str_remove_test();
	str_replace_test();
	str_substring_test();
	str_tolower_test();
	str_toupper_test();
	str_padleft_inplace_test();
	str_padright_inplace_test();
}
void run_all_int_tests(void)
{
	int_removeall_test();
	int_remove_test();
}





void str_endswith_test(void)
{
	assert_notequal_int(str_endswith("merhaba dunya", "  dunya", 1), 0, __LINE__,"str_endswith");
	assert_notequal_int(str_endswith("merhaba dunya", " dunya ", 1), 0, __LINE__,"str_endswith");
	assert_notequal_int(str_endswith("selamlar nasilsin nasil gidiyoR", "GiDiYOr", 1), 0, __LINE__,"str_endswith");
	assert_notequal_int(str_endswith("selamlar nasilsin nasil gidiyoR", "GiDiyOr", 1), 0, __LINE__,"str_endswith");
	assert_notequal_int(str_endswith("  ", "", 1), 0, __LINE__,"str_endswith");


	assert_equal_int(str_endswith("blahh blalh  ", " ", 1), 0, __LINE__,"str_endswith");
	assert_equal_int(str_endswith("...", ".", 1), 0, __LINE__,"str_endswith");
	assert_equal_int(str_endswith("merhaba dunya", "Dunya", 0), 0, __LINE__,"str_endswith");
	assert_equal_int(str_endswith("neil young still rock!", " young still rock!", 1), 0, __LINE__,"str_endswith");
}

void str_startswith_test(void)
{
	assert_notequal_int(str_startswith("Rock' In the free world!", "Rock ", 1), 0, __LINE__,"str_startswith");
	assert_notequal_int(str_startswith("kim demis su olmaz kim demis bu olmaz. kim yazmis kanunlari kim yazmis kitabi?", "Kim", 1), 0, __LINE__,"str_startswith");

	assert_equal_int(str_startswith("merhaba dunya", "mer", 0), 0, __LINE__,"str_startswith");
	assert_equal_int(str_startswith("merhaba dunya", "Mer", 1), 1, __LINE__,"str_startswith");
	assert_equal_int(str_startswith("merhaba dunya", "MerHABA ", 0), 0, __LINE__,"str_startswith");
	assert_equal_int(str_startswith("merhaba dunya", "MerHABA ", 1), 1, __LINE__,"str_startswith");
	assert_equal_int(str_startswith("  dunya", " ", 0), 0, __LINE__,"str_startswith");
	assert_equal_int(str_startswith("selam", "selam",1), 0, __LINE__,"str_startswith");
	assert_equal_int(str_startswith("  ", "", 0), -1, __LINE__,"str_startswith");

}

void str_padright_test(void)
{
	assert_equal_str(str_padright("11", 4, '0'), "1100", __LINE__,"str_padright");
	assert_equal_str(str_padright("Turkiy", 7, 'e'), "Turkiye", __LINE__, "str_padright");
}

void str_padleft_test(void)
{
	assert_equal_str(str_padleft("11", 4, '0'), "0011", __LINE__,"str_padleft");
	assert_equal_str(str_padleft("22", 4, '1'), "1122", __LINE__,"str_padleft");
}

void str_insert_test(void)
{
	assert_equal_str(str_insert("lma", "e", 0), "elma", __LINE__,"str_insert");
	assert_equal_str(str_insert("la", "la", 1), "llaa", __LINE__,"str_insert");
	assert_equal_str(str_insert("merhaba dunya", "rr", 3), "merrrhaba dunya", __LINE__,"str_insert");
	assert_equal_str(str_insert("selam", "lma", 2), "selmalam", __LINE__, "str_insert");
}

void str_remove_test(void)
{
	assert_equal_str(str_remove("selamlar nasilsin", 5, 3), "selam nasilsin", __LINE__,"str_remove");
	assert_equal_str(str_remove("nbrsin", 3, 3), "nbr", __LINE__,"str_remove");
	assert_equal_str(str_remove("hava nasil oralarda", 14, 3), "hava nasil orada", __LINE__, "str_remove");
	assert_equal_str(str_remove("hav hav", 0, 4), "hav", __LINE__,"str_remove");
}

void str_replace_test(void)
{
	assert_equal_str(str_replace("ah bu ben", 'h', 'y'), "ay bu ben", __LINE__,"str_replace");
	assert_equal_str(str_replace("ah bu ben", ' ', '|'), "ah|bu|ben", __LINE__,"str_replace");
	assert_equal_str(str_replace("sen ve ben", 's', 'b'), "ben ve ben", __LINE__,"str_replace");
	assert_equal_str(str_replace("nasil gidiyor.", '.', '?'), "nasil gidiyor?", __LINE__,"str_replace");
	assert_equal_str(str_replace("vallah", 'v', 'y'), "yallah", __LINE__,"str_replace");
}

void str_trim_test(void)
{
	char chrs1[1] = { 'r' };
	assert_equal_str(str_trim("rehber", chrs1, 1), "ehbe", __LINE__,"str_trim");

	char chrs2[3] = { 'a','r','n' };
	assert_equal_str(str_trim("nasil gidiyor", chrs2, 3), "sil gidiyo", __LINE__,"str_trim");

	char chrs3[1] = { ' ' };
	assert_equal_str(str_trim("    hava da tam kar havasi ha!      ", chrs3, 1), "hava da tam kar havasi ha!", __LINE__,"str_trim");

	char chrs4[4] = { 'a',' ','c','g' };
	assert_equal_str(str_trim("    a bcdef   g   a", chrs4, 4), "bcdef", __LINE__,"str_trim");

}

void str_trimstart_test(void)
{
	char chrs1[1] = { 'n' };
	assert_equal_str(str_trimstart("nasil gidiyor", chrs1, 1), "asil gidiyor", __LINE__,"str_trimstart");

	char chrs2[4] = { ' ','c','k','o' };
	assert_equal_str(str_trimstart("cok yorgunum beni bekleme kaptan!", chrs2, 4), "yorgunum beni bekleme kaptan!", __LINE__,"str_trimstart");

	char chrs3[1] = { ' ' };
	assert_equal_str(str_trimstart(" bir sevmek bin defa olmekmis!", chrs3, 1), "bir sevmek bin defa olmekmis!", __LINE__,"str_trimstart");

	char chrs4[4] = { '*',' ','?','/' };
	assert_equal_str(str_trimstart("? / *gecenin ucunde ? *", chrs4, 4), "gecenin ucunde ? *", __LINE__,"str_trimstart");

	char chrs5[1] = { '.' };
	assert_equal_str(str_trimstart("...gitmemesi gerekiyordu.", chrs5, 1), "gitmemesi gerekiyordu.", __LINE__,"str_trimstart");
}

void str_trimend_test(void)
{
	char chrs1[1] = { 'r' };
	assert_equal_str(str_trimend("nasil gidiyor", chrs1, 1), "nasil gidiyo", __LINE__,"str_trimend");

	char chrs2[] = { '!',' ' };
	assert_equal_str(str_trimend("onumden cekilirsen istanbul gorunecek  !  ", chrs2, 2), "onumden cekilirsen istanbul gorunecek", __LINE__, "str_trimend");

	char chrs3[] = { '~',' ' };
	assert_equal_str(str_trimend("master of the wind ~", chrs3, 2), "master of the wind", __LINE__,"str_trimend");

	char chrs4[] = { '.' };
	assert_equal_str(str_trimend("...ustalastik biraz daha tasi kirmakta, dostu dusmani ayirmakta...", chrs4, 1), "...ustalastik biraz daha tasi kirmakta, dostu dusmani ayirmakta", __LINE__,"str_trimend");

	char chrs5[] = { 'h','e','p','.' ,' ' };
	assert_equal_str(str_trimend("bir hisimla geldi gecti peh peh peh...", chrs5, 5), "bir hisimla geldi gecti", __LINE__,"str_trimend");
	
}

void str_substring_test(void)
{
	assert_equal_str(str_substring("anacim",0,3), "ana", __LINE__,"str_substring");
	assert_equal_str(str_substring("Yapraklarim suda balik gibi kivil kivil", 12, 15), "suda balik gibi", __LINE__,"str_substring");
	assert_equal_str(str_substring("amacim kimseyi kirmak degildi, yanlis anlasildim!", 31, 0), "yanlis anlasildim!", __LINE__,"str_substring");
	assert_equal_str(str_substring("drama koprusu", 0, 2), "dr", __LINE__,"str_substring");
}

void str_tolower_test(void)
{
	assert_equal_str(str_tolower("SELAMLAR"), "selamlar", __LINE__,"str_tolower");
	assert_equal_str(str_tolower("HAYAT baYRam Olsa"), "hayat bayram olsa", __LINE__,"str_tolower");
	assert_equal_str(str_tolower("olmadi ama"), "olmadi ama", __LINE__,"str_tolower");
}

void str_toupper_test(void)
{
	assert_equal_str(str_toupper("baris manco"), "BARIS MANCO", __LINE__,"str_toupper");
	assert_equal_str(str_toupper("dunyada biraz huzur herseye bedel...ilac neye yarar vade gelmisse eger"), "DUNYADA BIRAZ HUZUR HERSEYE BEDEL...ILAC NEYE YARAR VADE GELMISSE EGER", __LINE__,"str_toupper");
	assert_equal_str(str_toupper("sELaMlaR"), "SELAMLAR", __LINE__,"str_toupper");

}

void str_padleft_inplace_test(void)
{
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
}

void str_padright_inplace_test(void)
{
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
}

void int_removeall_test(void)
{
	int source[] = { 1,2,3,1,2,5,6,5,8,9,6,56,2,54,87,545,87,456,48,5,845,-54,8489,-5425,-596,2152,64,12,5663,2,1,5,-54,2563,2541,23,655,84,256,5441,210,4,-4 };
	struct condition con;
	con.predicate = LESS_THAN;
	con.predicate_value = 3;
	size_t return_size;
	int *result = int_removeall(source, &con, 43, &return_size);
	for(size_t k = 0; k < return_size;++k) {
		assert_condition_int(result[k], con, __LINE__, "int_removeall_test");
	}

	con.predicate = NOT_EQUAL;
	con.predicate_value = 2;
	return_size = 0;
	result = int_removeall(source, &con, 43, &return_size);
	for (size_t k = 0; k < return_size; ++k) {
		assert_condition_int(result[k], con, __LINE__, "int_removeall_test");
	}

	con.predicate = GREATER;
	con.predicate_value = 64;
	return_size = 0;
	result = int_removeall(source, &con, 43, &return_size);
	for (size_t k = 0; k < return_size; ++k) {
		assert_condition_int(result[k], con, __LINE__, "int_removeall_test");
	}

	con.predicate = GREATER_THAN_EQUAL;
	con.predicate_value = -54;
	return_size = 0;
	result = int_removeall(source, &con, 43, &return_size);
	for (size_t k = 0; k < return_size; ++k) {
		assert_condition_int(result[k], con, __LINE__, "int_removeall_test");
	}


	con.predicate = LESS_THAN_OR_EQUAL;
	con.predicate_value = 5663;
	return_size = 0;
	result = int_removeall(source, &con, 43, &return_size);
	for (size_t k = 0; k < return_size; ++k) {
		assert_condition_int(result[k], con, __LINE__, "int_removeall_test");
	}

	free(result);
}

void int_remove_test()
{
	int source[] = { 1,2,3,1,2,5,6,5,8,9,6,56,2,54,87,545,87,456,48,5,845,-54,8489,-5425,-596,2152,64,12,5663,2,1,5,-54,2563,2541,23,655,84,256,5441,210,4,-4 };
	size_t return_size;
	int *result = int_remove(source, 43, 5, &return_size);
	assert_equal_int(42,(int)return_size , __LINE__, "int_remove_test");	
	free(result);
}
