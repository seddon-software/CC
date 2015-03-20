////////////////////////////////////////////////////////////
//
//      Reverse Print using recursion
//
////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

void reversePrint (char *name);

int main (void)
{
    char *name = "ABCDEFGHIJKLM";

    reversePrint (name);
    printf("\n");
}

void reversePrint (char *name)
{
    char ch;

/* ----- BEFORE RECURSION ----- */

    ch = name[0];

    if (strlen(name) != 1)
    {
	name++;    /* move along 1 character */
	reversePrint (name);
    }

/* ----- AFTER RECURSION ----- */

    putchar (ch);
}

