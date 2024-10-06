#include <bits/stdc++.h>

using namespace std;

string plainTextToCypher(string &text, map<string, string> &dictionary)
{
    string check = "", convertedText = "";

    for (int i = 0; i < text.size(); ++i)
    {
        check += text[i];

        if (dictionary.find(check) != dictionary.end())
        {
            convertedText += (dictionary[check]);
            check = "";
        }    
    }

    return convertedText;
}

string cypherTextToPlain(string &text, map<string, string> &dictionary)
{
    string check = "", convertedText = "";

    for (int i = 0; i < text.size(); ++i)
    {
        check += text[i];

        if (dictionary.find(check) != dictionary.end())
        {
            convertedText += (dictionary[check]);
            check = "";
        }    
    }
    
    return convertedText;
}

int main()
{
    freopen("input2.txt", "r", stdin);

    map<string, string> dictionary, revDictionary;

    string key, value;
    while (cin >> key >> value)
    {
        dictionary[key] = value;
        revDictionary[value] = key;
        cout << key << " " << value << endl;
    }

    string plainText = "ABCDEFXYZ";

    string cypherText = plainTextToCypher(plainText, dictionary);
    string originalText = cypherTextToPlain(cypherText, revDictionary);

    cout << cypherText << endl;
    cout << originalText << endl;
}