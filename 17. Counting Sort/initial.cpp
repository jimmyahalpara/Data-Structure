#include <iostream>
#include <stdlib.h>
#include <limits.h>


using namespace std;



void countingSort(int * arr, int length, int maxValue){
	// valueCount array for storing count of each numbers
	int * valueCount = (int *)calloc(sizeof(int), (unsigned int)maxValue + 1);

	for (int i = 0; i < length; i++){
		int pos = *(arr + i);
		int value = *(valueCount + pos);
		*(valueCount + pos)  = value + 1;
	}

	int pointer = 0;
	int i = 0;
	while (pointer < length){
		if (*(valueCount + i) > 0){
			*(arr + pointer) = i;
			pointer ++;
			int temp = (*(valueCount + i));
			*(valueCount + i) = temp - 1;
		}
		else{
			i++;
		}
	}
}


int main(){
	int length;
	cout << "Enter array length :";
	cin >> length;

	int * ourArray = (int *)calloc(sizeof(int), (unsigned int)length);
	cout << "Enter array elements :" << endl;


	int maxValue = INT_MIN;
	
	int temp;
	for (int i = 0; i < length; i++){
		cin >> temp;
		if (temp > maxValue){
			maxValue = temp;
		}
		
		*(ourArray + i) = temp;
	}

	countingSort(ourArray, length, maxValue);
	cout << "Sorted array is :";
	for(int i = 0; i < length; i++){
		cout << *(ourArray + i) << " ";
		
	}
}
