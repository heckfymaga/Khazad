#include <iostream>
#include "Khazard.h"
using namespace std;
int main() {
    byte *a = new byte[8];
    a[0]='r';
    a[1]='u';
    a[2]='s';
    a[3]='l';
    a[4]='a';
    a[5]='n';
    a[6]='t';
    a[7]='h';
    byte *key = new byte[16];
    key[0]='r';
    key[1]='u';
    key[2]='s';
    key[3]='l';
    key[4]='a';
    key[5]='n';
    key[6]='t';
    key[7]='h';
    key[8]='e';
    key[9]='m';
    key[10]='o';
    key[11]='s';
    key[12]='t';
    key[13]='b';
    key[14]='r';
    key[15]='a';
    Khazard kh(key);
    cout << kh.ConvertTo64(a)<< endl;
    //cout<<kh.LinearMul(((kh.LinearMul(kh.ConvertTo64(a)))));
    cout<<kh.Decrypt(kh.Encrypt(kh.ConvertTo64(a)));
    /*uint64_t test = 0;
    test = (Khazard::LinearMul((3192261698671091793 ^ Khazard::ConvertTo64(a))));
    cout << test <<endl;
    test = Khazard::LinearMul(3192261698671091793) ^ Khazard::LinearMul(Khazard::ConvertTo64(a));
    cout << test;*/
    return 0;
}