#include <stdio.h>


int main(){
	int fibonacci[1000000];
	fibonacci[0] = 1;
	fibonacci[1] = 1;
	int sum = 0;
	for(int i = 2; i < 1000000; i += 1){
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
		if(fibonacci[i] > 4000000){
			break;
		}
		else if(fibonacci[i] % 2 == 0){
			sum += fibonacci[i];
		}
	}
	printf("%d\n", sum);
}