#include <stdio.h>

#define func(name, c) func_##name(int x) { return (c * x); }

func(Quad, 4);
func(Triple, 3);

int main()
{

    printf("%d", func_Quad(2));

    return 0;
}