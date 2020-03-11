#include <stdio.h>

long long unsigned int factorial(int x){
	long long unsigned int product = 1;
	for(x ; x > 1; x -= 1){
		product *= x;
	}
	return product;
}

int main(){
	long long unsigned int product = 1;

	product *= factorial(40);
	printf("%lld\n", product);

	product /= factorial(20);
	printf("%lld\n", product);

	product /= factorial(20);
	printf("%lld\n", product);
}