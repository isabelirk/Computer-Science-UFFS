#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c, media;
    scanf("%f %f %f", &a, &b, &c);
    
    media = (a + b + c) / 3;
    printf("%f\n", media);

    return 0;
}
