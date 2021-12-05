#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n = INT_MIN, m = INT_MIN;

    vector<vector<int>> lines;

    fstream fin("input.txt");
    while (fin.good())
    {
        string s;
        getline(fin, s);

        int x1, y1, x2, y2;
        sscanf(s.c_str(), "%d,%d -> %d,%d", &x1, &y1, &x2, &y2);

        n = max({n, x1 + 1, x2 + 1});
        m = max({n, y1 + 1, y2 + 1});

        lines.push_back({x1, y1, x2, y2});
    }

    vector<vector<int>> floor(n, vector<int>(m, 0));

    for (auto line : lines)
    {
        int x1 = line[0], y1 = line[1], x2 = line[2], y2 = line[3];

        if (x1 == x2)
        {
            if (y1 > y2)
                swap(y1, y2);
            for (int i = y1; i <= y2; i++)
                floor[i][x1]++;
        }
        else if (y1 == y2)
        {
            if (x1 > x2)
                swap(x1, x2);
            for (int i = x1; i <= x2; i++)
                floor[y1][i]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (floor[i][j] >= 2)
                ans++;
    cout << ans << endl;
}