#include <iostream>
#include <vector>
using namespace std;
auto multiply = [](auto a, auto b){ // lambda easiest
        return a * b;
    };
int main(){
    auto x = 10;
    auto y = 3.14;
    auto name = "Ashe";
    vector<int> nums = {1,2,3};

    nums.push_back(x);
    nums.push_back(y);

    for(auto& n : nums){
        cout << n << "\n";
    }
    cout << nums.size() << endl;
    cout << multiply(x, y);
}