#include <stdio.h>

int main(void){

int n=92, i, primo, cont=0;

while(n <= 1487){
	for(i = 1; i <= n && cont >= 3; i++){
		if(n % i == 0){
		cont ++;
		primo = n;
		}
	}
		if(cont == 2)
		primo = primo * n;
	n++;	
}
printf("%d", primo);

return 0;
}

