#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> reflectHorizontal(set<pair<int, int>> points, int l)
{
    set<pair<int, int>> reflected;
    for (auto point : points)
    {
        int x = point.first, y = point.second;
        if (x == l)
            continue;
        else if (x < l)
            reflected.insert(point);
        else if (x > l)
            reflected.insert({2 * l - x, y});
    }
    return reflected;
}

set<pair<int, int>> reflectVertical(set<pair<int, int>> points, int l)
{
    set<pair<int, int>> reflected;
    for (auto point : points)
    {
        int x = point.first, y = point.second;
        if (y == l)
            continue;
        else if (y < l)
            reflected.insert(point);
        else if (y > l)
            reflected.insert({x, 2 * l - y});
    }
    return reflected;
}

int main(void)
{
    fstream fin("input.txt");

    set<pair<int, int>> points;

    string line;
    while (getline(fin, line))
    {
        if (line.empty())
            break;
        int i = line.find(",");
        points.insert({stoi(line.substr(0, i)), stoi(line.substr(i + 1))});
    }

    vector<pair<char, int>> folds;

    while (getline(fin, line))
    {
        char c;
        int i;
        sscanf(line.c_str(), "fold along %c=%d", &c, &i);
        folds.push_back({c, i});
    }

    for (auto fold : folds)
    {
        char c = fold.first;
        int l = fold.second;

        if (c == 'x')
            points = reflectHorizontal(points, l);
        else if (c == 'y')
            points = reflectVertical(points, l);
    }

    int n = INT_MIN, m = INT_MIN;
    for (auto point : points)
    {
        n = max(n, point.first + 1);
        m = max(m, point.second + 1);
    }

    vector<vector<char>> matrix(n, vector<char>(m, ' '));
    for (auto point : points)
        matrix[point.first][point.second] = 219;

    for (auto row : matrix)
    {
        for (auto c : row)
            cout << c;
        cout << endl;
    }

    // Answer: CPZLPFZL
}