#include <stdio.h>
#include <stdlib.h>

// logic - use use stack(obviously we are not making our own stack), we use functional stack
// every function called is added to the stack
// we call reverse function recursively untill last character is encountered.
// last function call will be of null value at the end of the string
// but in that case if statement inside the reverse function will not be executed
// thus from that point onward our functional stacks starts clearing
// in second last function call, pointer passed was on last character of the string(other than null)
// that function's executing will be finished causing the last character to be printed 
// and that call will be removed form functional stack.
// then second last character will be printed in same way, untill all the functions are executed.
void reverse(char * our_string){
	if (*our_string){
		reverse(our_string + 1);
		printf("%c", *our_string);
	}
}


int main(int argc, char const *argv[])
{
	int length;
	printf("Enter the length of the string:");
	scanf("%d", &length);


	char * first_string = (char *)calloc(sizeof(char), length);
	printf("Enter the string:\n");
	scanf("%s", first_string);
	printf("String you entered is :%s\n", first_string);


	reverse(first_string);
	return 0;
}