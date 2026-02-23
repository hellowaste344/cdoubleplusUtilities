#include <iostream>
#include <memory>
using namespace std;

int main(){
    
    int *nptr;
    nptr = new int(6);
    cout << *nptr << endl;
    cout << nptr << endl;
    delete nptr;

    //if allocation fails, don't crash, just give me nullptr.
    int *p = new (nothrow) int(10);
    if(!p){
        cout << "memory allocation failed!"<< endl;
        exit(0);
        return 1;
    }
    cout << *p << "\n";
    delete p;

    int* arr;
    arr = new int[5]{1,2,3,4,5};
    for(int i=0; i<5; i++){
        cout << "arr[" << i << "] is: " <<  arr[i] << endl; 
    }
    delete[] arr; //free memory
    
    //smart pointer
    //no memory leak
    auto p1 = std::make_unique<int>(20); //p1 becomes nullptr
    auto p2 = std::move(p1); //ownership transfer
    cout << *p2 << " : " << p2.get(); //value : address
    return 0;
}