#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int safeDivision(int value){
    if (value == 0){
        throw runtime_error("Division by zero is not allowed");
    }
    return 100 / value;
}

void processNumbers(const vector<int>& numbers)
    {
    for (int n : numbers){
        try{
            int result = safeDivision(n);
            cout << "Result: " << result << endl;
        }
        catch(const runtime_error& e){
            cout << "ERROR: " << e.what() << endl;
        }
    }
}

int main(){
    vector<int> numbers;
    cout << "Enter numbers, type -1 to quit" << endl;

    while (true){
        int k;
        if (!(cin >> k)){
            cerr << "Invalid input. Exiting..." << endl;
            return 1;
        }
    
        if (k == -1) break;
        numbers.push_back(k);
    }

    processNumbers(numbers);
    return 0;
}