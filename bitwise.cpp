#include <algorithm> // transform
#include <functional> // bit_and
#include <iostream> 
#include <iterator> // end
using namespace std;

int main(){
    int xyz[] = {500,600,300,800,200};
    int abc[] = {0xf, 0xf, 0xf, 255, 255};
    int n = 5;

    int results[n];

    transform(begin(xyz), end(xyz), begin(abc), begin(results), bit_and<int>());

    cout << "results:";
    for (const int& x : results)
        cout << ' ' << x;

    return 0;
}   