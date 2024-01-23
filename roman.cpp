#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

// This function returns value of a Roman symbol
int romanToDecimal(string romanNumeral)
{
    map<char, int> rm;
    rm.insert({'I', 1});
    rm.insert({'V', 5});
    rm.insert({'X', 10});
    rm.insert({'L', 50});
    rm.insert({'C', 100});
    rm.insert({'D', 500});
    rm.insert({'M', 1000});
    int sum = 0;
    for (int i = 0; i < romanNumeral.length(); i++)
    {
        if (rm[romanNumeral[i]] < rm[romanNumeral[i + 1]])
        {
            sum += rm[romanNumeral[i + 1]] - rm[romanNumeral[i]];
            i++;
            continue;
        }
        sum += rm[romanNumeral[i]];
    }
    return sum;
}

// Driver Code
int main()
{
    string romanNumeral;
    cout << "Enter roman numeral: ";
    getline(cin, romanNumeral);
    cout << "The integer form of Roman Numeral " << romanNumeral << " is " << romanToDecimal(romanNumeral) << endl;
    // For easy checking:
    // string romanNumeral1;
    // romanNumeral1 = "MCMXCIX";
    // cout << "The integer form of Roman Numeral " << romanNumeral1 << " is " <<
    romanToDecimal(romanNumeral1) << endl;
    return 0;
}
