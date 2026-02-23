// to convert decimal to hexadecimal divide 16 constantly
// to convert decimal to octal divide 8 constantly
/*
| Base | Name        | Digits   | Example Use           |
| ---- | ----------- | -------- | --------------------- |
| 10   | Decimal     | 0–9      | Humans                |
| 16   | Hexadecimal | 0–9, A–F | Memory, colors, bytes |
| 8    | Octal       | 0–7      | Linux permissions     |
*/
#include <iostream>
using namespace std;

int main(){
    int decimal = 100;
    std::cout << "Hexadecimal: " << std::hex << decimal << " Octal: " << std::oct << decimal;
}