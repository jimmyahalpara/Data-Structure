#include <stdio.h>
#include <stdlib.h>

// we'll count the characters, if number of each characters
// if number of each characters are same then strings are anagrams


void main(){
	int length; //length stores length of string to be searched
	printf("Enter Length of the string:");
	scanf("%d%d", &length);

	// defining character array to store string
	char * first_string = (char *)calloc(sizeof(char), length);
	char * second_string = (char *)calloc(sizeof(char), length);

	// prompting and taking string input
	printf("Enter first string:");
	scanf("%s", first_string);
	printf("Enter second string");
	scanf("%s", second_string);


	printf("First string is %s, second string is %s\n", first_string, second_string);

	int * num_char_first = (int *)calloc(sizeof(int), (int)'z' - 'A');
	int * num_char_second = (int *)calloc(sizeof(int), (int)'z' - 'A');
	// num_char is integer array which stores number of occurance of each character
	// integer at position 0 stores number of occurance of 'A' character
	// integer at position 1 stores number of occurance of 'z' character
	// we substract ascii value of A from ascii value of z, to get total number of characters needed to store all
	// capitial and small alphabets.

	// prompting and taking length of string


	// counting number of each characters in both the array
	for (int i = 0; i < length; i++){

		char current_character = *(first_string + i);
		int character_position = current_character - 'A';
		int count  = *(num_char_first + character_position);
		*(num_char_first + character_position) = count + 1;
	}
	for (int i = 0; i < length; i++){

		char current_character = *(second_string + i);
		int character_position = current_character - 'A';
		int count  = *(num_char_second + character_position);
		*(num_char_second + character_position) = count + 1;
	}


	// comparing counts of both the strings, if flat is one, 
	// then both strings are anagrams
	// if any count is not equal then flag will become zero
	// if flag is zero then both strings are not anagrams
	int flag = 1;
	for (int i = 0; i < 57; i++){
		//printf("%d %d\n", *(num_char_first + i), *(num_char_second + i));
		if (*(num_char_first + i) != *(num_char_second + i)){
			flag = 0;
		}
	}

	if (flag){
		printf("String is anagram\n");
	}
	else{
		printf("String is not anagram\n");
	}
}