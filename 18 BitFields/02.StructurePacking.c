/***********************************************************************

        Structure Packing

***********************************************************************/


#include <stdio.h>
#include <stddef.h>

#pragma pack(16)

struct Flags
{
    unsigned flag_1 :3;     /* word 1  bits  0-2  */
    unsigned flag_2 :7;     /*         bits  3-9  */
    unsigned        :6;     /*         bits 10-15 */

    unsigned type   :2;     /* word 2  bits  0-1  */
    unsigned owner  :8;     /*         bits  2-9  */
    int      index  :6;     /*         bits 10-15 */

    int      day;           /* word 3  bits  0-15 */
    int      month;         /* word 4  bits  0-15 */
    int      year;          /* word 5  bits  0-15 */
};

struct Flags f;


int main(void)
{
                          /* word bit */
    f.flag_1 = 7;         /*  1    0  */
    f.flag_2 = 1;         /*  1    3  */

    f.type   = 1;         /*  2    0  */
    f.owner  = 1;         /*  2    2  */
    f.index  = 1;         /*  2   10  */

    f.day    = 20;        /*  3       */
    f.month  = 107;       /*  4       */
    f.year   = -55;       /*  5       */

    printf("day offset = %lu bytes\n", offsetof(struct Flags, day));
    printf("month offset = %lu bytes\n", offsetof(struct Flags, month));
    printf("year offset = %lu bytes\n", offsetof(struct Flags, year));
}
