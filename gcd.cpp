#include <iostream>
#include <sstream>
using namespace std; 

// Function to return gcd of a and b
int gcd(int a, int b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

// A simple method to evaluate Euler Totient Function 
int etf(int n) { 
    int result = 1; 
    for (int i = 2; i < n; i++) 
        if (gcd(i, n) == 1) 
            result++; 
    return result; 
} 

// Driver Code
int main(int argc, char* argv[]) { 
    int n = stoi(argv[1]);
    cout << etf(n);
    return 0; 
}
