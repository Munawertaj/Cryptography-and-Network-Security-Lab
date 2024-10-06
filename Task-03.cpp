#include <bits/stdc++.h>
using namespace std;


// Function to convert plain text to cipher text using columnar transposition
string plainTextToCypherText(const string& text, int col)
{
    int total = text.size();
    string res = ""; 

    // Read characters column by column
    for (int i = 0; i < col; i++)
    {
        int index = i;
        while (index < total)
        {
            res.push_back(text[index]);
            index += col;
        }
    }

    return res;
}

// Convert cipher text back to plain text
string cypherTextToPlainText(string text, int col)
{
    string res = "";

    int total = text.size();
    int row = total / col;
    int extra = total % col;

    // Reconstruct plain text from cipher text without extra 
    for(int r = 0; r < row; r++)
    {
        int index = r;
        int temp = extra;

        while(index < total)
        {
            res.push_back(text[index]);
            index += row;

            if(temp > 0)
            {
                index++;
                temp--;
            }
        }
    }

    // Adding last row's extra characters if exists
    int index = row;
    while(extra > 0) 
    {
        res.push_back(text[index]);
        index += (row + 1);
        extra--;
    }

    return res;
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