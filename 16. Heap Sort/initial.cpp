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


void heapify(int arr[], int n, int i){
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;


	if (left < n && arr[left] > arr[largest]){
		largest = left;
	}
	if (right < n && arr[right] > arr[largest]){
		largest = right;
	}

	if (largest != i){
		swap(arr + i, arr + largest);
		heapify(arr, n, largest);
	}
}

// Read https://www.programiz.com/dsa/heap-sort for explaination
void heapSort(int arr[],int n){
	for (int i = n / 2 - 1; i >= 0; i--){
		heapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--){
		swap(arr+ i, arr);

		heapify(arr, i, 0);
	}
}

int main(){
	int length;
	cout << "Enter array length :";
	cin >> length;

	int * ourArray = (int *)calloc(sizeof(int), (unsigned int)length);
	cout << "Enter array elements :" << endl;

	for (int i = 0; i < length; i++){
		cin >> ourArray[i];
	}

	heapSort(ourArray, length);
	cout << "Sorted array is :";
	for (int i = 0; i < length; i++){
		cout << *(ourArray + i) << " ";
	}
}
