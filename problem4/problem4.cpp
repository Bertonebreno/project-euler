#include <stdio.h>
#define MAXNUMBER 998001


int main(){
	int possiblePalindrome, reverseNumber, remainder, tempValue;	
	int maxPalindrome = 0;
	
	for(int i = 999; i > 99;i -= 1){
		for(int j = i; j > 99;j -= 1){

			possiblePalindrome = i*j;
			tempValue = possiblePalindrome;
			reverseNumber = 0;
			while(tempValue >= 1){
				remainder = tempValue % 10;
				reverseNumber = reverseNumber*10 + remainder;
				tempValue = tempValue/10;
			}
			if(reverseNumber == possiblePalindrome){
				printf("%d\n", possiblePalindrome);
				if(possiblePalindrome > maxPalindrome){
					maxPalindrome = possiblePalindrome;
				}
			}
		}
	}
	printf("\n%d", maxPalindrome);
}