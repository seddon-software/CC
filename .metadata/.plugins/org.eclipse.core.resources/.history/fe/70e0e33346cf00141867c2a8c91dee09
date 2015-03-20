/*******************************************************************

		simple.c

*******************************************************************/

#include <stdarg.h>

void function (int firstArg, ...);

int main (void)
{
    function (2, 4, 6, 8);
    return 0;
}

void function (int firstArg, ...)
{
    int x, y, z;
    va_list argPointer;

    va_start (argPointer, firstArg);

    x = va_arg (argPointer, int);
    y = va_arg (argPointer, int);
    z = va_arg (argPointer, int);

    va_end (argPointer);
}
