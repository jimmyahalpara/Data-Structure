#include <iostream>
#include <stdlib.h>



using namespace std;

void swap(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void bubbleSort(int * arr, int length){
	int i, j;
	for (i = 0; i < length; i++){
		for (j = 0; j < length - i - 1; j++){
			// above line uses j < length - i - 1, because
			// after each pass of bubble sort, maximum element
			// will be at last position
			// this fact is also utilized in implementation
			// of bubble sort recursive, while 
			// calling that function again, length of the 
			// array passed is length - 1.
			if (*(arr + j) > *(arr + j + 1)){
				swap(arr + j, arr + j + 1);
			}
		}
	}
}


// this recursive bubble sort use recursion instead of 
// one for loop. Try to compare both the implementation 
// to understand working
void bubbleSortRecursive(int * arr, int length){
	int i;
	if (length > 0){
		for (i = 0; i < length - 1; i++){
			if (*(arr + i) > *(arr + i + 1)){
				swap(arr + i, arr + i + 1);
			}
		}
		bubbleSortRecursive(arr, length - 1);
	}
	
}



int main(){
	int length;
	cout << "Enter array length :";
	cin >> length;

	int * ourArray = (int *)calloc(sizeof(int), (unsigned int)length);
	cout << "Enter array elements :" << endl;

	for (int i = 0; i < length; i++){
		cin >> *(ourArray + i);
	}

	bubbleSortRecursive(ourArray, length);

	cout << "Sorted array is :";
	for (int i = 0; i < length; i++){
		cout << *(ourArray + i) << " ";
	}
}