#include <iostream>
#include <ranges> //std::ranges::transform C++20
#include <vector>
#include <algorithm> //std::transform C++98
#include <string>
#include <cctype>

int main(){
    std::vector<int> nums = {1,2,3,4,5};
    auto even_nums = nums 
    // assume values are not references don't use "&" with adaptors
    | std::views::filter([](int n){return n % 2 == 0;})
    | std::views::transform([](int n){return n * n;});

    for (auto num : even_nums){
        std::cout << num << " ";
    }

    std::vector<std::string> words = {"hello", "world", "c++", "ranges"};
    // ranges::transform(obj, obj.begin(), lambda)
    std::ranges::transform(words, 
        words.begin(), [](std::string s){
            std::transform(s.begin(), s.end(), s.begin(),
                                [](unsigned char c){
                                    return std::toupper(c);
                                });
            return s;
    });
    for (auto word : words){
        std::cout << word << " "; 
    }
}