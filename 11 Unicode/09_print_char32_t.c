// #include <codecvt>
// #include <string>
// #include <iostream>
// #include <string>
// #include <locale>
// #include <iomanip>
// #include <stdexcept>
// #include <bitset>
// using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <uchar.h>
#include <locale.h>
#include <wchar.h>

/*
 *  The standard library has removed support for printing char32 characters.  However, you can create a 
 *  null terminated wchar_t string using from the char32_t character and convert it to a multi-byte string
 *  for printing.
 * 
 *  This works because a char32_t character is the same size as a wchar_t character on Unix systems (but
 *  not on Windows).  So we create a wchar_t array of size 2 and fill it with nulls.  Then we overwrite
 *  element zero with our char32_t before converting to multi-byte with wcstombs.
*/

void printChar32_t(const char32_t c32)
{
    wchar_t wstr[2] = {};       // fill with nulls
    wstr[0] = (wchar_t)c32;     // overwrite first element
    // now convert to wide string to multi-byte
    char mbstr[8] = {};
    int bytesConverted = wcstombs(mbstr, wstr, 8);
    if(bytesConverted != -1) 
        printf("char32_t: %s\n", mbstr);
    else
        printf("wcstoms failed to convert char32_t\n");
}

int main() 
{
    setlocale(LC_ALL, "");
    char32_t dollar = 0x0024;
    char32_t cent = 0x00A2;
    char32_t euro = 0x20AC;
    char32_t pài = 0x200A2;
    printChar32_t(dollar);
    printChar32_t(cent);
    printChar32_t(euro);
    printChar32_t(pài);
}
