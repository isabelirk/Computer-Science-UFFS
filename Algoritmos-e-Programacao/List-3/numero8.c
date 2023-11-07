#include <stdio.h>

int main(void){

  int n, i = 1, j = 1, espaco, aste;
  scanf("%d", &n);
  espaco = n / 2;
  aste = 1;

  while(aste <= n){
    while (i <= espaco){
      printf(" ");
      i ++;
    }
    while (j <= aste){
      printf("*");
      j ++;
    }

    printf("\n");
    i = 1;
    j = 1;
    aste += 2;
    espaco -= 1;
  }

  espaco = 1;
  aste = n - 2;

  while(aste > 0){
    while(i <= espaco){
      printf(" ");
      i++;
    }
    while(j <= aste){
      printf("*");
      j ++;
    }

    printf("\n");
    i = 1;
    j= 1;
    aste -= 2;
    espaco ++;
  }    

  return 0;
}
