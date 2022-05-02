#include <stdio.h>

/*
 *  Arrays can be initialized or uninitialized.  The C standard guarantees that uninitialized global arrays will be set to zero.
 *  The situation with local arrays is very different.  Uninitialized local arrays wil contain whatever happens to be in the
 *  mememory locations they use.  Effectively that means these arrays contain random values.
 * 
 *  Interestingly, the C standard also states that if a local array is partially initialized then the remaining members will be
 *  set to zero.  Thus
 *              int local_2[4] = {10};              // partially initialized
 * 
 *  is equivalent to
 *              int local_2[4] = {10, 0, 0, 0};
 * 
 *  If an array is empty initialized:
 *              int local_3[4] = {};                // this counts as partially initialized
 * 
 *  this counts as partially initialized an is equivalent to:
 *              int local_3[4] = {0, 0, 0, 0};
 * 
 *  Finally, if you initialize an array there is no need to specify its size - the compiler will work it out:
 *     int local_5[] = {10, 20, 30, 40};   // size computed by compiler
 * 
 *  is equivalent to
 *     int local_5[4] = {10, 20, 30, 40};
 *  

 */


int global_1[4] = {10, 20, 30, 40};     // initialized
int global_2[4];                        // uninitialized

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
    int local_1[4] = {10, 20, 30, 40};  // initialized
    int local_2[4] = {10};              // partially initialized
    int local_3[4] = {};                // this counts as partially initialized
    int local_4[4];                     // uninitialized
    int local_5[] = {10, 20, 30, 40};   // size computed by compiler

    printf("\nprinting global array (initialized):\n");
    print_array(global_1);

    printf("\nprinting global array (uninitialized):\n");
    print_array(global_2);

    printf("\nprinting local array (initialized):\n");
    print_array(local_1);
    
    printf("\nprinting local array (partially initialized):\n");
    print_array(local_2);
    
    printf("\nprinting local array (empty initialized):\n");
    print_array(local_3);

    printf("\nprinting local array (uninitialized):\n");
    print_array(local_4);    

    printf("\nprinting local array (size computed by compiler):\n");
    print_array(local_5);    
}
