#include <bits/stdc++.h>
using namespace std;


string plainTextToCypherText(string &message, int col)
{
    int total = message.size();
    
    string cipher = "";

    for(int i = 0; i < col; ++i)
    {
        int index = i;
        while(index < total)
        {
            cipher.push_back(message[index]);
            index += col;
        }
    }

    return cipher;
}

string cypherTextToPlainText(string &message, int col)
{
    int total = message.size();
    int row = total / col;
    int extra = total % extra;

    string decript = "";

    for(int r = 0; r < row; ++r)
    {
        int index = r;
        int temp = extra;

        while(index < total)
        {
            decript.push_back(message[index]);
            index += (temp > 0 ? row + 1 : row);
            temp--;
        }
    }

    int index = row;
    while(extra > 0)
    {
        decript.push_back(message[index]);
        index += row + 1;
        extra--;
    }

    return decript;
}



int main()
{
    string plainText;
    int width;

    // plainText = "Department Of Computer Science And Engineering";
    // width = 10;
    
    cin >> plainText;
    cin >> width;

    string cypher = plainTextToCypherText(plainText, width);
    string plain = cypherTextToPlainText(cypher, width);

    cout << cypher << endl;
    cout << plain << endl;
}