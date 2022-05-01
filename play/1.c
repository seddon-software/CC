#include <stdio.h>

int main(void)
{
    int   a[5];
    int   k;
    printf("%p\n", &k);
    printf("%p\n", a);
    printf("%p\n", &a[0]);
    printf("%p\n", &a[1]);
    printf("%p\n", &a[2]);
    printf("%p\n", &a[3]);
    printf("%p\n", &a[4]);
    printf("%p\n", &a[5]);
    
    for(a[0] = 0; a[0] <= 5; a[0]++) {
    //    printf("%p\n", &i);
         printf("initialising %i\n", a[0]);
         a[a[0]] = 3;
    }
}
