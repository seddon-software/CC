#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp( int *keyNumber, int *number);

//const int SIZE = 24; // this doesn't work
#define SIZE 24
int list[SIZE] = {
		 40, 26, 18, 33, 42, 17, 11, 24,
		 20, 16, 55, 31, 23, 57, 52, 13,
		 59, 20, 19, 53, 88, 12, 78, 75 };


int main(void)
{
	int i;
	qsort(list, 24, sizeof(int), (int (*)()) cmp);
	for(i = 0; i < 24; i++)
	{
		printf("%3i", list[i]);
	}
	printf("\n");
}

int cmp( int *keyNumber, int *number)
{
    int n;

    if( *keyNumber >  *number) n = +1;
    if( *keyNumber == *number) n =  0;
    if( *keyNumber <  *number) n = -1;

    return n;
}

