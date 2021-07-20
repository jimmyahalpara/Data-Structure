#include <iostream>
#include <stdlib.h>


using namespace std;

int main()
{
	int length;
	cout << "Enter the length of array:";
	cin >> length;


	int * first_array = (int *)calloc(sizeof(int), (unsigned int)length);
	cout << "Enter elements:" << endl;
	for (int i = 0; i < length; i++){
		cin >> *(first_array + i);
	}

	int min_pos = 0, max_pos = 0;
	for (int i = 0; i < length; i++){
		if (*(first_array + min_pos) > *(first_array + i)){
			min_pos = i;
		}
		if (*(first_array + max_pos) < *(first_array + i)){
			max_pos = i;
		}
	}

	cout << "Max. element :" << *(first_array + max_pos) << " Min. element :" << *(first_array + min_pos);
	return 0;
}