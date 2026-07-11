#include <iostream>
#include <array>
using namespace std;

int enc[11];

void decodePassword(char *out){
    enc[0] = 0xf9;
    enc[1] = 0xdf;
    enc[2] = 0xda;
    enc[3] = 0xcf;
    enc[4] = 0xd8;
    enc[5] = 0xf9;
    enc[6] = 0xcf;
    enc[7] = 0xc9;
    enc[8] = 0xdf;
    enc[9] = 0xd8;
    enc[10] = 0xcf;

    for (int i=0; i < 0xb; i++){
        out[i] = enc[i] ^ 0xaa;
    }
    out[0xb] = '\0';
}

int main(){
    char password[128];
    decodePassword(password);
    for (int i=0; i < 0xb; i++){
        cout << password[i];
    }
}
