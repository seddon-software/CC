/*
 *  Here we take a look at the UTF-8 encoding.  Recall that each Unicode character has a unique code point,
 *  but the code point is not normally what is stored in memory.  Instead there are many possible encodings.  
 *  The UTF-8 encoding is the most popular on the web (~75% of all websites use UTF-8).
 * 
 *  C has very limited support for encodings, but it does support UTF-8.  There are numerous blogs on the 
 *  web explaing how UTF-8 is related to the Unicode code point.  Here we print out both quantities for some 
 *  example Unicode characters:
 *  
 *    Character     Code Point  UTF-8(hex) 	UTF-8(binary)
 *       $ (dollar) U+0024 	    24          00100100 	                            
 *       ¢ (cent)   U+00A2 	    C2 A2       11000010 10100010 	
 *       € (euro)   U+20AC 	    E2 82 AC    11100010 10000010 10101100
 *       𠂢 (pài)   U+200A      F0 A0 82 A2 11110000 10100000 10000010 10100010  	            
 *       𠀋 (CJK)   U+2000B     F0 A0 80 8B 11110000 10100000 10000000 10001011 	
 * 
 *  Refer to:
 *      https://symbl.cc/en/unicode/blocks/
 * 
 *  for a full list of Unicode code points and their UTF-8 encodings.
 */

#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void convert_to_wide(wchar_t* wideString, const char* multibyteString)
{
    mbstate_t state;
    memset(&state, 0, sizeof state);   // zero the state
    mbsrtowcs(wideString, &multibyteString, 32, &state);
}

void convert_to_UTF8(char* s)
{
    // print the character
    printf("%s\t", s);
    
    // print code point from wide character
    wchar_t wide[32];
    convert_to_wide(wide, s);
    printf("%x\t\t", (unsigned) wide[0]);
    
    // print UTF-8 representation from multibyte representation
    for(size_t i = 0; i < strlen(s); i++)
    {
        printf("%02X ", 0xFF & s[i]);
    }
    printf("\n");
}

void headings()
{
    printf("char\tcode-point\tUTF8(hex)\n");
    printf("=================================\n");
}

int main() 
{
    setlocale(LC_ALL, "");
    headings();
    convert_to_UTF8("$");
    convert_to_UTF8("¢");
    convert_to_UTF8("€");
    convert_to_UTF8("𠂢");
    convert_to_UTF8("𠀋");
}
