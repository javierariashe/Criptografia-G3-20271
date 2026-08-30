#include <iostream>
#include <string>
using namespace std;

bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string cifrar(string s, int k) {
    k = (k % 26 + 26) % 26;
    
    for (char &c : s) {
        if (c == ' ') continue;

        if (!is_letter(c)) {
            cout << "Inválido. Solo letras.\n";
            return "";
        }

        if(c <= 'Z') c =  'A' + (c - 'A' + k) % 26; //Mayúsculas
        else  c =  'a' + (c - 'a' + k) % 26;  //Minúsculas 
    }

    return s;
}

string descifrar(string s, int k) {
    return cifrar(s, -k);
}
 
int main() {
    string s;
    int k;

    cout << "Ingresa un texto compuesto sólo por letras mayúsculas y minúsculas.\n";
    getline(cin, s);
    cout << "Ingresa la clave k, un número entero positivo.\n";
    cin >> k;
    
    string s_cifrada = cifrar(s, k);
    string s_descifrada = descifrar(s_cifrada, k);

    if(s_cifrada != "" && s_descifrada != "") {
        cout << "Cifrado: " << s_cifrada << "\n";
        cout << "Descifrado: " << s_descifrada << "\n";
    }
}
