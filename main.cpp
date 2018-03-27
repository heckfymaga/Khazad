#include <iostream>
#include "Khazard.h"
using namespace std;
const int CHUNK = 8;
int REMAIN;
byte* to_byte_array(string a){
    auto *result = new byte[a.length()];
    for(int i = 0; i < a.length(); i++){
        result[i] = (byte)a[i];
    }
    return result;
}
string* get_byte_blocks(string text){
    size_t size;
    if(text.length()%CHUNK == 0){
        size = text.length()/CHUNK;
    }
    else{
        size = text.length() + 1;
    }
    auto * result = new string[size];
    int j = -1;
    for(int i = 0; i < text.length(); i++){
        if(i%8 == 0){
            j++;
        }
        result[j] += text[i];
    }
    REMAIN = CHUNK - result[j].length();
    for(int i = 0; i < REMAIN; i++){
        result[j] += 'Q';
    }
    return result;
}
string block_to_string(uint64_t chunk){
    string result;
    bool check = true;
    uint8_t get_byte;
    for(int i = 0; i < 8; i++){
        get_byte = uint8_t((chunk >> (8*(CHUNK - i - 1))));
        if(get_byte == 0 && check)
            continue;
        check = false;
        result += char(get_byte);
    }
    return result;
}
int main() {
    string text;
    cout << "Type text you want to encrypt"<<endl;
    getline(cin,text);

    size_t size;
    if(text.length()%CHUNK == 0){
        size = text.length()/CHUNK;
    }
    else{
        size = text.length()/CHUNK + 1;
    }

    string* blocks = get_byte_blocks(text);
    string key = "asdzxcvfgbnhmjkl";
    Khazard cipher(to_byte_array(key));

    string encrypt_text;
    string decrypt_text;
    for(int i = 0; i < size; i++){
        encrypt_text += block_to_string(cipher.Encrypt(Khazard::ConvertTo64(to_byte_array(blocks[i]))));
    }
    for(int i = 0; i < size; i++){
        decrypt_text += block_to_string(cipher.Decrypt(cipher.Encrypt(Khazard::ConvertTo64(to_byte_array(blocks[i])))));
    }
    decrypt_text.erase(decrypt_text.length()-REMAIN, REMAIN);
    cout<<"Encrypted text is - "<<encrypt_text<<endl;
    cout<<"Decrypted text is - "<<decrypt_text;
    return 0;
}