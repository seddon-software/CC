/**********************************************************************

    File:           Scanf.c

**********************************************************************/

#include <stdio.h>

int main(void)
{
	int x = 100;
	int* p = &x;
	int** q = &p;

	scanf("%i", &x);
	printf("x = %i\n", x);

	scanf("%i", p);
	printf("*p = %i\n", *p);

	scanf("%i", *q);
	printf("**q = %i\n", **q);
}

