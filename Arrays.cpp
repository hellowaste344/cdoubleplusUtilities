#include <iostream>
#include <algorithm>
using namespace std;

void arr_Function(int arr[][3], int rows, int cols){

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = i + j;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	const int rows = 10;
	const int cols = 3;
	
	int arr[rows][cols];

	arr_Function(arr, rows, cols);

	return 0;
}