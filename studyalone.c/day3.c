#include <stdio.h>  
int main(){
    int a=0xAF;
    int b=0xB5;
    printf("%x\n",a&b);
    printf("%x\n",a|b);
    printf("%x\n",a^b);
    printf("%x\n",~a);
    printf("%x\n",a<<2);
    printf("%x\n",b>>3);

    return 0;
}