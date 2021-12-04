#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    fstream fin("input.txt");

    int aim = 0, depth = 0, horizontal = 0;
    while (fin.good())
    {
        string s;
        int x;
        fin >> s >> x;
        if (s == "forward")
        {
            horizontal += x;
            depth += aim * x;
        }
        else if (s == "up")
            aim -= x;
        else if (s == "down")
            aim += x;
    }
    cout << depth * horizontal << endl;
}