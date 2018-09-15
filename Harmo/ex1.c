#include <stdio.h>
#include <math.h>

double delta(double a, double b, double c) { return (b * b) + (-4 * a) * c; }
// Solutions réelles
double x1(double a, double b) { return (-b - sqrt(2 * a)) / (2 * a); }
double x2(double a, double b) { return (-b + sqrt(2 * a)) / (2 * a); }
double x0(double a, double b) { return -b / (2 * a); }
// Solutions complexe
int main()
{
    double a, b, c;

    printf("a = ");
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("c = ");
    scanf("%lf", &c);
    if (delta(a, b, c) > 0)
    {
        printf("Les deux solutions : x1 = %f | x2 = %f", x1(a, b), x2(a, b));
    }
    else if (delta(a, b, c) < 0)
    {
        printf("Solution Complexe");
    }
    else
    {
        printf("Une seule solution : x0 = %f", x0(a, b));
    }
    return 0;
} 