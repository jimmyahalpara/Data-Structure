#include <iostream>
#include <stdlib.h>


using namespace std;


void sortArray(int * arr, int length){
	for (int i = 0; i < length; i++){
		for (int j = 0; j < length - 1; j++){
			if (*(arr + j) > *(arr + j + 1)){
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}


int binarySearch(int * arr, int length, int element){
	int low = 0;
	int high = length - 1;
	int mid;
	while(low <= high){
		mid = (high + low)/2;
		if (*(arr + mid) > element){
			high = mid - 1;
		}
		else if (*(arr + mid) < element){
			low = mid + 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}


int main(){
	int length;
	cout << "Enter length of the array:";
	cin >> length;

	int * our_array = (int *)calloc(sizeof(int), (unsigned int)length);
	cout << "Enter array elements:" << endl;
	for (int i = 0; i < length; i++){
		cin >> *(our_array + i);
	}

	int element;
	cout << "Enter element to search :";
	cin >> element;
	//sortArray(our_array, length);
	cout << "Position of element " << element << " is " << binarySearch(our_array, length, element);

}