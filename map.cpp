#include <iostream>
#include <map>
using namespace std;

int main(){
map<int, string> students = {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}}; // keys: int, values: string

for(auto &p : students){
    cout << p.first << "=" << p.second << endl;
}

auto it = students.find(3);
if( it != students.end())
    cout << "Found " <<  it->second << " = " << it->first << endl;
else
    cout << "Not found" << endl;

return 0;
}