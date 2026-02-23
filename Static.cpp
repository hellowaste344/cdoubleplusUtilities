#include <iostream>
#include <string> // otherwise logger<string>::L("hello world!");
using namespace std;

class logger{
public:
    static void L(const string& msg){ // reads not modifies and references msg itself not creates a coppy
        cout << "Message: " << msg << endl;
    }
};

int main(){
    logger::L("hello world!");
}