#include <stdio.h>

int main(void)
{
    int a[] = {2, 4, 6, 8, 10};
    int* p = a;
    printf("%p\n", p);
    return 0;
}