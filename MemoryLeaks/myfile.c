#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

int main()
{
    int i;
    int* ptr;
    
    mtrace();
    ptr = (int*) malloc(50 * sizeof(int));
    for(i = 0; i < 50; i++)
    {
	ptr[i] = i * i;
	printf("%i ", ptr[i]);
    }
    ptr++;
    free(ptr);
    printf("\n");
    return 0;
}

