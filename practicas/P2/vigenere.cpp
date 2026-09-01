#include <iostream>
#include <string>
using namespace std;

bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string cifrar(string s, string k) {
    int n = (int)s.size();
    int m = (int)k.size();
    
    for(int i = 0; i < n; i++) {

        if(s[i] == ' ') continue;

        if(!is_letter(s[i])) {
            cout << "Inválido. Solo letras.\n";
            return "";
        }
        
        int offset = k[i%m] <= 'Z' ? k[i%m] - 'A' : k[i%m] - 'a';
        
        if(s[i] <= 'Z') s[i] = 'A' + ((s[i] - 'A') + offset) % 26;
        else s[i] = 'a' + ((s[i] - 'a') + offset) % 26;
    }

    return s;
}

string descifrar(string s, string k) {
    int n = (int)s.size();
    int m = (int)k.size();
    
    for(int i = 0; i < n; i++) {
        
        if(s[i] == ' ') continue;
        
        if(!is_letter(s[i])) {
            cout << "Inválido. Solo letras.\n";
            return "";
        }

        int offset = k[i%m] <= 'Z' ? k[i%m] - 'A' : k[i%m] - 'a';
        
        if(s[i] <= 'Z') s[i] = 'A' + ((s[i] - 'A') - offset + 26) % 26;
        else s[i] = 'a' + ((s[i] - 'a') - offset + 26) % 26;
    }

    return s;
}
 
int main() {
    string s, k;

    cout << "Ingresa un texto compuesto sólo por letras mayúsculas y minúsculas.\n";
    getline(cin, s);
    cout << "Ingresa la clave k, una palabara compuesta por letras.\n";
    cin >> k;
    
    string s_cifrada = cifrar(s, k);
    string s_descifrada = descifrar(s_cifrada, k);

    if(s_cifrada != "" && s_descifrada != "") {
        cout << "Cifrado: " << s_cifrada << "\n";
        cout << "Descifrado: " << s_descifrada << "\n";
    }
}
