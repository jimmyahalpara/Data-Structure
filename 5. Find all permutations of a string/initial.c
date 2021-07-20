#include <stdio.h>
#include <stdlib.h>

void swap(char * a, char * b){
	char temp = *a;
	*a = *b;
	*b = temp;
}


// please watch  : https://www.youtube.com/watch?v=GuTPwotSdYw


void permutation(char * our_string, int low, int high){
	if (low == high){
		printf("%s\n", our_string);
	}
	else {
		int i;
		for (i = low; i <= high; i++){
			swap(our_string + i, our_string + low);
			permutation(our_string, low + 1, high);
			swap(our_string + i, our_string + low);
		}
	}
	
}



void main(){
	int length;
	printf("Enter length of the string:\n");
	scanf("%d", &length);

	char * first_string = (char*)calloc(sizeof(char), length);
	printf("Enter the string:\n");
	scanf("%s", first_string);


	printf("Permucations are --\n\n");
	permutation(first_string, 0, length - 1);

}