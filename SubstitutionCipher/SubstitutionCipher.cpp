

#include <iostream>
#include <string>

using namespace std;

string encrypt(string message) {
    string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
    string key{ "XFQNMLKJHGlkjwzsedcTYUIOPDCVBxfqgavbnGAWZSEmhgtyuiop1029384756" };
    string encrypted_message{};

    /*
    * 1. take the message, break it up to each letters
    * 2. match it with alphabet and get its index 
    * 3. substitute the letter with the character of corresponding index in key
    */

    int index{};

    for (int i = 0; i < message.length(); i++) {
        if (isalnum(message[i])) {
            index = alphabet.find(message[i]);
            encrypted_message += key[index];
        }
        else {
            encrypted_message += message[i];
        }
    }

    return encrypted_message;
}

// used to test if encryption is actually working by going backwards
string decrypt(string encrypted_message) {
    string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" };
    string key{ "XFQNMLKJHGlkjwzsedcTYUIOPDCVBxfqgavbnGAWZSEmhgtyuiop1029384756" };
    string decrypted_message{};

    int index{};

    for (int i = 0; i < encrypted_message.length(); i++) {
        if (isalnum(encrypted_message[i])) {
            index = key.find(encrypted_message[i]);
            decrypted_message += alphabet[index];
        }       
        else {
            decrypted_message += encrypted_message[i];
        }
    }

    return decrypted_message;
}
int main()
{
    string message{};
    cout << "Please enter a message" << endl;
    getline(cin, message);
    cout << "the encrypted message is: ";
    cout << encrypt(message) + "\n" << endl;
    cout << "the encrypted message is: " << decrypt(encrypt(message)) << endl;
    
}


