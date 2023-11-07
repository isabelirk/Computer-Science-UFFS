#include <stdio.h> // inclui a biblioteca padrão de entrada e saída de C
#include <map>     // inclui a biblioteca de mapa do C++ para guardar valores em pares
#include <string>  // inclui a biblioteca de strings do C++

using namespace std; // permite o uso das funções e classes da biblioteca padrão do C++ sem o prefixo "std::"

#define INF 112345678 // define a constante INF com o valor 112345678

int main(void) // função principal
{
  char cs1[20], cs2[20]; // declara dois arrays de caracteres com 20 posições cada

  map<string, int> M; // declara um mapa com chave de string e valor inteiro

  while (scanf("%s %s ", cs1, cs2) != EOF) // enquanto houver entrada para ser lida
  {
    M[string(cs1)]++;      // incrementa o valor da chave correspondente a cs1 no mapa
    M[string(cs2)] = -INF; // atribui o valor -INF à chave correspondente a cs2 no mapa
  }

  printf("HALL OF MURDERERS\n"); // imprime a mensagem "HALL OF MURDERERS"

  for (auto &i : M)                                 // para cada par de chave e valor no mapa M
    if (i.second > 0)                               // se o valor for maior que zero
      printf("%s %d\n", i.first.c_str(), i.second); // imprime a chave e o valor correspondente
  return 0;                                         // retorna zero para indicar que a execução foi concluída com sucesso
}