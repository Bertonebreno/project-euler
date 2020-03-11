#include <stdio.h>

int main(){

	int biggestSequence = -1, currentSequence = 1;
	long int biggestNumber, initialNumber;

	int isValueKnown[1000000];

	for(int i = 0; i < 1000000; i += 1){
		isValueKnown[i] = -1;
	}
	isValueKnown[1] = 1;

	for(int i = 2; i < 1000000; i += 1){
		initialNumber = i;
		currentSequence = 1;
		while(initialNumber != 1){
			if(initialNumber < 1000000){	
				if(isValueKnown[initialNumber] != -1){
					currentSequence += isValueKnown[initialNumber]-1;
					break;
				}
			}
			if(initialNumber % 2 == 0){
				currentSequence += 1;
				initialNumber = initialNumber/2;
			}
			else{
				currentSequence += 1;
				initialNumber =  3*initialNumber + 1;
			}
		}

		isValueKnown[i] = currentSequence;
		if(currentSequence > biggestSequence){
			biggestSequence = currentSequence;
			biggestNumber = i;
		}
	}
	printf("%ld: %d\n", biggestNumber, biggestSequence);
}