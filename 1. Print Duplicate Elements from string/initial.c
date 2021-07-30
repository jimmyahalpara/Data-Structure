#include <stdio.h>
#include <stdlib.h>





void main(){
	int length; //length stores length of string to be searched
	int * num_char = (int *)calloc(sizeof(int),  ((int)'z' - 'A'));  
	// num_char is integer array which stores number of occurance of each character
	// integer at position 0 stores number of occurance of 'A' character
	// integer at position 1 stores number of occurance of 'z' character
	// we substract ascii value of A from ascii value of z, to get total number of characters needed to store all
	// capitial and small alphabets.

	// prompting and taking length of string
	printf("Enter length of string:\n");
	scanf("%d", &length);
	
	// defining character array to store string
	char * first_string = (char *)malloc(sizeof(char) * length);
	
	// prompting and taking string input
	printf("Enter the string:");
	scanf("%s", first_string);
	
	// confirming entered string
	printf("Original string is : %s\n", first_string);


	// iterating through string and increamenting count in num_char array for corresponding characters.
	for (int i = 0; i< length; i++){

		// currect_character - character which is currently being scanned will be stored here.
		char current_character = *(first_string + i);
		// substract 'A' to find count position in num_char array.
		int character_position = current_character - 'A';

		// storing previous value of count ina variable
		int count = *(num_char + character_position);
		// updating the variable and storing is back to same position
		*(num_char + character_position) = count + 1;
	}
	

	// iterating through entire num_char array, and printing the character if count is more than one.
	// here 57 is the length of our array, it is equal to (int)'z' - 'A'
	for (int i = 0; i< 57; i++){
		
		// selecting each value and comparing it with 1.
		if (*(num_char + i) > 1){
			printf("%c ", 'A' + i);
		}
	}
	
}