#include <stdio.h>

int main(){

	for(int a = 1; a < 499; a += 1){
		for(int b = a; b > 0; b -= 1){
			if( ((1000-(a+b))*(1000-(a+b)) + a*b + b*(1000-(a+b)) + a*(1000-(a+b))) == 500000){
				printf("%d, %d\n", a, b);
			}
		}
	}
}