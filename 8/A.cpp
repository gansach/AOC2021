#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    fstream fin("input.txt");
    int ans = 0;
    while (fin.good())
    {
        string line;
        getline(fin, line);
        stringstream ss(line);
        int i = 0;
        while (ss.good())
        {
            string num;
            ss >> num;
            if (i > 10)
                if (num.size() == 2 || num.size() == 3 || num.size() == 4 || num.size() == 7)
                    ans++;
            i++;
        }
    }
    cout << ans << endl;
}