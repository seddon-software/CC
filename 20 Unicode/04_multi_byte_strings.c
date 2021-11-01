#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>

void print_as_wide(const char* multiByteStr)
{
    mbstate_t state;
    memset(&state, 0, sizeof state);
    size_t length = 1 + mbsrtowcs(NULL, &multiByteStr, 0, &state);
    wchar_t wideStr[length];
    mbsrtowcs(&wideStr[0], &multiByteStr, length, &state);
    wprintf(L"Wide string: %ls \n", wideStr);
    wprintf(L"The length, including L'\\0': %zu\n", length);
}
 
int main(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    const char* mbstr = "АБВГДЕЖЗИЙКЛ";
    print_as_wide(mbstr);
}
