/*
Unicode Support

The Unicode standard defines several encoding formats, for example: UTF-8, UTF-16, and UTF-32. Each has advantages 
and disadvantages. Currently, C/C++ programmers use 
    char[] to encode UTF-8 strings, 
    wchar_t or wchar32_t for UTF-32
    UTF-32 is same as code point
    UTF-16 is not used any more

C11 introduces two new types with platform-independent widths: 
    char16_t for UTF-16 and 
    char32_t for UTF-32

C11 also provides prefixes for string literals of these new types:
    u prefix for char16_t
    U prefix for char32_t

Notes: 
1. wchar_t is platform dependent (usually 32 bit on Linux, 16 bit on Windows)
2. there is NO library support (as yet) for char16_t and char32_t.

Check out these web sites:
    https://www.asciitable.com/
    https://unicode-table.com/en/
    https://en.cppreference.com/w/
    https://www.cprogramming.com/tutorial/unicode.html
*/

#include <stdio.h>
#include <wchar.h>
#include <uchar.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "en_US.UTF-8");
    printf("char has size %lu\n", sizeof(char));
    printf("wchar_t has size %lu\n", sizeof(wchar_t));

    printf("char16_t has size %lu\n", sizeof(char16_t));
    printf("u'A' has size %lu\n", sizeof(u'A'));

    printf("char32_t has size %lu\n", sizeof(char32_t));
    printf("U'A' has size %lu\n", sizeof(U'A'));
}
