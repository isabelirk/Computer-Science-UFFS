#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, t, h, prestacao;
    scanf("%f %f %f", &a, &t, &h);

    prestacao = a + ( a * ( t / 100) * h);
    printf("%f", prestacao);
    
    return 0;
}
