#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int n, i, matricula=0;
	float nota=0.0;
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d %f", &matricula, &nota);
		
		if(nota>=9.0){
			printf("Matricula: %d. Conceito: A\n", matricula);
		}
			
		else if(nota>=7.0){
			printf("Matricula: %d. Conceito: B\n", matricula);
		}
			
		else if(nota>=5.0){
			printf("Matricula: %d. Conceito: C\n", matricula);
		}

		else{
			printf("Matricula: %d. Conceito: D\n", matricula);
		}
	}
	
return 0;	
}
