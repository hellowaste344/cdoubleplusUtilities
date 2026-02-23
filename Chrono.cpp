#include <iostream>
#include <chrono>
#include <vector>
using namespace std;


int main(){
    const int N = 10000000;
    vector<int> arr(N);
    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i < N; i += 1){
        arr[i] = i;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << duration.count() << " milliseconds\n";
}
