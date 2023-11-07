#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grupo_musical{
    char nome[30];
    char estilo[30];
    int integ;
    int posi;
} grupo;

void procuraposicao(grupo banda[], int n);
void procuraestilo(grupo banda[], char estilo_m[]);
void procurabanda (grupo banda[], char nome_banda[]);

void procuraposicao(grupo banda[], int n){
    int i;
    for(i=0; i<5; i++){
        if(banda[i].posi == n){
            printf("Banda: %s\nEstilo: %s\nItegrantes %d\nPosicao dos favoritos: %d\n", banda[i].nome, banda[i].estilo, banda[i].integ, banda[i].posi);
        }
    }
}

void procuraestilo(grupo banda[], char estilo_m[]){
    int i;
    for(i=0; i<5; i++){
        if(strcmp(estilo_m,banda[i].estilo) == 0)
            printf("%s\n", banda[i].nome);
    }
}

void procurabanda (grupo banda[], char nome_banda[]){
    int i;
    for(i=0; i<5; i++){
        if(strcmp(nome_banda,banda[i].nome) == 0)
            printf("Esta nos seus favoritos\n");
        else
            printf("Nao esta nos seus favoritos\n");
    }
}

int main(void){
    int i, n, caso;
    char estilo_m[30], nome_banda[30];
    grupo banda[5];

    do{
        printf("Digite 1 para: inserir as bandas e suas caracteristicas\n");
        printf("Digite 2 para: imprimir as bandas e suas caracteristicas\n");
        printf("Digite 3 para: procurar alguma banda em seus favoritos\n");
        printf("Digite 4 para: procurar alguma banda por estilo musical\n");
        printf("Digite 5 para: procurar alguma banda pelo nome\n");
        scanf("%d", &caso);
        getchar();

        switch(caso){
            case 1: printf("Digite as caracteristicas das bandas\n");
                    for(i=0; i<5; i++){
                    printf("Digite o nome\n");
                    scanf("%[' ' A-z a-z 0-9]s", banda[i].nome);
                    getchar();
                    printf("Digite o estilo\n");
                    scanf("%[' ' A-z a-z]s", banda[i].estilo);
                    getchar();
                    printf("Digite a quantidade de integrantes e a posicao nos favoritos\n");
                    scanf("%d %d", &banda[i].integ, &banda[i].posi);
                    getchar();
                    }
                    break;

            case 2: for(i=0; i<5; i++){
                        printf("Banda: %s\nEstilo: %s\nItegrantes %d\nPosicao dos favoritos: %d\n", banda[i].nome, banda[i].estilo, banda[i].integ, banda[i].posi);
                        printf("\n");
                    }
                    break;

            case 3: printf("Digite a posicao da banda nos favoritos\n");
                    scanf("%d", &n);
                    getchar();
                    procuraposicao(banda, n);
                    break;

            case 4: printf("Digite o estilo musical\n");
                    scanf("%[' ' A-Z a-z]s", estilo_m);
                    getchar();
                    procuraestilo(banda, estilo_m);
                    break;

            case 5: printf("Digite o nome de uma banda\n");
                    scanf("%[' 'A-Z a-z]s", nome_banda);
                    getchar();
                    procurabanda(banda, nome_banda);
                    break;

            default: printf("Esta opcao nao existe!!! ;-;\n");
        }
    }while(caso);
    return 0;
}
