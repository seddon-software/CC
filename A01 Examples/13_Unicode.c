#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main( ) {
    setlocale(LC_ALL, "");
    wprintf(L"%ls\n", L"\x0152\x3074\x1F4A9\u6000 ʃ \u0283 ᐃ \u1403");
}
