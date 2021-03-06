/**********************************************************************

		atexit.c

**********************************************************************/

#include <stdio.h>
#include <stdlib.h>

void routine1 (void);
void routine2 (void);
void routine3 (void);
void routine4 (void);
void routine5 (void);


int main (void)
{
    atexit (routine1);
    atexit (routine2);
    atexit (routine3);
    atexit (routine4);
    atexit (routine5);
    puts ("Handlers registered\n");
    puts ("Main completes\n");
}

void routine1 (void)
{
    puts ("routine1");
}

void routine2 (void)
{
    puts ("routine2");
}

void routine3 (void)
{
    puts ("routine3");
}

void routine4 (void)
{
    puts ("routine4");
}

void routine5 (void)
{
    puts ("routine5");
}
