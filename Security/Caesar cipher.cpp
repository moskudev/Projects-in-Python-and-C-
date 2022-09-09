#include <iostream>
#include <sstream>

using namespace std;
const string encrypt (const string plainText, int key){
    stringstream cipherStream;
    int x;
    for (auto &c : plainText) {
        x = c + key;
        if (c>= 'A' && c<= 'Z') {
            x = (x > 'z') ? ('A' + (x - 1) - 'Z') : x;
        }
        else if (c>= 'a' && c <= 'z') {
            x = (x > 'z') ? ('a' + (x - 1) - 'z') : x;
        }
        cipherStream << char(x);
    }
    return cipherStream.str();

}

const string decrypt (const string cipherText, int key) {
    stringstream plainStream;
    int x;
    for (auto &c : cipherText) {
        x = c - key;
        if (c >= 'A' && c <= 'Z') {
            x=  ( x  < 'A') ? ( 'Z' -('A'- (x + 1))) : x ;
        }
        else if ( c>= 'a' && c <= 'z') {
            x =  ( x  < 'a') ? ( 'z' - ('a' - (x + 1))) : x ;
        }
        plainStream << char(x);
    }
    return plainStream.str();
}

int main() {

    int choice, key;
    string plaintText, cipherText;

    cout << "Caesar Cipher\n"
        << "What would you like to do?\n"
        << "1. Encrypt a plain text\n"
        << "2. Decrypt a cipher text\n"
        << "Enter a choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter plain text: ";
            cin >> plaintText;
            cout << "Enter key ( 1 - 25): ";
            cin >> key;
            cipherText = encrypt(plaintText, key);
            cout << "Plain text: " <<plaintText
                 << " ---> " 
                 << "Cipher text: " << cipherText <<endl;
            break;

        case 2:
            cout << "Enter cipher text: ";
            cin >> cipherText;
            cout << "Enter key ( 1 - 25): ";
            cin >> key;
            plaintText = decrypt(cipherText, key);
            cout << "Cipher text: " << cipherText
                 << "-->"
                 << "Plain text: " << plaintText <<endl;
            break;
        
        default:
        cout << "Invalid choice\n";
            break;
        }

    return 0;

}