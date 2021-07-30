#include <iostream>
#include <stdlib.h>



using namespace std;

void swap(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


// insertion sort pics one elemrnt from start and 
// insert it in sorted order.
void insertionSort(int * arr, int length){
	int i, j;
	// i will track which element will be selected
	// selected element will be inserted at correct position
	for (i = 1; i < length; i++){
		// key variable will temporarily store our selected element
		// all the comaprision will take place with key element
		// as value at that position in the array may change
		// j will point at selected value's left adjacent value
		int key = *(arr + i);
		j = i-1;
		// untill value at position j is larger than selected
		// value, we'll shift values present at j,
		// by one position right, untill value at j is less than key,
		// which means if any value at left is greater, it'll be shifted
		// to right, and at last key will be placed after(on left side of shifted)
		// value.
		while ((*(arr + j) > key) && (j > 0)){
			*(arr + j + 1) = *(arr + j);
			// we'll keep decrementing j so it'll check all the values present on left side
			j--;
		}
		*(arr + j + 1) = key;
	}
}


// same as iterative, but use recursion to sort elements present
// on left side of last value, then at last positions last value 
// on correct position.
void insertionSortRecursive(int * arr,  int length){
	if (length > 0){
		insertionSortRecursive(arr, length - 1);
		int key = *(arr + length - 1);
		int j = length - 2;
		while ((*(arr + j) > key) && (j > 0)){
			*(arr + j + 1) = *(arr + j);
			j--;
		}
		*(arr + j + 1) = key;
		
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

	insertionSortRecursive(ourArray, length);

	cout << "Sorted array is :";
	for (int i = 0; i < length; i++){
		cout << *(ourArray + i) << " ";
	}
}