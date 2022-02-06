/**********************************************************************

    File:           Scanf.c

**********************************************************************/

#include <stdio.h>

// q -> p, *q -> x, *p, **q
//

int main(void)
{
	int x = 100;
	int* p = &x;   // p is LEVEL 1 because one * in declaration
	int** q = &p;  // q is LEVEL 2 because two *s in declaration

	scanf("%i", &x);  // & increase level x is LEVEL 0, &x ids LEVEL 1
	printf("x = %i\n", x);

	scanf("%i", p);   // p is LEVEL 1
	printf("*p = %i\n", *p);

	scanf("%i", *q);	// q is LEVEL 2, * decreases level, *q is LEVEL 1
	printf("**q = %i\n", **q);
}

