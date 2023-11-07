#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, anterior, posterior;
    scanf("%d", &a);
    
    anterior = a - 1;
    posterior = a + 1;
    printf("%d %d %d\n", anterior, a , posterior);

    return 0;
}
