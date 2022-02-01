#include <stdio.h>

/*
 */
void clear(void* start, void* end)
{
    for(char* p = start; p < (char*)end; p++)
    {
        *p = '\0';
    } 
}
void print_int(int* start, int* end)
{
    for(int* p = start; p < (int*)end; p++)
    {
        printf("%i, ", *p);
    }
    printf("\n");     
}
void print_double(double* start, double* end)
{
    for(double* p = start; p < (double*)end; p++)
    {
        printf("%lf, ", *p);
    }         
    printf("\n");     
}

int main(void)
{
    int a[] = {10, 20, 30, 40, 50};
    double b[] = {1.2, 2.4, 3.6, 4.8}; 
    clear(a, a+5);
    clear(b, b+4);
    print_int(a, a+5);
    print_double(b, b+4);
}
