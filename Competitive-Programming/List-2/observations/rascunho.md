1. `#include <iostream>`: inclui a biblioteca de entrada/saída de fluxo de dados padrão.
2. `#include <cstring>`: inclui a biblioteca para manipulação de strings e arrays de caracteres.
3. `using namespace std;`: define o namespace padrão a ser usado.
4. `int main()`: a função principal que retorna um inteiro.
5. `short i;`: declara uma variável inteira curta sem sinal chamada `i`.
6. `short tmp;`: declara uma variável inteira curta sem sinal chamada `tmp`.
7. `short qtsMergulhou, qtsRetornou;`: declara duas variáveis curtas sem sinal para armazenar o número de pessoas que mergulharam e o número de pessoas que retornaram.
8. `bool iguais = false;`: declara uma variável booleana chamada `iguais` e a inicializa como `false`.
9. `while (cin >> qtsMergulhou >> qtsRetornou)`: lê os valores de `qtsMergulhou` e `qtsRetornou` da entrada padrão usando o operador de fluxo de entrada `>>`.
10. `if (qtsMergulhou == qtsRetornou)`: verifica se o número de pessoas que mergulhou é igual ao número de pessoas que retornou.
11. `iguais = true;`: atribui `true` à variável `iguais` se o número de pessoas que mergulhou é igual ao número de pessoas que retornou.
12. `for (i = 0; i < qtsRetornou; i++)`: um loop que lê os valores de retorno da entrada padrão e os descarta.
13. `cin >> tmp;`: lê o valor de retorno da entrada padrão e o armazena em `tmp`.
14. `cout << "*\n";`: escreve um asterisco na saída padrão seguido de uma nova linha.
15. `else`: caso contrário, ou seja, se o número de pessoas que mergulhou for diferente do número de pessoas que retornou.
16. `short retornou[qtsMergulhou + 1];`: declara um array chamado `retornou` com o tamanho `qtsMergulhou + 1`.
17. `memset(retornou, 0, sizeof(retornou));`: preenche o array `retornou` com zeros.
18. `for (i = 0; i < qtsRetornou; i++)`: um loop que lê os valores de retorno da entrada padrão e armazena os valores no array `retornou`.
19. `cin >> tmp;`: lê o valor de retorno da entrada padrão e o armazena em `tmp`.
20. `retornou[tmp] = tmp;`: atribui o valor de `tmp` ao índice `tmp` do array `retornou`.
21. `for (i = 1; i <= qtsMergulhou; i++)`: um loop que percorre todos os valores de `1` a `qtsMergulhou`.
22. `if (retornou[i] == 0)`: verifica se o valor do índice `i` do array `retornou` é zero.
23. `cout << i << " ";`: escreve o valor de `i
