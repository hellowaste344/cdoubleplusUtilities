#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    map<int, string> ordered;
    unordered_map<int, string> unordered;

    ordered[2] = "Bob";
    ordered[1] = "Ashe";
    ordered[3] = "Jeff";

    unordered[2] = "Bob";
    unordered[1] = "Ashe";
    unordered[3] = "Jeff";

    cout << "Ordered map: " << endl;
    for(auto &p : ordered)
        cout << p.first << "=" << p.second << endl;
    
    cout << "\nUnordered map: " << endl;
    for(auto &p : unordered)
        cout << p.first << "=" << p.second << endl;

    return 0;
    }