#include <iostream>
#include <algorithm> // max()
#include <string>
#include <limits> // std::numeric_limits<type>::min|max()
using namespace std;
using std::for_each;

int Even_numbers_function(const int arr[], int n){
    int even_numbers=0;
    for(int j=0; j<n; j++){
        if(arr[j]%2==0){
            even_numbers++;
        };
    }
    return even_numbers;
}

int Sum_function(const int arr[], int n){
    int sum = 0;
    auto add = [&](int a){sum+=a;};
    for_each(arr, arr+n, add);
    return sum;
}

void Display_function(const int arr[], int n){
    auto print = [&](int k){
        cout << k << ' ';
    };
    for_each(arr, arr+n, print);
}

int Max_number_function(const int arr[], int n){
    int current_max = std::numeric_limits<int>::min();
    auto find_max = [&](int x){
        current_max = std::max(current_max, x);
    };
    for_each(arr, arr+n, find_max);

    return current_max;
}

int main(){
    cout << "Enter the size of number\n";
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "number of even numbers: " << Even_numbers_function(arr, n) << endl;
    cout << "Max element: " << Max_number_function(arr, n) << "\n";
    cout << "All elements sum: " << Sum_function(arr, n) << endl;
    cout << "Elements " << endl;
    Display_function(arr, n);
    delete[] arr;
    return 0;
}