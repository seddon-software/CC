#include <stdio.h>
#define QUOTE(P1) #P1

int main (void)
{
    int number = 77;

    printf("%s is %i \n", QUOTE(number), number);
    printf("%s is %i \n", "number", number);
}

