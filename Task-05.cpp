#include<bits/stdc++.h>
using namespace std;

map<char, int> mp1;
map<int, char> mp2;

void puttingValues()
{
    int count = 0;

    for(char ch = 'A'; ch <= 'Z'; ch++)
    {
        mp1[ch] = count;
        mp1[ch + 32] = count + 26;

        mp2[count] = ch;
        mp2[count+26] = ch + 32;

        count++;
    }

    // for(auto pr : mp1)
    // {
    //     cout << pr.first << "->" << pr.second << endl;
    // }
}

bool isAlphabet(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return true;
    else if (ch >= 'A' && ch <= 'Z')
        return true;
    else
        return false;
}

string encryption(string &message, string &pad)
{
    string encryptedText;
    for(int i = 0; i < message.size(); ++i) 
    {
        if(!isAlphabet(message[i]))
        {
            encryptedText.push_back(message[i]);
            continue;
        }

        int val = (mp1[message[i]] + mp1[pad[i]]) % 52;
        char ch = mp2[val];
        encryptedText.push_back(ch);
    }

    return encryptedText;
}

string decryption(string &message, string &pad)
{
    string decryptedText;

    for(int i = 0; i < message.size(); ++i)
    {
        if(!isAlphabet(message[i]))
        {
            decryptedText.push_back(message[i]);
            continue;
        }
        
        int val = mp1[message[i]] - mp1[pad[i]];

        if(val < 0)
            val += 52;

        decryptedText.push_back(mp2[val]);
    }

    return decryptedText;
}


int main()
{
    freopen("input5.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string message , pad;

    getline(cin, message);
    getline(cin, pad);

    cout << message << endl << pad << endl;

    puttingValues();
    
    string cipherText = encryption(message, pad);
    string plainText = decryption(cipherText, pad);

    cout << cipherText << endl << plainText << endl;

}