#include <iostream>
#include <variant>
#include <string>
using namespace std;

int main(){
    variant<int, string, char> data;
    data = 10; // output 0;
    data = "hello"; // 1;
    data = 'c'; // 2;
    cout << data.index();
}
