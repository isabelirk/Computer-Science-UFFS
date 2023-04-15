#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float funcao2ograu(float a, float b, float c, float x);
float calcularaiz1(float a, float b, float c);
float calcularaiz2(float a, float b, float c);
float min(float n1, float n2);
int buscavetor(int vetor[], int nbuscar);

float funcao2ograu(float a, float b, float c, float x){
    float y;
    y = (a * (x * x)) + (b * x) + c;
    return y;
}

float calcularaiz1(float a, float b, float c){
    float res, delta;
    delta = (b * b) - 4 * a * c;
    if((delta >= 0) && (2 * a != 0)){
        res = (-b + sqrt(delta)) / (2 * a);
        return res;
    }else
        return -9999999;
}

float calcularaiz2(float a, float b, float c){
   float res, delta;
    delta = (b * b) - 4 * a * c;
    if((delta >= 0) && (2 * a != 0)){
        res = (-b - sqrt(delta)) / (2 * a);
        return res;
    }else
        return -9999999;
}

float min(float n1, float n2){
    if(n1 < n2)
        return n2;
    else
        return n1;
}

int buscavetor(int vetor[], int nbuscar){
    int i;
    for(i=0; i<10; i++){
        if(nbuscar == vetor[i])
            return i;
    }
    return -1;
}

int main(void){
    float a, b, c, x, res, res2, n1, n2;
    int questao, i, vetor[10], nbuscar, res3;
    scanf("%d", &questao);
    switch(questao){
        case 2: scanf("%f %f %f %f", &a, &b, &c, &x);
                res = funcao2ograu(a, b, c, x);
                printf("y = %.2f\n", res);
                break;
        case 3: scanf("%f %f %f", &a, &b, &c);
                res = calcularaiz1(a, b, c);
                res2 = calcularaiz2 (a, b, c);
                if(res != -9999999 || res2 != -9999999){
                    if(res != res2)
                        printf("Raizes diferentes = %f %f\n", res, res2);
                    else
                        printf("Raizes iguais = %f\n", res);
                }else
                    printf("Raizes nao existem em reais.\n");
                break;
        case 4: scanf ("%f %f", &n1, &n2);
                res = min(n1, n2);
                if(res == n1)
                    printf("o menor eh = %.2f\n", n2);
                else
                    printf("o menor eh = %.2f\n", n1);
                break;
        case 5: printf("Digite os valores do vetor.\n");
                for(i=0; i<10; i++)
                    scanf("%d", &vetor[i]);
                printf("Digite o valor a ser buscado no vetor.\n");
                scanf("%d", &nbuscar);
                res3 = buscavetor(vetor, nbuscar);
                if(res3 != -1 )
                    printf("O numero buscado esta na posicao %d\n", res3);
                else
                    printf("O numero nao foi encontrado.\n");
                break;
        default: printf(";-; Esta questao nao existe!!! ;-;\n");
    }
    return 0;
}
