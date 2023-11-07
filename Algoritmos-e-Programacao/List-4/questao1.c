#include <stdio.h>

int main(void){
  int i, n;
  printf("Digite o numeros de posicoes do vetor\n");
  scanf("%d", &n);
  int v[n];
  printf("Digite os valores do vetor\n");
  for(i=0; i<=n; i++){
    scanf("%d", &v[i]);
  }
  i = n;
  while(i>=0){
    printf("v[%d] = %d\n", i, v[i]);
    i--;
  }
  return 0;
}
