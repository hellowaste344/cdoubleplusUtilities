#include <iostream>
#include <string>
#include <limits> // numeric_limits
using namespace std;

int main(){
    string line;
    string data;
    string num;
    cout << "Enter a random num:\n";
    cin >> num;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clean up the buffer until a newline character
    cout << "enter the line: ";
    getline(cin, line, ','); // stops reading at first comma
    cout << "First:" << line << endl;
    getline(cin, data);
    cout << "other datas: " << data << "\n";
    cin.clear(); // reset any error flags
    char c;
    c = cin.get(); // get one more char
    cout << "Char: " << c << endl;
}