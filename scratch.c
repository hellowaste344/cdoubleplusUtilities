#include <stdio.h>
#include <stdlib.h>

char output[51] = "apijaczhzgtfnyjgrdvqrjbmcurcmjczsvbwgdelvxxxjkyigy";
char input[51];
int i_1;
int uVar1;
int iVar2;
int i = 0;

int main(){
    for (; i < 3; i = i + 1) {
    for (i_1 = 0; i_1 < 51; i_1 = i_1 + 1) {
      uVar1 = (i_1 % 0xff >> 1 & 0x55U) + (i_1 % 0xff & 0x55U);
      uVar1 = ((int)uVar1 >> 2 & 0x33U) + (uVar1 & 0x33);
      iVar2 = ((int)uVar1 >> 4) + input[i_1] + -0x61 + (uVar1 & 0xf);
      input[i_1] = (char)iVar2 + (char)(iVar2 / 0x1a) * -0x1a + 'a';
    }
  }
  printf(input);
}