#include <stdio.h>
#include <stdlib.h>

void main(){
	int length;
	int * num_char = (int *)calloc(sizeof(int), ((int)'z' - 'A'));
	


	printf("Enter length of string: ");
	scanf("%d", &length);


	char * first_string = (char *)malloc(sizeof(char) * length);


	printf("Enter the string:");
	scanf("%s", first_string);


	printf("String you entered is %s\n", first_string);

	
	//counting characters 
	for (int i = 0; i < length; i ++){
		char current_character = *(first_string + i);

		int character_position = current_character - 'A';

		int count = *(num_char + character_position);

		*(num_char + character_position) = count + 1;
	}
	int i;
	for (i = 0; i < length; i ++){
		char current_character = *(first_string + i);

		int character_position = current_character - 'A';

		int count = *(num_char + character_position);

		if (count == 1){
			printf("First non repeating character is : %c\n", current_character);
			break;
		}
	}
	if (i == length){
		printf("All the characters are repeating\n");	
	}
}