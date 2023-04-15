#include <stdio.h>

int main(void){

  int id, opiniao, cont=0, maiori=0, i=0;
  double media=0, idade, cont5=0, porcentagem;

  while(i<200){
    scanf("%lf %d %d", &idade, &id, &opiniao);
    media = media + idade;

    if(opiniao == 10){
      cont++;
    }

    if(opiniao <= 5){
      cont5++;
    }

    if(idade>maiori){
      maiori = idade;
    }

    porcentagem= (cont5 / 3) * 100;
    i++;
  }

  media= media/3;

  printf("Respostas 10: %d\nMedia das idades: %.2lf\nPorcentagem de notas <=5: %.2lf\nPessoa mais velha: %d\n", cont, media, porcentagem, maiori);

  return 0;
}
