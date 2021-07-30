#include <iostream>
#include <stdlib.h>



using namespace std;

void swap(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_array(int * our_array, int length){
	int low = 0;
	int mid = 0;
	int high = length - 1;

	while (mid <= high){
		switch(*(our_array + mid)){
			case 0:
				swap(our_array + low, our_array + mid);
				low ++;
				mid ++;
				break;
			case 1:
				mid ++;
				break;
			case 2:
				swap(our_array + low, our_array + high);
				high --;
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