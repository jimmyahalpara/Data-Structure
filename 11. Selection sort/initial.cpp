#include <iostream>
#include <stdlib.h>



using namespace std;

void swap(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void selectionSort(int * arr, int n){
	int i,j, minPos;
	for (i = 0; i < n - 1; i++){
		minPos = i;
		for (j = i + 1; j < n; j++){
			if (*(arr + j) < *(arr + minPos)){
				minPos = j;
			}
		}
		swap(arr + i , arr + minPos);

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

	selectionSort(ourArray, length);

	cout << "Sorted array is :";
	for (int i = 0; i < length; i++){
		cout << *(ourArray + i) << " ";
	}
}