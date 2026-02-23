#include <bits/stdc++.h> //imports all headers
// #include <algorithm>
using namespace std;

void shuffle_array(int arr[], int n)
{
    random_device rd; // true random seed
    mt19937 gen(rd()); // Mersenne Twister

    // shuffling array
    shuffle(arr, arr+n, gen);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    // searching algorithms
    vector<int> v = {4,1,3,6,2,9};
    auto it = find(v.begin(), v.end(), 2);
    if (it != v.end()){
        cout << distance(v.begin(), it) << endl;
    }
    else
        cout << "Not Present" << endl;

    vector<int>::iterator odd = v.begin();

    odd = find_if(v.begin(), v.end(), [](int x){return x % 2;});
    cout << "The first odd is " << *odd << '\n';
    
    odd = find_if_not(v.begin(), v.end(), [](int x){return x % 2;});
    cout << "The first non-odd(or even) value is " << *odd << endl;
    

    
    vector<int> arr = {1,2,5,9,6,4,2,1,6,3,4,5};
    
    // manupilation algorithms
    shuffle_array(arr.data(), arr.size());
    
    vector<int> v1 = {1,5,6,8};
    vector<int> v2(v1.size()); // {0,0,0,0}
    // tranform(first, last, res, op1) for unary operation
    // transform(first, last, first1, res, op2) for binary operation
    transform(v1.begin(), v1.end(), v2.begin(), [](int a ){return a+1;});
    for (auto i : v2)
        cout << i << " ";
    cout << endl;

    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {5,4,3,2,1};
    vector<int> arr3(arr1.size());

    transform(arr1.begin(), 
              arr1.end(), 
              arr2.begin(), 
              arr3.begin(),
              [](int a, int b){return a + b;});
    for (auto i : arr3)
        cout << i << " ";
    cout << endl;

    // & capture by reference
    // = capture by value
    string s = "PLAYTOWIN";
    transform(s.begin(),
              s.end(), 
              s.begin(), 
              [](char c){return static_cast<char>(tolower(static_cast<unsigned char>(c)));});
    cout << s << endl;

    // counting & comparing algorithms
    cout << count(arr.begin(), arr.end(), 2) << endl; // count(first, last, val)

    vector<string> st = {"hi", "music", "play", "sound", "hi"};
    cout << count(st.begin(), st.end(), "hi");

    return 0;
}