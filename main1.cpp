#include <iostream>
#include <string>
using namespace std;


void EvenNumbers(string number, int& n){
    for(int i = 0; i < number.length(); i++){
        int digit = number[i] - '0';
        if(digit % 2 == 0){ n++;}
    }
}

int main(){
    cout << "Enter the number" << endl;
    string number;
    int n = 0;
    getline(cin, number, '\n');
    EvenNumbers(number, n);
    cout << n;
}