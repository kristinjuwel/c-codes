#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
string modif(string input, int len)
{
    int i = 0, j;
    // for removing non-alpanumeric characters
    for (string::iterator i = input.begin(); i != input.end(); i++)
    {
        if (!isalnum(input.at(i - input.begin())))
        {
            input.erase(i);
            i--;
        }
    }
    // for removing spaces
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    // for ignoring case
    for (int i = 0; i < input.length(); i++)
    {
        input[i] = tolower(input[i]);
    }
    return input;
}

int isPalindrome(int len, string input)
{
    string check;
    int i, j, flag = 1;
    if (len < 2)
    {
        cout << input << " is a palindrome.";
    }
    // find the string length
    for (i = 0; input[i] != '\0'; i++)
        ;
    // copy the string in reverse order
    for (i--, j = 0; i >= 0; i--, j++)
    {
        check[j] = (input[i]);
        input[i] = (check[j]);
    }
    check[j] = '\0';
    // string comparison
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != check[i])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string input;
    cout << "Enter string: ";
    getline(cin, input);
    int len = input.size();
    // modifying string to ignore case, spaces and non-alphanumeric characters
    string input1 = modif(input, len);
    // calling of function to see if input word is a palindrome
    if (isPalindrome(len, input1))
    {
        cout << input << " is a palindrome.";
    }
    else
    {
        cout << input << " is not a palindrome.";
    }
    return 0;
}
