#define CUBE(X)   ((X) * (X) * (X))

int main(void)
{
    int result, n = 3;

    result = CUBE(n);
    printf("%i %i \n", result, n);
}
