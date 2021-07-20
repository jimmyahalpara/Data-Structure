#include <iostream>
#include <stdlib.h>



using namespace std;

void swap(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int min(int a, int b){
	if (a >= b){
		return b;
	}
	else {
		return a;
	}
}

// her we select last element as pivot
// we'll compare value present at j with each element
// if they are less than pivot, we'll pout it at left
// side of pivot.
// cant explain in words, you'll understand real working 
// by performing dry run using pen and paper
// https://www.geeksforgeeks.org/iterative-quick-sort/
int partition(int * arr, int low, int high){
	int pivot = *(arr + high);
	int i = low - 1;

	for (int j = low; j <= high - 1; j++){
		if (*(arr + j) < pivot){
			i++;
			swap(arr + j, arr + i);
		}
	}
	swap(arr + i + 1, arr + high);
	return i + 1;
}



void quickSort(int * arr, int low, int high){
	if (low < high){

		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


// we use stack instead of recursive calls.
void quickSortIterative(int * arr, int low, int high){
	int * stack = (int *)calloc(sizeof(int), (unsigned int)(high - low + 1));
	int top = -1;

	// storing initial values in stack
	*(stack + (++top)) = low; 
	*(stack + (++top)) = high;

	while (top >= 0){

		// pop high and low values from the stack
		int h = *(stack + (top--));
		int l = *(stack + (top--));

		// call partition and get pivot
		int p = partition(arr, l, h);

		// if there is elements on left hand side of pivot
		// then we'll push those positions to the stack
		if (p -1 > l){
			*(stack + (++top)) = l;
			*(stack + (++top)) = p - 1;
		}

		// if there is elements on right hand side of pivot
		// then we'll puch those positions to the stack.
		if (p + 1 < h){
			*(stack + (++top)) = p + 1;
			*(stack + (++top)) = h;
		}

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

	//mergeSort(ourArray, 0, length - 1);
	//mergeSortRecursive(ourArray, length);
	quickSortIterative(ourArray, 0, length - 1);
	cout << "Sorted array is :";
	for (int i = 0; i < length; i++){
		cout << *(ourArray + i) << " ";
	}
}