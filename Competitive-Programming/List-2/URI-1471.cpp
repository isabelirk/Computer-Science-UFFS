#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  short i;                         // declaração da variável para o laço de repetição
  short tmp;                       // variável temporária para leitura dos valores
  short qtsMergulhou, qtsRetornou; // quantidade de mergulhadores e de mergulhadores que retornaram
  bool iguais = false;             // flag que indica se a quantidade de mergulhadores e de mergulhadores que retornaram são iguais

  while (cin >> qtsMergulhou >> qtsRetornou) // laço de repetição que lê a quantidade de mergulhadores e de mergulhadores que retornaram
  {
    if (qtsMergulhou == qtsRetornou)
      iguais = true;

    if (iguais) // Se o número de mergulhadores e o número de retornos forem iguais
    {
      for (i = 0; i < qtsRetornou; i++) // laço de repetição que lê os mergulhadores que retornaram
        cin >> tmp;

      cout << "*\n";
    }
    else // se a quantidade de mergulhadores e de mergulhadores que retornaram são diferentes
    {
      short retornou[qtsMergulhou + 1];      // declaração de um vetor para armazenar os mergulhadores que retornaram
      memset(retornou, 0, sizeof(retornou)); // Inicializa o vetor com zero em todas as posições

      for (i = 0; i < qtsRetornou; i++) // Lê todos os mergulhadores que retornaram e marca as posições no vetor
      {
        cin >> tmp;
        retornou[tmp] = tmp; // armazena o mergulhador que retornou no vetor
      }

      for (i = 1; i <= qtsMergulhou; i++) // laço de repetição que verifica quais mergulhadores não retornaram
        if (retornou[i] == 0)
          cout << i << " "; // imprime o número do mergulhador que não retornou

      cout << endl; // Imprime uma quebra de linha
    }
    iguais = false;
  }

  return 0;
}
