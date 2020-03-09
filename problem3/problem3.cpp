#include <stdio.h>
#include <stdlib.h>
#define LISTSIZE 10000000


int main(){ 
	int *isPrime = (int *) malloc(sizeof(int)*LISTSIZE);
	isPrime[0] = 1; //0 is not a prime number
	isPrime[1] = 1; //1 is not a prime number
	long int targetNumber = 600851475143;

	for(int i = 2; i < LISTSIZE; i += 1){
		if(isPrime[i] == 0){
			for(int j = 2; i*j < LISTSIZE; j += 1){
				isPrime[i*j] = 1;
			}
		}
	}
	int testNumber = -1;
	while(1){
		if(targetNumber < LISTSIZE){
			if(isPrime[targetNumber] == 0){
				break;
			}
		}
		for(int i = 2; i < LISTSIZE; i += 1){
			if(isPrime[i] == 0 && targetNumber % i == 0){
				targetNumber = targetNumber/i;
				printf("%d\n", i);
			}
		}
		if(testNumber == targetNumber){
			break;
		}
		testNumber = targetNumber;
	}
	printf("%ld\n", targetNumber);
}