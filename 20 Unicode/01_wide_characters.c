/*
UTF-8
    Pro: compatible with all existing strings and most existing code
    Pro: takes less space
    Pro: widely used as an interchange format (e.g. in XML)
    Con: more complex processing, O(n) string indexing

Wide characters
    Pro: easy to process
    Con: wastes space
    Pro: Simple syntax, L"Hello, world."

    Con: the size of wide characters is not consistent across platforms (should be 4 bytes, some incorrectly use 2-byte wide characters)
    Con: should not be used for output, since spurious zero bytes and other low-ASCII characters with common meanings (such as '/' 
         and '\n') will likely be sprinkled throughout the data.

Multibyte
    Pro: no conversions ever needed on input and output
    Pro: built-in C library support
    Pro: provides the widest possible internationalization, since in rare cases conversion between local encodings and Unicode does 
         not work well
    Con: strings are opaque
    Con: perpetuates incompatibilities. For example, there are three major encodings for Russian. If one Russian sends data to another 
         through your program, the recipient will not be able to read the message if his or her computer is configured for a different 
         Russian encoding. But if your program always converts to UTF-8, the text is effectively normalized so that it will be widely 
         legible (especially in the future) no matter what encoding it started in.
*/

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    // define characters from Unicode Code Points
    wchar_t star = 0x2605;
    wchar_t pi = 0x03C0;
    wchar_t hebrew_alef = 0x05D0;

    // print wide charcters
    wprintf(L"Star :%lc\n", star);
    wprintf(L"Greek pi: %lc\n", pi);
    wprintf(L"Hebrew Alef: %lc\n", hebrew_alef);
}
