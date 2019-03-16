#include <iostream>

using namespace std;

int* getBinary(int n);
int* whichBits(int n);
int* revBits(int *n);
bool ifZero(int *n);
int countBit(int n);

int main() {

	int num = 0;

	cout << "Enter an integer number less than 256:" << endl;
	cin >> num;
	cout << endl;

	cout << "Number of bits required to store your number " << countBit(num) << endl;

	int * arr = getBinary(num);

	cout << "Number " << num << " in binary " << endl;

	for(int i = 0; i < 8; i++){
		cout << arr[i];
	}
	cout << endl;

	arr = whichBits(num);

	cout << "Number of 1's is " << arr[1] << endl;
	cout << "Number of 0's is " << arr[0] << endl;

	cout << endl;

	arr = revBits(getBinary(num));

	cout << "Number " << num << " with 0's and 1's reversed " << endl;
	for (int i = 0; i < 8; i++) {
		cout << arr[i];
	}
	cout << endl;
	
	system("Pause");

	return 0;
}

int countBit(int n) {
	int count = 0, i;
	if (n == 0) return 0;
	for (i = 0; i < 32; i++) {
		if ((1 << i) & n)
			count = i;
	}
	return ++count;
}

int* getBinary(int n) {
	int* arr = new int[8];

	for (int i = 0; i < 8; i++) {
		if ((1 << i) & n) {
			arr[7 - i] = 1;
		}
		else {
			arr[7-i] = 0;
		}
	}
	return arr;
}

int* whichBits(int num) {
	int *arr = new int[2];

	int ones = 0, zeros = 0;

	for (int i = 7; i >= 0; i--) {
		if (num & (1 << i))	{
			ones++;
		}
		else {
			if (ones != 0) {
				zeros++;
			}
		}
	}

	arr[0] = zeros;
	arr[1] = ones;

	return arr;
}

//returns true if array consits only of 0's
bool ifZero(int *n) {
	bool key = true;
	int sum = 0;

	for (int i = 0; i < 8; i++) {
		sum |= n[i];
	}

	if (sum != 0) {
		key = false;
	}

	return key;
}


int* revBits(int *n){
	int* arr = new int[8];

	//first 1 in the array
	int elem = 0;

	for (int i = 0; i < 8; i++) {
		arr[i] = 0;
	}

	//check if all zeros
	if(!ifZero(n)){
		for (int i = 0; i < 8; i++) {
			if (n[i] == 1) {
				elem = i;
				break;
			}
		}

		for (int i = elem; i < 8; i++) {
			if (n[i] == 0) {
				arr[i] = 1;
			}
		}

		for (int i = 0; i < 8; i++) {
			cout << arr[i];
		}
	}

	return arr;
}

