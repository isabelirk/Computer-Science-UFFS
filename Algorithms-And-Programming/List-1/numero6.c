#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, dividendo, divisor, quociente, resto;
    scanf("%f %f", &a, &b);
    
    dividendo = a;
    divisor = b;
    quociente = a / b;
    resto = (int) a % (int) b;
    printf("dividendo: %f\ndivisor: %f\nquociente: %f\nresto: %d\n", dividendo, divisor, quociente, (int)resto);

    return 0;
}
