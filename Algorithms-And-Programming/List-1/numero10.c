#include <stdio.h>
#include <stdlib.h>

int main()
{
    float r,p=3.14, per, area;
    scanf("%f", &r);

    per = (2 * p) * r;
    area = p * (r * r);
    printf("PERIMETRO: %f\nAREA: %f", per, area);
    
    return 0;
}
