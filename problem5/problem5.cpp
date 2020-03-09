#include <stdio.h>

int main(){
	int sumOfSquares = 100*(100+1)*(2*100+1)/6;
	int squaredSum = (100*(100+1)/2)*(100*(100+1)/2);

	printf("%d\n", squaredSum - sumOfSquares);
}