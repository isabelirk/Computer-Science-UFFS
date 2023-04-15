#include <stdio.h>

int main (void){
	
	int n, media=0, cont=0;
	
	while(scanf("%d", &n), n<0){
		media = media + n;
		cont ++;
	}
	printf("Media: %d\n", media/cont);
	
	return 0;
}
