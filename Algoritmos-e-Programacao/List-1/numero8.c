#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, saldoa;
    scanf("%f", &a);

    saldoa = (a / 100) + a;
    printf("%f", saldoa);
    
    return 0;
}
