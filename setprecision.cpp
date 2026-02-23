#include <iostream>
#include <iomanip> // set precision
using namespace std;

int main(){
    double pi = 3.141592653589793;
    cout << setprecision(4) << pi << endl; // total digits
    cout << fixed << setprecision(4) << pi << endl; // digits after decimal
    cout << setprecision(10) << pi << endl;
}