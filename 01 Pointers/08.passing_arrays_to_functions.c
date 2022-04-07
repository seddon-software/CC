#include <stdio.h>

/*
 */

void print_1(int a[])
{
    printf("sizeof a = %li\n", sizeof(a));
}
void print_2(int* a)
{
    printf("sizeof a = %li\n", sizeof(a));
}
void print_3(int a[], int size)
{
    for(int i = 0; i < size; i++)
        printf("a[%i] = %i\n", i, a[i]);
}
void print_4(int* a, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("a[%i] = %i\n", i, *a++);
    }
}

int main(void)
{
    int a[] = {10, 20, 30, 40, 50};
    
    printf("sizeof a = %li\n", sizeof(a));
    int size = sizeof(a)/sizeof(int);
    print_1(a);
    print_2(a);
    print_3(a, size);
    print_4(a, size);
}
