#include <iostream>
#include <algorithm> // for_each(start, end, apply)
#include <vector>
using namespace std;
template<typename T>
int main(){
    vector<T> v = {1,2,3,4,5,6,7,8,9,0};
    auto print = [&](const int n){cout << n << ' ';}; // lambda function [reference->&](parameter->int n){function->n*=2}
    cout << "Before: " << " ";
    std::for_each(v.cbegin(), v.cend(), print); // output v // cbegin returns immutable iterators
    cout << "\n";

    //increment elements in-place
    std::for_each(v.begin(), v.end(), [](int& n){n++;});
    cout << "After: " << "\t";
    std::for_each(v.cbegin(), v.cend(), print);
    cout << "\n";

    struct Sum
    {
        void operator()(int n){sum+=n;}
        int sum{0}; //initialize sum to 0
    };

    // invoke Sum operator for each element
    Sum s; 
    s = for_each(v.begin(), v.end(), s);
    cout << "Sum: " << s.sum;
}