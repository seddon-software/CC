/*
Unicode Support

The Unicode standard defines three encoding formats: UTF-8, UTF-16, and UTF-32. Each has advantages 
and disadvantages. Currently, programmers use char to encode UTF-8, unsigned short or wchar_t for 
UTF-16, and unsigned long or wchar_t for UTF-32. C11 eliminates these hacks by introducing two new 
datatypes with platform-independent widths: char16_t and char32_t for UTF-16 and UTF-32, respectively 
(UTF-8 encoding uses char, as before). C11 also provides u and U prefixes for Unicode strings, and 
the u8 prefix for UTF-8 encoded literals. Finally, Unicode conversion functions are declared in <uchar.h>.
*/

#include <uchar.h>

int main(void)
{
    char16_t c16;
    char32_t c32;
}