/**********************************************************************

    File:           Printf.c

**********************************************************************/

#include <stdio.h>



int main(void)
{
	int x = 107;
	printf("text\n");
	printf("special characters:%%\\\n");
	printf("integer: %5i\n", x);
	printf("integer: %5d\n", x);
	printf("hex: %x\n", x);
	printf("octal: %o\n", x);
	
}

