#include <stdio.h>

int main() {

    int Byets = 0b11111111000000001010101010101010;
    
    char *ptrByte_1 = &Byets;
    char * ptrByte_2 = ptrByte_1+1;
    char * ptrByte_3 = ptrByte_1+2;
    char * ptrByte_4 = ptrByte_1+3;
    char temp=0;
    
    temp=*ptrByte_1;
    *ptrByte_1 = * ptrByte_3;
    *ptrByte_3 = temp;

    printf("%d",Byets);

    return 0;
}