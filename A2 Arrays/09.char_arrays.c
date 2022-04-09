#include <stdio.h>

/*
 *  Unlike many othe pogramming language, C doesn't have a "string" type.  Instead it uses char arrays; these are normally refered 
 *  to as strings.  
 * 
 *  The language has special support for these arrays.  Instead of writing:
 *              char letters_1[] = {'A', 'B', 'C', 'D', 'E'};
 * 
 *  we can write:
 *              char letters_2[] = "ABCDE";
 * 
 *  and these two statements are almost equivalent.  In fact they produce the same array in memory, except 'letters_2' contains
 *  one extra character.  The extra character is in fact a null (or '\0') and refered to as the null terminator.  This is a non 
 *  printable character with an ASCII value of 0.  The null never appears in normal text and as such it serves as an end stop 
 *  for the string.
 * 
 *  Now, because the null terminator can never appear in the middle of a string, we don't need to pass the size of the char array
 *  when passing the array to any function.  The function can work out the size of the array because the null will be its last
 *  character; this function works without being told the size of the input string:
 
 *              void print_char_array(const char* ptr)
 * 
 *  Note that the routine assumes that the C-String contains a null; it will keep printing memory locations until it finds a null.
 *  If there is no null, as in 'letters_1', then you'll probably see garbage being printed after the string.  The same is true of 
 *  printf. 
 */


void print_char_array(const char* ptr)
{
    while(*ptr != '\0')
    {
        printf("%c", *ptr);
        fflush(stdout);         // so we can see characters as we debug
        ptr++;
    }
    printf("\n");
}

void print_array_as_ints(const char* ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%i ", *ptr);
        fflush(stdout);         // so we can see characters as we debug
        ptr++;
    }
    printf("\n");
}

int main(void)
{
    char letters_1[] = {'A', 'B', 'C', 'D', 'E'};
    char letters_2[] = "ABCDE";
    char letters_3[5] = "ABCDE";      // don't allocate space for null terminator

    // chars are only 1 byte long
    printf("size of char = %li\n", sizeof(char));

    // the size of the char array = the number of chars it contains
    printf("size of 'letters_1' = %li\n", sizeof(letters_1));
    printf("size of 'letters_2' = %li\n", sizeof(letters_2));
    printf("size of 'letters_3' = %li\n", sizeof(letters_3));

    // print the extra character as an integer (it is a non-printable char in position 5):
    printf("last char of 'letters_2' = %i\n", letters_2[5]);

    // print out the strings as chars
    print_char_array(letters_1);
    print_char_array(letters_2);
    print_char_array(letters_3);

    // print out the strings as ints
    print_array_as_ints(letters_1, 5);
    print_array_as_ints(letters_2, 6);
    print_array_as_ints(letters_3, 5);

    // use library routine 'printf' instead
    printf("char array = %s\n", letters_1);
    printf("char array = %s\n", letters_2);
    printf("char array = %s\n", letters_3);
}

