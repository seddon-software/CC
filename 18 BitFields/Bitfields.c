/************************************************************************

        Bitfields

************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define BIT0  0x0001  /* 0000 0000 0000 0001 */
#define BIT1  0x0002  /* 0000 0000 0000 0010 */
#define BIT2  0x0004
#define BIT3  0x0008
#define BIT4  0x0010
#define BIT5  0x0020
#define BIT6  0x0040
#define BIT7  0x0080
#define BIT8  0x0100
#define BIT9  0x0200
#define BIT10 0x0400
#define BIT11 0x0800
#define BIT12 0x1000
#define BIT13 0x2000
#define BIT14 0x4000
#define BIT15 0x8000

int main(void)
{
    int flag = 0;

    flag  = BIT0 | BIT4 | BIT8 | BIT12;
    printf("%04x\n", flag);
    flag |= BIT1 | BIT2 | BIT3;
    printf("%04x\n", flag);
    flag ^= BIT4 | BIT8 | BIT12;
    printf("%04x\n", flag);

    flag  = BIT0 | BIT4 | BIT8 | BIT12;
    flag &= 0x00ff;
    printf("%04x\n", flag);

    flag  = flag << 1;
    flag  = flag << 1;
    flag  = flag << 1;
    flag  = flag << 1;
    flag  = flag >> 1;
    printf("%04x\n", flag);
}


