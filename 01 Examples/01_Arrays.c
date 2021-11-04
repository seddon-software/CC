/**********************************************************************

    File:           Arrays.c

**********************************************************************/

#include <stdio.h>



void f(int *b)
{
	printf("%i\n", sizeof(b));
	printf("%p\n", b);
	printf("%i %i\n", b[0], *b);
	printf("%i %i\n", b[1], *(b+1));
	printf("%i %i\n", b[-1], *(b-1));
}

int main(void)
{
	int a[] = {5, 10, 15, 20, 25};
	printf("%i\n", sizeof(a));
	f(a+2);
	//int const * const q;
	int* ptr = a;   // ptr is an l-value because it can appear on lhs of =
	printf("%li\n", sizeof(int*));
	printf("%p %p \n", a, ptr);
	// ptr = ptr + 3;
	printf("%p %p \n", a, ptr);
	printf("%i %i %i %i\n", a[0], ptr[0], *a, *ptr);
	printf("%i %i %i %i\n", a[1], ptr[1], *(a+1), *(ptr+1));
	printf("%i %i %i %i\n", a[2], ptr[2], *(a+2), *(ptr+2));
	printf("%i %i %i %i\n", a[3], ptr[3], *(a+3), *(ptr+3));
	printf("%i %i %i %i\n", a[4], ptr[4], *(a+4), *(ptr+4));
}

