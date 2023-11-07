#include <iostream>
using namespace std;

int main()
{
  int i = 0, n[1000], t, j = 0; // Declara três inteiros: um índice, uma array de tamanho 1000 e um inteiro temporário

  cin >> t;

  while (i < 1000)
  {
    j = 0;

    while (j < t && i < 1000)
    {
      n[i] = j;                                    // Define o valor da array no índice i como j
      cout << "N[" << i << "] = " << n[i] << endl; // Imprime o valor da array no índice i
      j++;
      i++;
    }
  } // Loop que preenche a array com valores de 0 até t-1 e imprime cada valor da array seguido do seu índice na tela.

  return 0;
}
