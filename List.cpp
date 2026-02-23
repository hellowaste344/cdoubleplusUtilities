#include <iostream>
#include <list>  
using namespace std;

int main(){
    list<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    for(int x : numbers){
        cout << x << ' ';
    }
    return 0;
}