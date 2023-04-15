#include <stdio.h>

int main(void){
  int i, vetor[10], aux, tamanho=10, j;
  for(i=0; i<10; i++){
    scanf("%d", &vetor[i]);
  }
  for(i=tamanho-1; i >= 1; i--){
    for(j=0; j < i ; j++) {
      if(vetor[j]>vetor[j+1]){
	aux = vetor[j];
	vetor[j] = vetor[j+1];
	vetor[j+1] = aux;
      }
    }
  }
  for(i= 0; i < 10; i++){
    printf("%d ",vetor[i]);
  }
  printf("\n");
  return 0;
}
