#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
using namespace std::chrono;
class BruteForce{
public:
    static void X(const string target) {
        string chars =
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789"
            "!@#$%^&*()-_=+[]{};:'\",.<>/?\\|`~";

        int length = target.length();
        string attempt(length, chars[0]); // "aaaaaaaaaaaaaaaaaaaa....."

        vector<int> counters(length, 0); // "00000000000000000000...." length=size and initialize all elements from 0
        int base = chars.size(); // size() measures how many elements it contains

        while (true) {
            // build the attempt from counters
            for (int i = 0; i < length; i++) {
                attempt[i] = chars[counters[i]];
            }

            // check match
            if (attempt == target) {
                cout << "Found the password: " << attempt << "\n";
                return;
            }

            // increment counters (base-N counter)
            int pos = length - 1;

            while (pos >= 0) {
                counters[pos]++;

                if (counters[pos] < base) break;   // no carry needed

                // carry
                counters[pos] = 0;  // reset this digit
                pos--;              // move left
            }

            // if pos < 0, full space was searched
            if (pos < 0) {
                cout << "Password not found.\n";
                return;
            }
        }
    }
};

int main() {
    string line;
    ifstream infile("Password.text");

    if (!infile.is_open()) {
        throw runtime_error("Failed to open file");
    }

    getline(infile, line, '\n');
    string target = line;
    
    auto start = high_resolution_clock::now();
    BruteForce::X(target);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);

    cout << duration.count() << "Second passed";
}
