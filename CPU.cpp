#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;


void cpu_work(){
    double sum = 0;
    for(long long i = 0; i < 1e12; i += 1){
            double k = pow(k, i);
    }
}

int main(){
    auto start = chrono::high_resolution_clock::now();

    cpu_work();

    auto end = chrono::high_resolution_clock::now();
    auto duration_ms = chrono::duration_cast<chrono::seconds>(end - start).count();

    cout << "CPU time: " << duration_ms << "\n";
}
