#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream outFile("Data.text"); // write mode
    if(outFile.is_open()){
        outFile << "C++ code, " << endl;
        outFile << 99 << endl;
        outFile.close();
    }

    ifstream inFile("Data.text"); // read mode
    if(inFile.is_open()){
        string line;
        while(getline(inFile, line)){
            cout << line << endl;
        }
        inFile.close();
    }
    return 0;
}