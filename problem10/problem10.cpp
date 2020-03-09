#include <stdio.h>
#include <stdlib.h>
#define LISTSIZE 2000000

int main(){

	int *isPrime = (int *) malloc(sizeof(int)*LISTSIZE);
	isPrime[0] = 1; //0 is not a prime number
	isPrime[1] = 1; //1 is not a prime number
	for(int i = 2; i < LISTSIZE; i += 1){
		if(isPrime[i] == 0){
			for(int j = 2; i*j <= LISTSIZE; j += 1){
				isPrime[i*j] = 1;
			}
		}
	}

	long int sum = 0;
	for(int i = 0; i < LISTSIZE; i += 1){
		if(isPrime[i] == 0){
			sum += i;
		}
	}

	printf("%ld\n", sum);
	free(isPrime);
}