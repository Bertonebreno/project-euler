#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

#define LISTSIZE 100000000


int main(){

	ofstream file;
	file.open("primesSmallerThan1e+8.txt");

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

	int isFirst = 1;
	for(int i = 0; i < LISTSIZE; i += 1){
		if(isPrime[i] == 0){
			if(isFirst){
				file << "{";
				isFirst = 0;
			}
			else{
				file << ", ";
			}
			file << i;
		}
	}
	file << "}";

	file.close();
	free(isPrime);
}
