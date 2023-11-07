#include <stdio.h>

int main(void){

  int n, i = 1, j = 1, linha = 1, espaco, num;
  scanf("%d", &n);
  espaco = n / 2;
  num = 1;

  while(linha <= n/2+1){
    while (i <= espaco){
      printf(" ");
      i ++;
    }
    while (j <= num){
      printf("%d", j);
      j ++;
    }
	j -= 2;
	while(j>0){
		printf("%d", j);
		-- j;
	}
    printf("\n");
    i = 1;
    j = 1;
    num ++;
    espaco -= 1;
    linha ++;
  }

  espaco = 1;
  num = n - 1;

  while(num > 0){
    while(i <= espaco){
      printf(" ");
      i++;
    }
    while(j <= num){
      printf("%d", j);
      j ++;
    }
    j += 2;

    printf("\n");
    i = 1;
    j= 1;
    num --;
    espaco ++;
    linha ++;
  }    

  return 0;
}
