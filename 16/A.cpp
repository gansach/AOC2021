#include <bits/stdc++.h>

using namespace std;

map<char, string>
    hex2bin({{'0', "0000"},
             {'1', "0001"},
             {'2', "0010"},
             {'3', "0011"},
             {'4', "0100"},
             {'5', "0101"},
             {'6', "0110"},
             {'7', "0111"},
             {'8', "1000"},
             {'9', "1001"},
             {'A', "1010"},
             {'B', "1011"},
             {'C', "1100"},
             {'D', "1101"},
             {'E', "1110"},
             {'F', "1111"}});

int bin2dec(string b)
{
    int n = 0;
    for (auto c : b)
    {
        n <<= 1;
        if (c == '1')
            n++;
    }
    return n;
}

string extractBits(string &s, int n)
{
    string t = s.substr(0, n);
    s = s.substr(n);
    return t;
}

void processPacket(string bin, int &versionSum)
{
    while (!bin.empty() && bin2dec(bin) != 0)
    {
        versionSum += bin2dec(extractBits(bin, 3));

        int packetTypeID = bin2dec(extractBits(bin, 3));

        // Literal
        if (packetTypeID == 4)
        {

            string literal = extractBits(bin, 5);
            while (literal.at(0) != '0')
                literal = extractBits(bin, 5);
        }
        // Operator
        else
        {
            int lengthTypeID = bin2dec(extractBits(bin, 1));
            bin2dec(extractBits(bin, lengthTypeID == 0 ? 15 : 11));
        }
    }
}

int main(void)
{
    fstream fin("input.txt");
    string hex;
    getline(fin, hex);

    string bin;
    for (auto c : hex)
        bin += hex2bin[c];

    while (bin.size() % 4 != 0)
        bin.push_back('0');

    int versionSum = 0;
    processPacket(bin, versionSum);
    cout << versionSum << endl;
}