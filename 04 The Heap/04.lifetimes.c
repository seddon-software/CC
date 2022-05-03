
#include <stdio.h>   
#include <stdlib.h> 
 
#define SIZE 4

int* allocate()
{
    int *ptr = malloc(SIZE*sizeof(int));
    for(int i = 0; i < SIZE; i++)
    {
        ptr[i] = 100 * (i + 1);
    }
    return ptr;
}

int sum_array(int* p)
{
    int total = 0;
    for(int i = 0; i < SIZE; i++)
    {
        total += p[i];
    }
    return total;
}

void deallocate(int* ptr)
{
    free(ptr);
}

int main(void) 
{
    int* p = allocate();
    int total = sum_array(p);
    deallocate(p);
    printf("total = %i\n", total);
}
