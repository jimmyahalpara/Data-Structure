#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;



// reverse function takes a pointer to character array, an integer low
// and integer high, it make inplace changes to the character array
// to reverse the elements between low(included) and high(excluded) or high - 1(included)
void reverse(char * first_string, int low, int high){
	high --;
	while (low < high){
		char temp = *(first_string + low);
		*(first_string + low) = *(first_string + high);
		*(first_string + high) = temp;
		low++;
		high--;
	}
}

int main(){
	int length;
	//cout << "Enter length of the string:";
	//cin >> length;

	char * first_string = (char *)calloc(sizeof(char), (unsigned int)50);
	cout << "Enter the string(max 50):";
	cin.getline(first_string, 50);
	cout << "Enter length of the string:";
	cin >> length;
	cout << "Original String string is :" << first_string << endl;


	// we initialize 2 pointer, pointer left will remain on left side of any word
	// pointer_right will go up to end of the word(till space is encountered)

	int pointer_left = 0;
	int pointer_right = 0;

	// we loop until both the pointers are in range
	while ((pointer_left < length) && (pointer_right < length)){
		// normally we'll iterate and increment both the pointers
		// but if any non space character is encountered, it means it is start of some word
		// we'll stop incrementing left pointer, and keep on incrementing right pointer 
		// until first space is encountered(after word end).

		if (*(first_string + pointer_left) != ' '){

			// this loop keep on incrementing right pointer untill it is in range of string and space is not encountered
			while (*(first_string + pointer_right) != ' ' && pointer_right < length){
				pointer_right ++;
			}

			// if space is encountered or right pointer reach stirng's end, loop breaks
			// at this point, left pointer is on first character of the word, and right pointer
			// is on right adjacent character of word's last character.
			reverse(first_string, pointer_left, pointer_right);

			// after reversing the word, we'll update pointer left to again start search for another 
			// word start.
			pointer_left = pointer_right;
		}
		else{
			pointer_right++;
			pointer_left++;
		}
	}
	cout << "Reverse words string is :" << first_string;

}