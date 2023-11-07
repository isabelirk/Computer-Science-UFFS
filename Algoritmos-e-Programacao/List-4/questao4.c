#include <stdio.h>

int main(void){
int n, i, j, ant, maior, pos;
scanf("%d", &n);
int vetor[n];
for(i=0; i<n; i++)
    scanf("%d", &vetor[i]);
for(i=0, ant=0, pos=0; i<n; i++){
    for(j=i, maior=0; j<n; j++)
    maior += vetor[j];
    if(maior > ant){
    pos = i;
    ant = maior;
    }
}
for(i=n-1; i>=pos; i--){
    for(j=pos, maior=0; j<= i; j++)
    maior += vetor[j];
    if(maior>ant)
    ant = maior;
}
printf("%d\n", ant);
return 0;
}
