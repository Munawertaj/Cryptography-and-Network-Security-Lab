#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll modExp(ll base, ll exp, ll mod)
{
    ll ans = 1;

    while(exp > 0)
    {
        if(exp & 1)
            ans = (ans * base) % mod;
        
        base = (base * base) % mod;
        exp /= 2;
    }

    return ans;
}

vector<int> divideIntoBlocks(string message, int blockSize)
{
    string block = "";
    vector<int> allBlocks;

    for(char ch : message)
    {
        block.push_back(ch);
        if(block.size() == blockSize)
        {
            int val = stoi(block);
            cout << block << endl;
            allBlocks.push_back(val);
            block = "";
        }
    }

    if(block.size())
        allBlocks.push_back(stoi(block));

    return allBlocks;
}

string mergeBlocks(vector<int> blocks) 
{
    string message = "";
    for(int val: blocks)
    {
        message += to_string(val);
    }

    return message;
}


vector<int> encryption(vector<int> &messageBlocks, int eKey, int n)
{
    vector<int> cipherBlocks;

    for(int val : messageBlocks)
    {
        int cipher = modExp(val, eKey, n);
        cipherBlocks.push_back(cipher);
    }

    return cipherBlocks;
}

vector<int> decryption(vector<int> &cipherBlocks, int dKey, int n)
{
    vector<int> decryptedBlocks;

    for(int val : cipherBlocks)
    {
        int decrypted = modExp(val, dKey, n);
        decryptedBlocks.push_back(decrypted);
    }

    return decryptedBlocks;
}



int main()
{
    freopen("input10.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string message;
    int eKey, dKey, n;

    getline(cin, message);

    cin >> eKey >> dKey >> n;

    int blockSize = to_string(n).size() - 1;

    cout << blockSize << endl;

    vector<int> messageBlocks, cipherBlocks, decryptedBlocks;
    
    messageBlocks = divideIntoBlocks(message, blockSize);

    cipherBlocks = encryption(messageBlocks, eKey, n);
    decryptedBlocks = decryption(cipherBlocks, dKey, n);


    string cipherText = mergeBlocks(cipherBlocks);
    string decryptedText = mergeBlocks(decryptedBlocks);

    cout << "Original  Text: " << message << endl;
    cout << "Encrypted Text: " << cipherText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

}