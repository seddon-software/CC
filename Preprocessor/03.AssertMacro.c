#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    int  i;
	int* ptr;

    ptr = malloc(50 * sizeof(int));
	assert(ptr == NULL);

	for(i = 0; i < 50; i++)
		ptr[i] = 0;
}