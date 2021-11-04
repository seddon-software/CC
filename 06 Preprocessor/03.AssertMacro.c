#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    int  i;
	int* ptr;

    ptr = malloc(50 * sizeof(int));
	assert(ptr == NULL);  // revers assert so we can see what happens if one fires

	for(i = 0; i < 50; i++)
		ptr[i] = 0;
}
