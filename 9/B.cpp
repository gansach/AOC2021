#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isSafe(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int explore(int i, int j, vector<vector<int>> &matrix, vector<vector<bool>> &visited, int parent)
{
    int n = matrix.size();
    int m = matrix[0].size();

    if (!isSafe(i, j, n, m))
        return 0;

    if (matrix[i][j] <= parent)
        return 0;

    if (visited[i][j] || matrix[i][j] == 9)
        return 0;

    visited[i][j] = true;

    int size = 1;
    for (int d = 0; d < 4; d++)
        size += explore(i + dx[d], j + dy[d], matrix, visited, matrix[i][j]);
    return size;
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

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    vector<int> basins;

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
            if (low_point && !visited[i][j])
                basins.push_back(explore(i, j, matrix, visited, -1));
        }
    }
    sort(basins.begin(), basins.end(), greater<int>());
    cout << basins[0] * basins[1] * basins[2] << endl;
}