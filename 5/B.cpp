#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int>> bresenhamsLineGeneration(int x1, int y1, int x2, int y2)
{
    vector<tuple<int, int>> line;

    bool isSteep = (abs(y2 - y1) > abs(x2 - x1));
    if (isSteep)
    {
        swap(x1, y1);
        swap(x2, y2);
    }

    if (x1 > x2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }

    int deltaX = x2 - x1;
    int deltaY = abs(y2 - y1);
    int error = int(deltaX / 2);

    int y = y1;
    int ystep = (y1 < y2) ? 1 : -1;

    for (int x = x1; x < x2 + 1; ++x)
    {
        if (isSteep)
            line.push_back({y, x});
        else
            line.push_back({x, y});

        error -= deltaY;
        if (error < 0)
        {
            y += ystep;
            error += deltaX;
        }
    }

    return line;
}

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

        auto points = bresenhamsLineGeneration(x1, y1, x2, y2);
        for (auto point : points)
            floor[get<0>(point)][get<1>(point)]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (floor[i][j] >= 2)
                ans++;

    cout << ans << endl;
}