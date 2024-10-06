#include <bits/stdc++.h>
using namespace std;

bool isAlphabet(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return true;
    else if (ch >= 'A' && ch <= 'Z')
        return true;
    else
        return false;
}

char convertToCypher(char ch)
{
    ch += 3;
    if (!isAlphabet(ch))
        ch -= 26;

    return ch;
}

char convertToPlain(char ch)
{
    ch -= 3;
    if (!isAlphabet(ch))
        ch += 26;

    return ch;
}

string plainTextToCypherText(string text)
{
    string res = "";

    for (int i = 0; i < text.size(); ++i)
    {
        if (isAlphabet(text[i]))
            text[i] = convertToCypher(text[i]);

        res.push_back(text[i]);
    }

    return res;
}

string cypherTextToPlainText(string text)
{
    string res = "";

    for (int i = 0; i < text.size(); ++i)
    {
        if (isAlphabet(text[i]))
            text[i] = convertToPlain(text[i]);

        res.push_back(text[i]);
    }

    return res;
}

int main()
{
    string plainText;
    cin >> plainText;

    string cypher = plainTextToCypherText(plainText);
    string plain = cypherTextToPlainText(cypher);

    cout << cypher << endl << plain;
}