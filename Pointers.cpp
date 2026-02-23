#include <iostream>
using namespace std;

int main(){
    int x{5};
    cout << x << "\n";
    int* p{&x};
    cout << "X's adress is: [" << p << "] Which is 5" << endl;

    int* ptr {nullptr}; // pointer is now a null pointer, not holding an address
    int y{5};
    ptr = &y; // ptr now pointing at object (y)
    cout << "Y: " << *ptr << "\n";
    return 0;
}
