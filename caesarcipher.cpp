#include <iostream>
using namespace std;
string encrypt(string message, int key)
{
    string cipher = "";
    for (unsigned i = 0; i < message.length(); i++)
    {
        char c = message[i];
        // For upper case letters
        if (isupper(c))
        {
            int x = c - 'A' + key;
            x = x % 26;
            c = (char)(x + 'A');
        }
        // For lower case letters
        else if (islower(c))
        {
            int x = c - 'a' + key;
            x = x % 26;
            c = (char)(x + 'a');
        }
        cipher.insert(cipher.end(), 1, c);
    }
    return cipher;
}
string decrypt(string message, int key)
{
    string cipher = "";
    for (unsigned i = 0; i < message.length(); i++)
    {
        char c = message[i];
        // For upper case letters
        if (isupper(c))
        {
            int x = c - 'A' - key;
            if (x < 0)
            {
                x += 26;
            }
            c = (char)(x + 'A');
        }
        // For lower case letters
        else if (islower(c))
        {
            int x = c - 'a' - key;
            if (x < 0)
            {
                x += 26;
            }
            c = (char)(x + 'a');
        }
        cipher.insert(cipher.end(), 1, c);
    }
    return cipher;
}
int main()
{
    string message;
    int i, key, shift, choice;
    cout << "Enter message: ";
    getline(cin, message);
    cout << "Enter key: ";
    cin >> key;
    cout << "Choose shift (1. Right, 2. Left): ";
    cin >> shift;
    cout << "Enter your choice (1. Encryption, 2. Decryption): ";
    cin >> choice;
    if (choice == 1)
    {
        if (shift == 2)
        {
            cout << "Output: " << decrypt(message, key);
        }
        else if (shift == 1)
        {
            cout << "Output: " << encrypt(message, key);
        }
        else
        {
            cout << "Invalid!";
        }
    }
    else if (choice == 2)
    {
        if (shift == 1)
        {
            cout << "Output: " << decrypt(message, key);
        }
        else if (shift == 2)
        {
            cout << "Output: " << encrypt(message, key);
        }
        else
        {
            cout << "Invalid!";
        }
    }
    else
    {
        cout << "Invalid!";
    }
    return 0;
}
