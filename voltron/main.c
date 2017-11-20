#pragma  warning(disable:4996)
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "vstring.h"
#include "vassert.h"

int main() {
	
	equal_int(str_endswith("selamlar nasilsin nasil gidiyoR", "GiDiYOr", 1), -1, __LINE__);
	equal_int(str_endswith("selamlar nasilsin nasil gidiyoR", "GiDiYOr", 0), 0, __LINE__);
	equal_int(str_endswith("  ", "", 1), -1, __LINE__); 
	equal_int(str_endswith("  ", " ", 1), 0, __LINE__);
	equal_int(str_endswith("merhaba dunya", "  dunya", 1), -1, __LINE__);
	equal_int(str_endswith("merhaba dunya", " dunya ", 1), -1, __LINE__);
	equal_int(str_endswith("merhaba dunya", "Dunya", 0), 0, __LINE__);

	equal_int(str_startswith("merhaba dunya", "mer", 0), 0, __LINE__);
	equal_int(str_startswith("merhaba dunya", "Mer", 1), -1, __LINE__);
	equal_int(str_startswith("merhaba dunya", "MerHABA ", 0), 0, __LINE__);
	equal_int(str_startswith("merhaba dunya", "MerHABA ", 1), -1, __LINE__);
	equal_int(str_startswith("  dunya", " ", 0), 0, __LINE__);
	equal_int(str_startswith("  ", "", 0), -1, __LINE__);

	equal_str(str_padright("11", 4, '0'), "1100", __LINE__);
	equal_str(str_padright("Turkiy", 7, 'e'), "Turkiye", __LINE__);

	equal_str(str_padleft("11", 4, '0'), "0011", __LINE__);
	equal_str(str_padleft("22", 4, '1'), "1122", __LINE__);

	equal_str(str_insert("lma", "e", 0), "elma", __LINE__);
	equal_str(str_insert("la", "la", 1), "llaa", __LINE__);
	equal_str(str_insert("merhaba dunya", "rr", 3), "merrrhaba dunya", __LINE__);
	equal_str(str_insert("selam", "lma", 2), "selmalam", __LINE__);


	//printf("%s\n", str_remove("selamlar nasilsin", 5, 3));

	system("pause");
	return 0;
}
