#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c, d, mediap;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    
    mediap = ((a * 1) + (b * 2) + (c * 3) + (d * 4)) / (1 + 2 + 3 + 4);
    printf ("%f", mediap);

    return 0;
}
