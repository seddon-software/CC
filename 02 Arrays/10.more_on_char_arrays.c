#include <stdio.h>

/*
 *  In the early days of C, the library routine to copy C strings was a one liner:
 *              while(*t++ = *s++);
 *
 *  Although this is cryptic (and hence not recommended) it instructive to see why this works.  Let's take it in stages.
 * 
 *      1) *t++ = *s++
 *          this is equivalent to
 *              *t = *s
 *              t++
 *              s++
 *         which copies a character and bumps both pointers.
 * 
 *      2) every expression in C yields a value.  With this above expression it yields the value of the LHS with the side effect 
 *         operators removed.  i.e the expression yields '*s'.  This yielded value is used in the while statement as a boolean.
 * 
 *      3) because s is being incremented, *s successively takes on the value of each character in the source string, including the
 *         null terminator.  The ASCI values of the string will be 65, 66, 67, 68, 69 and finally the null terminator 0.  If we 
 *         convert these ints to booleans we get True, True, True, True, True, False; because non zero is True and zero is False.  
 *         Thus when any C-string is considered as a boolean, it consists of a sequence of True values and one final False value.
 * 
 *      4) This means the while statement will exit after the null (False value) has been copied to the target array.
 */


void string_copy(char* t, const char* s)
{
    while(*t++ = *s++);
}

int main(void)
{
    char source[] = "ABCDE";
    char target[6];         // don't forget to allow for the null terminator
    printf("%i\n", 'A');
    string_copy(target, source);

    printf("source = %s\n", source);
    printf("target = %s\n", target);
}

