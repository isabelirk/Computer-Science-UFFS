#include <bits/stdc++.h> // Inclui todas as bibliotecas padrão do C++

using namespace std; // permite o uso das funções e classes da biblioteca padrão do C++ sem o prefixo "std::"

char S[1000001];      // Declara uma string com tamanho máximo de 1000000
int N, odd, freq[26]; // Declara três inteiros: o comprimento da string, o caractere ímpar e a frequência de cada letra do alfabeto

int main()
{
  scanf("%s", S);

  N = (int)strlen(S); // Calcula o comprimento da string

  // Esta parte conta a frequência de cada letra maiúscula do alfabeto inglês na string S. A fórmula (int)(S[i] - 'A')
  // converte o caractere S[i] em um número inteiro entre 0 e 25, que representa a posição da letra correspondente na matriz freq.

  for (int i = 0; i < N; i++)
    freq[(int)(S[i] - 'A')]++; // incrementa o contador de frequência da letra correspondente da string usando a tabela ASCII

  odd = -1; // Define o caractere ímpar como -1, o que significa que não há nenhum caractere ímpar

  // Para que uma string possa ser permutada para formar um palíndromo, deve haver no máximo um caractere que aparece um número ímpar de
  // vezes na string. Se houver mais de um caractere que aparece um número ímpar de vezes na string, não é possível formar um
  // palíndromo. Se nenhum caractere aparecer um número ímpar de vezes, a string já é um palíndromo. A variável odd é usada para
  // armazenar o índice do caractere que aparece um número ímpar de vezes na string, se houver.

  for (int i = 0; i < 26; i++) // loop para percorrer todas as letras do alfabeto
  {
    if (freq[i] & 1) // verifica se a frequência da letra é ímpar
    {
      if (odd != -1) // verifica se já há uma letra com frequência ímpar
      {
        printf("NO SOLUTION\n");
        return 0; // Se houver mais de um caractere ímpar, a string não pode ser um palíndromo
      }
      else
      {
        odd = i; // Se houver apenas um caractere ímpar, define-o como o caractere ímpar da string
      }
    }
  }

  // o loop externo percorre todas as letras do alfabeto em ordem alfabética. O loop interno imprime a letra atual freq[i] / 2 vezes.
  // Como estamos procurando um palíndromo, precisamos garantir que cada letra apareça em pares, uma vez que a primeira metade da string
  // será igual à segunda metade, só que com as letras invertidas.

  for (int i = 0; i < 26; i++)
    for (int j = 0; j < freq[i] / 2; j++)
      printf("%c", (char)(i + 'A')); // Imprime a primeira metade da string ordenada em ordem alfabética

  if (odd != -1)                     // verifica se há alguma letra com frequência ímpar
    printf("%c", (char)(odd + 'A')); // imprime a letra correspondente

  // A primeira metade da string é impressa em ordem alfabética, a letra ímpar (se houver) é adicionada no meio e a segunda metade da
  // string é impressa em ordem inversa.

  for (int i = 25; i >= 0; i--)
    for (int j = 0; j < freq[i] / 2; j++)
      printf("%c", (char)(i + 'A')); // Imprime a segunda metade da string ordenada em ordem alfabética
  return 0;                          // retorna zero para indicar que a execução foi concluída com sucesso
}
