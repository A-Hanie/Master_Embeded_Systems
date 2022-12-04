#include <stdio.h>

#define DB_print(debug_lvl, ...)                                                           \
	if (debug_lvl > 1)                                                                     \
		printf("[File: %s , Line: %d , Func: %s()]  ", __BASE_FILE__, __LINE__, __func__); \
	printf(">> \t%s", __VA_ARGS__);

#define ENABLE 1
#define DISABLE 0
/*********************************************************
 * DEBUG Options:
 *  -ENABLE
 *  -DISABLE
 ********************************************************/
#define DEBUG ENABLE

int main()
{

#if DEBUG == ENABLE
	DB_print(2, "\n");
#endif
	return 0;
}
