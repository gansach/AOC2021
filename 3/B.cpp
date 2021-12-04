#include <bits/stdc++.h>

using namespace std;

int bin2dec(string &b)
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

int main(void)
{
    fstream fin("input.txt");

    vector<string> bins;
    while (fin.good())
    {
        string b;
        fin >> b;
        bins.push_back(b);
    }

    vector<string> oxygen(bins.begin(), bins.end());
    for (int i = 0; i < bins[0].size(); i++)
    {
        int ones = 0, zeros = 0;
        for (auto b : oxygen)
            b[i] == '1' ? ones++ : zeros++;

        vector<string> tmp;
        char c = (zeros > ones) ? '0' : '1';

        for (auto b : oxygen)
            if (b[i] == c)
                tmp.push_back(b);

        oxygen = tmp;
    }

    vector<string> carbon(bins.begin(), bins.end());
    for (int i = 0; i < bins[0].size(); i++)
    {
        int ones = 0, zeros = 0;
        for (auto b : carbon)
            b[i] == '1' ? ones++ : zeros++;

        vector<string> tmp;
        char c = (ones < zeros) ? '1' : '0';

        for (auto b : carbon)
            if (b[i] == c)
                tmp.push_back(b);

        carbon = tmp;
        if (carbon.size() == 1)
            break;
    }

    cout << bin2dec(oxygen.front()) * bin2dec(carbon.front()) << endl;
}