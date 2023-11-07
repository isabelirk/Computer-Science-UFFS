#include <stdio.h>
#include <string.h>

int main(){
  int n, i, j;
  printf("Digite o numero de posicoes do vetor\n");
  scanf("%d", &n);
  int v1[n], v2[n], vsoma[n*2];
  memset(vsoma, 0, sizeof(vsoma));

  printf("Digite o vetor 1\n");
  for (i = 0; i < n; i++)
    scanf("%d", &v1[i]);
  printf("Digite o vetor 2\n");
  for (i = 0; i < n; i++)
    scanf("%d", &v2[i]);

  for (i = n - 1, j = 0; i >= 0; i--){
    if(v1[i] + v2[i] + vsoma[j] > 9){
      vsoma[j++] += (v1[i]+v2[i]) % 10;
      vsoma[j] += (v1[i]+v2[i])/10;
    }else
      vsoma[j++] += v1[i]+v2[i];
  }
  for (; j >= 0 ; j--)
    printf("%d ", vsoma[j]);
  printf("\n");
  return 0;
}
