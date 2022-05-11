/***********************************************************************

        Casting Bitfields

***********************************************************************/


#include <stdio.h>

#pragma pack(16)        // align on 16 bit boundary (gcc)

struct Flags
{
    unsigned flag_1 :3;     /* word 1  bits  0-2  */
    unsigned flag_2 :7;     /*         bits  3-9  */
    unsigned        :6;     /*         bits 10-15 */

    unsigned type   :2;     /* word 2  bits  0-1  */
    unsigned owner  :8;     /*         bits  2-9  */
    int      index  :6;     /*         bits 10-15 */
};



int main(void)
{
    struct Flags flags;

    
    flags.owner = 33;
    flags.index = 17;
    printf("flags.owner = %04x %u\n", flags.owner, flags.owner);
    printf("flags.index = %04x %u\n", flags.index, flags.index);
    flags.index = 65;       // not enough bits for this (overflow)
    printf("flags.index = %04x %u\n", flags.index, flags.index);
    
    struct Flags allOnes;
    allOnes.flag_1 = 1;
    allOnes.flag_2 = 1;
    allOnes.type = 1;
    allOnes.owner = 1;
    allOnes.index = 1;
    printf("%04x %u\n", allOnes, allOnes);

    // casting with void*
    void* v = &allOnes;
    int   flag = *(int*)v;  // cast back to int
    printf("%04x %i\n", flag, flag);
}
