// The functions mbstowcs() and wcstombs() convert from and to locale-specific encodings, respectively.

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
/*
᠐
*/
int main() 
{
    setlocale(LC_ALL, "");
    const wchar_t* wstr = L"\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041A\u041B";
    char mbstr[32];
    int bytesConverted = wcstombs(mbstr, wstr, 32);
    printf("Russian letters: %s\n", mbstr);
}
 
