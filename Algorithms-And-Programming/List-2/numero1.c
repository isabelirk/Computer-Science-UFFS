#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int n, i, n1, j=1, fatorial=0;
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d", &n1);
	    fatorial=n1;
		while(j<n1){
			fatorial= fatorial*(n1-j);
			j++;	
		}
		j=1;
		
    printf("Numero\n%d\nFatorial\n%d\n", n1, fatorial);
	}

return 0;		
}