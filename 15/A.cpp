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

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[0][0] = true;

    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 0, 0});

    while (!pq.empty())
    {
        int risk = get<0>(pq.top());
        int i = get<1>(pq.top());
        int j = get<2>(pq.top());
        pq.pop();

        if (i == n - 1 && j == m - 1)
        {
            cout << -risk << endl;
            break;
        }

        for (int d = 0; d < 4; d++)
        {
            int ii = i + dx[d];
            int jj = j + dy[d];

            if (isSafe(ii, jj, n, m) && !visited[ii][jj])
            {
                pq.push({risk - matrix[ii][jj], ii, jj});
                visited[ii][jj] = true;
            }
        }
    }
}
