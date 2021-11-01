/*
Unicode Support

The Unicode standard defines several encoding formats, for example: UTF-8, UTF-16, and UTF-32. Each has advantages 
and disadvantages. Currently, C/C++ programmers use 
    char to encode UTF-8, 
    unsigned short or wchar_t for UTF-16,
    unsigned long or wchar_t for UTF-32
    
C11 introduces two new types with platform-independent widths: 
    char16_t for UTF-16 and 
    char32_t for UTF-32

C11 also provides prefixes for string literals of these new types:
    u prefix for char16_t
    U prefix for char32_t

Notes: 
1. wchar_t is platform dependent (usually 32 bit on Linux, 16 bit on Windows)
2. there is NO library support (as yet) for char16_t and char32_t.
*/

#include <stdio.h>
#include <wchar.h>
#include <uchar.h>

int main(void)
{
    char utf8[] = u8"ABCDEFG";
    wchar_t utf32[] = L"ABCDEFG";
    char16_t c16 = u'A';
    char32_t c32 = U'A';

    printf("size of char: %lu\n", sizeof(utf8));
    printf("size of wchar_t: %lu\n", sizeof(utf32));
    printf("size of char16_t: %lu\n", sizeof(c16));
    printf("size of char32_t: %lu\n", sizeof(c32));
}
