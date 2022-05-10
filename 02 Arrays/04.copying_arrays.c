#include <stdio.h>

/*
 *  In C it is not possible to copy complete arrays by assignment.  Thus for the arrays defined in this example
 *              target = source
 * 
 *  will not compile.  Instead, arrays must be copied element by element.  The only exception is when an array is part of a struct.
 *  Since structs can be copied, the arrays contained in the structs also get copied (however, this is not common in practice).
 */


void print_array(int array[])
{
    printf("array = ");
    for(int i = 0; i < 4; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    int source[4] = {10, 20, 30, 40};
    int target[4];
    
    target[0] = source[0];
    target[1] = source[1];
    target[2] = source[2];
    target[3] = source[3];
    print_array(source);
    print_array(target);
}
