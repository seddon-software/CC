#include <stdio.h>

int main (void)
{
    printf ("This is line %i \n", __LINE__);
    printf ("This is file %s \n", __FILE__);
    printf ("The time is  %s \n", __TIME__);
    printf ("The date is  %s \n", __DATE__);
}
