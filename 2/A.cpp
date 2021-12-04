#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    fstream fin("input.txt");

    int depth = 0, horizontal = 0;
    while (fin.good())
    {
        string s;
        int x;
        fin >> s >> x;
        if (s == "forward")
            horizontal += x;
        else if (s == "up")
            depth -= x;
        else if (s == "down")
            depth += x;
    }
    cout << depth * horizontal << endl;
}