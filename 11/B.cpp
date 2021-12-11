#include <bits/stdc++.h>

using namespace std;

bool isSafe(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int countFlashes(vector<vector<int>> &octopuses)
{
    int flashes = 0;
    for (int i = 0; i < octopuses.size(); i++)
        for (int j = 0; j < octopuses[i].size(); j++)
            if (octopuses[i][j] == 0)
                flashes++;
    return flashes;
}

void incrementOctopuses(vector<vector<int>> &octopuses)
{
    for (int i = 0; i < octopuses.size(); i++)
        for (int j = 0; j < octopuses[i].size(); j++)
            octopuses[i][j]++;
}

int maxOctopus(vector<vector<int>> &octopuses)
{
    int m = INT_MIN;
    for (int i = 0; i < octopuses.size(); i++)
        for (int j = 0; j < octopuses[i].size(); j++)
            m = max(m, octopuses[i][j]);
    return m;
}

void flashOctopuses(int i, int j, vector<vector<int>> &octopuses, set<pair<int, int>> &flashed)
{
    int n = octopuses.size();
    int m = octopuses[0].size();

    octopuses[i][j] = 0;

    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            if (di != 0 || dj != 0)
            {
                if (isSafe(i + di, j + dj, n, m) && flashed.find({i + di, j + dj}) == flashed.end())
                    octopuses[i + di][j + dj]++;
            }
        }
    }
}

void flash(vector<vector<int>> &octopuses, set<pair<int, int>> &flashed)
{
    for (int i = 0; i < octopuses.size(); i++)
    {
        for (int j = 0; j < octopuses[i].size(); j++)
        {
            if (octopuses[i][j] > 9 && flashed.find({i, j}) == flashed.end())
            {
                flashed.insert({i, j});
                flashOctopuses(i, j, octopuses, flashed);
                return;
            }
        }
    }
}

int main(void)
{
    fstream fin("input.txt");

    vector<vector<int>> octopuses;
    while (fin.good())
    {
        octopuses.push_back(vector<int>());

        string line;
        getline(fin, line);
        for (auto c : line)
            octopuses.back().push_back(c - '0');
    }

    int n = octopuses.size();
    int m = octopuses[0].size();

    for (int step = 1;; step++)
    {
        int flashes = 0;
        incrementOctopuses(octopuses);

        set<pair<int, int>> flashed;
        while (maxOctopus(octopuses) > 9)
        {
            flash(octopuses, flashed);
            flashes++;
        }
        if (flashes == n * m)
        {
            cout << step << endl;
            break;
        }
    }
}