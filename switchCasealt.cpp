#include <iostream>
#include <string>
#include <ranges>//all(), transform(), filter()
#include <map>
#include <cctype>//toupper(), tolower()
using namespace std;
using std::tolower;

string getCaffeine(string& type) { 
    // & = pass by reference 
    // don't create a coppy

    for(char &c : type){
        c = tolower(static_cast<unsigned char>(c));
    }

    map<string, string> caffeineMap = {
        {"coffe", "95mg"},
        {"redbull", "147mg"},
        {"tea", "11mg"},
        {"soda", "21mg"}
    };

    auto it = caffeineMap.find(type);

    if(it != caffeineMap.end()){
        return it->second;
    } else {
            return "Not found";
        }
}
int main(){
    string Drink;
    cout << "Enter the name: ";
    getline(cin, Drink, '\n');
    string result = getCaffeine(Drink);
    cout << Drink << " contains " << result << " caffein" << endl;
    return 0;
}