#include <iostream>
#include "Khazard.h"
using namespace std;
int main() {
    byte *a = new byte[8];
    a[0]='R';
    a[1]='u';
    a[2]='s';
    a[3]='l';
    a[4]='a';
    a[5]='n';
    a[6]='!';
    a[7]=' ';
    byte *key = new byte[16];
    key[0]='r';
    key[1]='r';
    key[2]='r';
    key[3]='r';
    key[4]='r';
    key[5]='r';
    key[6]='r';
    key[7]='r';
    key[8]='r';
    key[9]='r';
    key[10]='r';
    key[11]='r';
    key[12]='r';
    key[13]='r';
    key[14]='r';
    key[15]='r ';
    Khazard kh(key);
    cout<<Khazard::ConvertTo64(key);
    //cout<<kh.Substitution(kh.LinearMul(kh.LinearMul(kh.Substitution(kh.ConvertTo64(a)))));
    return 0;
}