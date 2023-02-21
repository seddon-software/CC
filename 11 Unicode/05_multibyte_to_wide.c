/*
 *  In this example we convert from wide characters to multi-byte strings.
 */

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

void convert_to_wide_and_print(const wchar_t* name, const char* multiByteString)
{
    int length = 32;
    wchar_t wideString[length];
    mbstowcs(wideString, multiByteString, length);
    wprintf(L"%-16ls: %ls\n", name, wideString);
}

int main(void)
{
    setlocale(LC_ALL, "");
    
    // work directly with unicode characters
    convert_to_wide_and_print(L"star", "★");
    convert_to_wide_and_print(L"pi", "π");
    convert_to_wide_and_print(L"hebrew alef", "א");
    convert_to_wide_and_print(L"pài", "𠂢");
    convert_to_wide_and_print(L"russian letters", "АБВГДЕЖЗИЙКЛ");

    // work with code points
    convert_to_wide_and_print(L"star", "\u2605");
    convert_to_wide_and_print(L"pi", "\u03C0");
    convert_to_wide_and_print(L"hebrew alef", "\u05D0");
    convert_to_wide_and_print(L"pài", "\U000200A2");
    convert_to_wide_and_print(L"russian letters", "\u0410\u0411\u0412\u0413\u0414\u0415"
                                                  "\u0416\u0417\u0418\u0419\u041A\u041B");
}
