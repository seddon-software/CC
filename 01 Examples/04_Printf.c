/**********************************************************************

    File:           Printf.c

**********************************************************************/

#include <stdio.h>



int main(void)
{
	int x = 107;
	double pi = 3.14159;
	printf("text\n");
	puts("text\n");
	printf("special characters:%%\\\n");
	printf("integer: %05i\n", x);
	printf("integer: %5d\n", x);
	printf("%06.4lf\n", pi);
	printf("hex: %x\n", x);
	printf("octal: %o\n", x);
}

