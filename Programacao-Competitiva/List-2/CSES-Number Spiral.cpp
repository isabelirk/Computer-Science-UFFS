#include <bits/stdc++.h> // inclui todas as bibliotecas padrão do C++

using namespace std;  // permite o uso das funções e classes da biblioteca padrão do C++ sem o prefixo "std::"
typedef long long ll; // define um alias para o tipo long long, chamado de ll

int T;   // declara a variável T para o número de casos de teste
ll X, Y; // declara as variáveis X e Y como long long

ll solve(ll x, ll y) // função que recebe dois valores long long e retorna um valor long long
{
  ll l = max(x, y) - 1; // calcula o valor l como o maior entre x e y, subtraído por 1

  if (l & 1) // se l for ímpar
  {
    if (x < y)          // se x for menor que y
      return l * l + x; // retorna o valor l^2 + x
    else
      return l * l + 2 * l - y + 2; // retorna o valor l^2 + 2l - y + 2
  }
  else // senão, se l for par
  {
    if (x < y)                      // se x for menor que y
      return l * l + 2 * l - x + 2; // retorna o valor l^2 + 2l - x + 2
    else
      return l * l + y; // retorna o valor l^2 + y
  }
}

int main()
{
  scanf("%d", &T); // lê o número de casos de teste

  for (int t = 0; t < T; t++) // repete para cada caso de teste
  {
    scanf("%lld %lld", &X, &Y);    // lê os valores de X e Y
    printf("%lld\n", solve(X, Y)); // chama a função solve com X e Y como parâmetros e imprime o valor retornado
  }
  return 0; // retorna zero para indicar que a execução foi concluída com sucesso
}