#include <bits/stdc++.h>

using namespace std;

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

    int gamma = 0, epsilon = 0;
    for (int i = 0; i < bins[0].size(); i++)
    {
        int ones = 0, zeros = 0;
        for (auto b : bins)
            b[i] == '1' ? ones++ : zeros++;

        gamma <<= 1;
        epsilon <<= 1;

        if (ones > zeros)
            gamma++;
        else
            epsilon++;
    }
    cout << gamma * epsilon << endl;
}