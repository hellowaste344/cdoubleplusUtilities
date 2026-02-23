#include <iostream>
using namespace std;

int main(){
    cout << "Enter the size of array:";
    int rows;
    cin >> rows;
	int* arr = new int[rows]; // we create a dynamic array
	for(int i = 0; i < rows; i++){
		cin >> arr[i];
	}

	for(int j = 0; j < rows/2; j++){
		int tmp = arr[j];
        arr[j] = arr[rows - j - 1];
        arr[rows - j - 1] = tmp;
	}
	for(int k = 0; k < rows; k++){
		cout << arr[k] << ' ';
	}
	delete[] arr; // free memory
	return 0;
}