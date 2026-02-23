#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
using std::next_permutation;
int main(){
    int j = 2;
    do{
        j = pow(j, 2);
        cout << "j: " << j << "\n";
    } while (j < 1000);
    cout << "\n" << endl;

    string s = "aba";
    sort(s.begin(), s.end()); // s is sorted 
    do cout << s << '\n';
    while (next_permutation(s.begin(), s.end()));
}