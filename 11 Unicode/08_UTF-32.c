#include <stdio.h>
#include <wchar.h>
#include <uchar.h>
#include <locale.h>
#include <stdlib.h>


mbstate_t ss;    /* set shift state to the initial state */

int main(void)
{
    setlocale(LC_ALL, "");
    // 'Б' has encoding 53393 in UTF-8
    // 'Б' has encoding 1041 (0x0411) in UTF-32 (= code point)
    char32_t c32;
    char mbs[] = "Б" ; /* string containing the multibyte character */
    int length = 0 ;
   
    /* Determine the length of the multibyte character pointed to by */
    /* mbs. Store the multibyte character in the char16_t object */
    length = mbrtoc32(&c32, mbs, MB_CUR_MAX, &ss);
    if (length < 0) {
        perror("mbrtoc16() fails to convert");
        exit(-1);
    }

    printf("mbs:\"%s\"\n", mbs);
    printf("length: %d \n", length);
    printf("hex encoding (UTF-32): 0x%04hx \n", c32);
    printf("decimal encoding (UTF-32): %i \n", c32);
}
