#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, per, area;
    scanf("%f %f", &a, &b);

    per = a + a + b + b;
    area = a * b;
    printf("PERIMETRO: %f\nAREA:%f\n", per, area);
    
    return 0;
}
