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
        string line;
        getline(fin, line);

        matrix.push_back(vector<int>());
        for (auto c : line)
            matrix.back().push_back(c - '0');
    }

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> matrix5x5(5 * n, vector<int>(5 * m, 0));

    for (int i = 0; i < 5 * n; i++)
    {
        for (int j = 0; j < 5 * m; j++)
        {
            if (isSafe(i, j, n, m))
                matrix5x5[i][j] = matrix[i][j];
            else if (isSafe(i - n, j, 5 * n, 5 * m))
                matrix5x5[i][j] = matrix5x5[i - n][j] != 9 ? matrix5x5[i - n][j] + 1 : 1;
            else if (isSafe(i, j - m, 5 * n, 5 * m))
                matrix5x5[i][j] = matrix5x5[i][j - m] != 9 ? matrix5x5[i][j - m] + 1 : 1;
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    vector<vector<bool>> visited(5 * n, vector<bool>(5 * m, false));
    visited[0][0] = true;

    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 0, 0});

    while (!pq.empty())
    {
        int risk = get<0>(pq.top());
        int i = get<1>(pq.top());
        int j = get<2>(pq.top());
        pq.pop();

        if (i == 5 * n - 1 && j == 5 * m - 1)
        {
            cout << -risk << endl;
            break;
        }

        for (int d = 0; d < 4; d++)
        {
            int ii = i + dx[d];
            int jj = j + dy[d];

            if (isSafe(ii, jj, 5 * n, 5 * m) && !visited[ii][jj])
            {
                pq.push({risk - matrix5x5[ii][jj], ii, jj});
                visited[ii][jj] = true;
            }
        }
    }
}