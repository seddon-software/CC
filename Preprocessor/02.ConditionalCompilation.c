#include <stdio.h>

#define USD 1
#define UK  2
#define DM  3

// command line:
//      gcc -E -DUSD=1 02.ConditionalCompilation.c
int main (void)
{

    #if CURRENCY == USD
    printf("Currency is USD\n");
    printf("Currency is USD\n");

    #elif CURRENCY == UK
    printf("Currency is UK\n");
    printf("Currency is UK\n");

    #elif CURRENCY == DM
    printf("Currency is DM\n");
    printf("Currency is DM\n");

    #else
    printf("Currency is YEN\n");
    printf("Currency is YEN\n");

    #endif
}

