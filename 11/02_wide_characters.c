/*
There are 2 types of string representation: multibyte (8-bit bytes) or wide character (size depends 
on platform).

To use the multibyte representation you declare characters with char.
To use multibyte strings use "...."

To use the wide character representation you declare characters with wchar_t.
To use wide character strings use L"...."
*/

#include <stdio.h>
#include <wchar.h>
#include <locale.h>


void usingCodePoints()
{
    wchar_t star = 0x2605;
    wchar_t pi = 0x03C0;
    wchar_t hebrew_alef = 0x05D0;
    wchar_t pài = 0x200A2;

    // print individual wide characters
    wprintf(L"Star :%lc\n", star);
    wprintf(L"Greek pi: %lc\n", pi);
    wprintf(L"Hebrew Alef: %lc\n", hebrew_alef);
    wprintf(L"pài: %lc\n", pài);
}

void usingUnicodeSymbols()
{
    wchar_t star = L'★';
    wchar_t pi = L'π';
    wchar_t hebrew_alef = L'א';
    wchar_t pài = L'𠂢';

    // print individual wide characters
    wprintf(L"Star :%lc\n", star);
    wprintf(L"Greek pi: %lc\n", pi);
    wprintf(L"Hebrew Alef: %lc\n", hebrew_alef);
    wprintf(L"pài: %lc\n", pài);
}

int main() 
{
    setlocale(LC_ALL, "");
    usingCodePoints();
    usingUnicodeSymbols();
}
