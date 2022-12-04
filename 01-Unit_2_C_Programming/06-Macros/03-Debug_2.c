#include <stdarg.h>
#include <stdio.h>

#define DEBUG 1
void debug_variable(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
}

/* debug_var(("var1 = %d", var1)); */
#define debug_var(x)                                                   \
	do                                                                 \
	{                                                                  \
		if (DEBUG)                                                     \
		{                                                              \
			debug_variable("[File: %s , Line: %d , Func: %s()] ---> ", \
						   __FILE__, __LINE__, __func__);              \
			debug_variable x;                                          \
		}                                                              \
	} while (0)

int main()
{
	int var1 = 5;

	debug_var(("var1 = %d , var1 = %d, var1 = %d, var1 = %d", var1++, var1++, ++var1, var1));
	return 0;
}
