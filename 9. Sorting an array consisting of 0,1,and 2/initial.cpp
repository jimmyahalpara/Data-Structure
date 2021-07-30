#include <iostream>
#include <stdlib.h>



using namespace std;


void sort_array(int * our_array, int length){
	int * temp_array = (int *)calloc(sizeof(int), (unsigned int)length);

	for (int i = 0; i < length; i++){
		int value = *(our_array + i);
		int temp = *(temp_array + value);
		*(temp_array + value) = temp + 1;
	}

	int pointer = 0;
	int main_pointer = 0;
	while(main_pointer < length){
		if (*(temp_array + pointer) > 0){
			*(our_array + main_pointer) = pointer;
			main_pointer ++;
			int temp = (*(temp_array + pointer));
			*(temp_array + pointer) = temp - 1;
		}
		else{
			pointer ++;
		}
	}
}


int main(){
	int length;
	cout << "Enter length of an Array:";
	cin >> length;


	int * first_array = (int *)calloc(sizeof(int), (unsigned int)length);
	cout << "Enter array elements:";

	for (int i = 0; i < length; i++){
		cin >> *(first_array + i);
	}

	sort_array(first_array, length);

	for (int i = 0; i < length; i++){
		cout << *(first_array + i) << " ";
	}
}