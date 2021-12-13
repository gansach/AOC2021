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

    int n = INT_MIN, m = INT_MIN;
    set<pair<int, int>> points;

    string line;
    while (getline(fin, line))
    {
        if (line.empty())
            break;
        int i = line.find(",");
        int x = stoi(line.substr(0, i));
        int y = stoi(line.substr(i + 1));

        points.insert({x, y});
    }

    vector<pair<char, int>> folds;

    while (getline(fin, line))
    {
        char c;
        int i;
        sscanf(line.c_str(), "fold along %c=%d", &c, &i);
        folds.push_back({c, i});
    }

    auto fold = folds.front();

    char c = fold.first;
    int l = fold.second;

    if (c == 'x')
        points = reflectHorizontal(points, l);
    else if (c == 'y')
        points = reflectVertical(points, l);
    cout << points.size() << endl;
}