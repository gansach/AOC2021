#include <bits/stdc++.h>

using namespace std;

bool isSafe(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int main(void)
{
    fstream fin("input.txt");

    vector<vector<int>> matrix;
    while (fin.good())
    {
        matrix.push_back(vector<int>());
        string line;
        getline(fin, line);
        for (auto c : line)
            matrix.back().push_back(c - '0');
    }

    int n = matrix.size();
    int m = matrix[0].size();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool low_point = true;
            for (int d = 0; d < 4; d++)
            {
                int ii = i + dx[d];
                int jj = j + dy[d];
                if (isSafe(ii, jj, n, m) && matrix[i][j] >= matrix[ii][jj])
                    low_point = false;
            }
            if (low_point)
                ans += matrix[i][j] + 1;
        }
    }
    cout << ans << endl;
}