#include <stdio.h>
#include <math.h>

void convert_to_cartesian(double r, double θ, double 𝜙)
{
    double x = r*sin(𝜙)*cos(θ);
    double y = r*sin(𝜙)*sin(θ);
    double z = r*cos(𝜙);
    printf("x=%lf, y=%lf, z=%lf\n", x, y, z);
}

int main()
{
    double π = 4 * atan(1.0);
    convert_to_cartesian(5, 3*π/5, π/3);
}