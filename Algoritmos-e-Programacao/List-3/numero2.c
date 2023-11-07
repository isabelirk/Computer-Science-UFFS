#include <stdio.h>

int main(void){

  int idade, id, opiniao, cont, cont5, mairoidade=0, porcentagem=0;

  while(i<3){
    scanf("%d %d %d", &idade, &id, &opiniao);

    if(opiniao == 10){
      cont++;
    }

    media= media + idade;
    if(opiniao <= 5){
      cont5++;
    }

    if(idade>maioridade){
      maioridade = idade;
    }
    porcentagem= (cont5 / 3) * 100;

  }
  printf("Respostas 10: %d\nMedia das idades: %d\nPorcentagem de notas <=5: %d\nPessoa mais velha: %d\n", cont, media, porcentagem, maioridade);

  return 0;
}
