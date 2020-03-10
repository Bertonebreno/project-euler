#include <stdio.h>
#include <stdlib.h>
#define LISTSIZE 1000000
#define MAXTRIANGULARNUMBER 1000000

int factorList[MAXTRIANGULARNUMBER];
int lastNumber = -1;
int factorListCounter = 0;
int isPrime[LISTSIZE];

void getFactors(int targetNumber){
	while(1){
		if(targetNumber == 1){
			break;
		}
		for(int i = 2; i <= targetNumber; i++){
			if(!isPrime[i] && targetNumber % i == 0){
				targetNumber /= i;
				if(i == lastNumber){
					factorList[factorListCounter] += 1;
				}
				else{
					factorListCounter += 1;
					factorList[factorListCounter] +=1;
					lastNumber = i;
				}
				i -= 1;
			}
		}
	}
	factorList[factorListCounter+1] = -1;
}

int main(){ 
	isPrime[0] = 1; //0 is not a prime number
	isPrime[1] = 1; //1 is not a prime number
	int numberOfDivisor;
	int triangularNumber = 0;

	for(int i = 2; i < LISTSIZE; i += 1){
		if(isPrime[i] == 0){
			for(int j = 2; i*j < LISTSIZE; j += 1){
				isPrime[i*j] = 1;
			}
		}
	}

	for(int i = 2; i < MAXTRIANGULARNUMBER; i+=1){
		triangularNumber = i*(i-1)/2;
		numberOfDivisor = 1;
		lastNumber = -1;
		factorListCounter = -1;

		for(int i = 0; i < MAXTRIANGULARNUMBER; i++){
			if(factorList[i] == -1){
				factorList[i] = 0;
				i = MAXTRIANGULARNUMBER;
			}
			factorList[i] = 0;
		}

		getFactors(triangularNumber);
		for(int i = 0; i < MAXTRIANGULARNUMBER; i++){
			if(factorList[i] == -1){
				i = MAXTRIANGULARNUMBER;
			}
			else{
				numberOfDivisor *= (factorList[i]+1);
			}
		}
		if(numberOfDivisor > 500){
			printf("%d: %d\n", triangularNumber, numberOfDivisor);
		}	
	}
}
