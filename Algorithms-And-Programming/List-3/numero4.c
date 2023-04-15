#include <stdio.h>

int main(void){

  int serie, livros, redacao, m=0, cont3=0, idade;
  double por, contr=0, i=1.0;

  while(scanf("%d", &idade), idade){
    scanf("%d %d %d", &serie, &livros, &redacao);

    if(serie == 3){
      cont3++;
    }
    if(livros>m && serie == 4){
      m=livros;
    }
    if(serie == 3 && redacao == 0){
      contr++;
    }
    i++;
  }
  por= (contr / i) * 100;

  printf("Quantidade de alunos na terceira serie: %d\nMaior quantidade de livros lidos por um aluno da quarta serie: %d\nPorcentagem de alunos que não gostam de fazer redacao na terceira serie: %.2lf\n", cont3, m, por);

  return 0;
}
