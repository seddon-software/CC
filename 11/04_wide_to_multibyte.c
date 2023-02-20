/*
 *  The functions mbstowcs() and wcstombs() convert between multibyte and wide charaters.  Multi-byte 
 *  characters strings are variable length.  For interest sake we print the length of the multibyte
 *  string upon conversion.   
 */

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

void convert_wide_to_multibyte_and_print(const char* description, char* narrow, int max, const wchar_t* wide)
{
    int size = wcstombs(narrow, wide, max);
    if (size > 0)
        printf("multibyte string(%s):  '%s' of size %i\n", description, narrow, size);
}

#define SIZE 32

int main() 
{
    setlocale(LC_ALL, "");
    // work directly with unicode characters
    char target[SIZE];
    convert_wide_to_multibyte_and_print("star", target, SIZE, L"★");
    convert_wide_to_multibyte_and_print("pi", target, SIZE, L"π");
    convert_wide_to_multibyte_and_print("hebrew alef", target, SIZE, L"א");
    convert_wide_to_multibyte_and_print("pài", target, SIZE, L"𠂢");
    convert_wide_to_multibyte_and_print("russian letters", target, SIZE, L"АБВГДЕЖЗИЙКЛ");

    // work with code points
    convert_wide_to_multibyte_and_print("star", target, SIZE, L"\u2605");
    convert_wide_to_multibyte_and_print("pi", target, SIZE, L"\u03C0");
    convert_wide_to_multibyte_and_print("hebrew alef", target, SIZE, L"\u05D0");
    convert_wide_to_multibyte_and_print("pài", target, SIZE, L"\U000200A2");
    convert_wide_to_multibyte_and_print("russian letters", target, SIZE, 
        L"\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041A\u041B");
}
 
