#include <iostream>
#include <string>
using namespace std;

template <typename T>

class Box{
public:
    T value;
    Box(T v) : value(v) {}
};

template <typename K>
K add(K a, K b){
    return a + b;
}

int main(){
    Box<int> b1(10);
    Box<string> b2("Hi");

    cout << b1.value << endl;
    cout << b2.value << endl;
    
    cout << add<int>(4,5) << "\n";
    cout << add<double>(4.3,3.2) << "\n";
}