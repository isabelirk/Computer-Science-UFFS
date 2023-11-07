#include <stdio.h>

int main(void){
	
	int a=1, b=1;
	double d=0;
	
	while(a <= 99){
		d += (a/b);
		a = a+2;
		b ++;
	}
	printf("S = %.2lf\n", d);
	
	return 0;
}
