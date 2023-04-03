#include <iostream>

using namespace std;

int main()
{

  int n, k, categoria;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &k);
    for (int j = 0; j < k; j++)
    {
      scanf("%d", &categoria);
      if (categoria == 1)
        printf("Rolien\n");
      else
      {
        if (categoria == 2)
          printf("Naej\n");
        else if (categoria == 3)
          printf("Elehcim\n");
        else
          printf("Odranoel\n");
      }
    }
  }

  return 0;
}