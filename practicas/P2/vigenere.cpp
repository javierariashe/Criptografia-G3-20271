#include <iostream>
#include <string>
using namespace std;

bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string vigenere(string s, string k, bool cifrar) {
    int n = (int)s.size();
    int m = (int)k.size();
    int j = 0;
    
    for(int i = 0; i < n; i++) {

        if(s[i] == ' ') continue;

        if(!is_letter(s[i])) {
            cout << "Inválido. Solo letras.\n";
            return "";
        }
        
        int offset = k[j%m] <= 'Z' ? k[j%m] - 'A' : k[j%m] - 'a';

        if(!cifrar) offset = -offset;
        
        if(s[i] <= 'Z') s[i] = 'A' + ((s[i] - 'A') + offset + 26) % 26;
        else s[i] = 'a' + ((s[i] - 'a') + offset + 26) % 26;
        j++;
    }

    return s;
}
 
int main() {
    string s, k;

    cout << "Ingresa un texto compuesto sólo por letras mayúsculas y minúsculas.\n";
    getline(cin, s);
    cout << "Ingresa la clave k, una palabara compuesta por letras.\n";
    cin >> k;
    
    for (char c : k) {
        if (!is_letter(c)) {
            cout << "Clave inválida\n";
            return 0;
        }
    }
    
    string s_cifrada = vigenere(s, k, 1);
    string s_descifrada = vigenere(s_cifrada, k, 0);

    if(s_cifrada != "" && s_descifrada != "") {
        cout << "Cifrado: " << s_cifrada << "\n";
        cout << "Descifrado: " << s_descifrada << "\n";
    }
}
