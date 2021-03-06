/***********************************************************************

        Casting Bitfields

***********************************************************************/


#include <stdio.h>

#pragma pack(16)

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
    struct Flags allOnes;
    struct Flags theFlags;
    int   flag;
    void* v = &allOnes;

    allOnes.flag_1 = 1;
    allOnes.flag_2 = 1;
    allOnes.type = 1;
    allOnes.owner = 1;
    allOnes.index = 1;
    
    flag     = *(int*) v;
    theFlags = *(struct Flags*) v;
}
