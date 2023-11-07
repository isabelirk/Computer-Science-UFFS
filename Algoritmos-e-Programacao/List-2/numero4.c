#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int i, cont=0;
	float mc=1.5, mz=1.1;
	
	for(i=0; mz>mc; i++){
		mc = mc + 2;
		mz = mz + 3;
		cont = cont + 1;
	}
	printf("Ze vai levar %d anos para ser maior que Chico.", cont);
	
	return 0;
}

