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

void merge(int * arr, int left, int right, int mid){
	int l1 = mid - left + 1;
	int l2 = right - mid;
	int * temp1 = (int *)calloc(sizeof(int), (unsigned int)l1);
	int * temp2 = (int *)calloc(sizeof(int), (unsigned int)l2);


	for (int i = 0 ; i < l1; i++){
		*(temp1 + i) = *(arr + left + i);
	}
	for (int j = 0; j < l2; j++){
		*(temp2 + j) = *(arr + mid + 1 + j);
	}

	int i = 0; // temp 1 array
	int j = 0; // temp 2 array
	int k = left; // main array

	while (i < l1 && j < l2){
		if (*(temp1 + i) >= *(temp2 + j)){
			*(arr + k) = *(temp2 + j);
			j++;
			k++;
		}
		else{
			*(arr + k) = *(temp1 + i);
			i++;
			k++;
		}
	}
	while (i < l1){
		*(arr + k) = *(temp1 + i);
		k++;
		i++;
	}
	while (j < l2){
		*(arr + k) = *(temp2 + j);
		k++;
		j++;
	}
}

void mergeSort(int * arr, int left, int right){
	if (right > left){
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, right, mid);
	}
}

void mergeSortIterative(int * arr, int n){
	int curr_size;
	int left_start;
	// see https://www.techiedelight.com/iterative-merge-sort-algorithm-bottom-up/
	// see https://www.geeksforgeeks.org/iterative-merge-sort/
	// for information regarding iterative implementation
	for (curr_size = 1; curr_size <= n - 1; curr_size = 2*curr_size){
		for (left_start = 0; left_start < n-1; left_start += 2*curr_size){
			int mid = min(left_start + curr_size - 1, n - 1);
			int right_end = min(left_start + 2*curr_size - 1, n-1);
			merge(arr, left_start, right_end, mid);
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
	mergeSortIterative(ourArray, length);
	cout << "Sorted array is :";
	for (int i = 0; i < length; i++){
		cout << *(ourArray + i) << " ";
	}
}