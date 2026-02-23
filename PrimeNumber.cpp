#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0 && n != 2) return false;

    int limit = sqrt(n);
    for (int c = 3; c <= limit; c += 2) {
        if (n % c == 0) return false;
    }
    return true;
}

int main() {
    int target = 1123;
    vector<int> primes;
    primes.reserve(target); // avoids reallocation

    int count = 0;
    int i = 2;

    while (count < target) {
        if (isPrime(i)) {
            primes.push_back(i);
            count++;
        }
        i++;
    }

    cout << target << ". Prime is: " << primes[target - 1] << endl;
    return 0;
}
