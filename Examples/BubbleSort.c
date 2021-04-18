/**********************************************************************

	File:           BubbleSort.C

	Description:    This routine shows a bubble sort in action.

**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(void);
void sort (int *a, int *b);

# define MAX 16

int list[MAX] = { 40, 26, 18, 33, 42, 17, 11, 24,
		  20, 16, 55, 31, 23, 57, 52, 13 };


/*********************************************************************/

int main(void)
{
    printf("Bubble Sort \n\n");
    bubble();
}

/*********************************************************************/

void bubble(void)
{
    int i, j, k;

    for( i = 0;     i < MAX; i++)
	for( j = i + 1; j < MAX; j++)
	{
        sort (&list[i], &list[j]);

	    for( k = 0; k < MAX; k++) printf("%3i", list[k]);
	    puts("");
	}
}

/*********************************************************************/

void sort (int *a, int *b)
{
    int temp;

    if( *a > *b)
    {                   /* interchange elements */
		temp = *a;
        *a   = *b;
        *b   = temp;
    }
}
