#include <iostream>
#include <stdio.h>

using namespace std;



// this reverse method will use 2 pointers, one on extreme left and another on extrement right.
// then keep on exchanging values present in those 2 pointers, then decrement the high pointer 
// and increment the low pointer, untill they are same.
void reverse(int * my_array, int length){
	int low = 0;
	int high = length - 1;
	while (low < high){
		int tmp = *(my_array + low);
		*(my_array + low) = *(my_array + high);
		*(my_array + high) = tmp;
		low++;
		high--;
	}
}

int main(){
	int length;
	cout << "Enter length of array:";
	cin >> length;

	int * integer_array = (int *)calloc(sizeof(int), (unsigned int)length);
	cout << "Enter array elements:\n";
	for (int i = 0; i < length; i++){
		cin >> *(integer_array + i);
	}

	cout << "Array in reverse order is :" << endl;
	reverse(integer_array, length);
	for (int i = 0; i < length; i++){
		cout << *(integer_array + i) << " ";
	}
	return 0;
}