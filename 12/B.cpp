#include <bits/stdc++.h>

using namespace std;

bool isLower(string &s)
{
    for (auto c : s)
        if (isupper(c))
            return false;
    return true;
}

int explore(string s, string d, map<string, vector<string>> &edges, vector<string> &path, string smallVisited)
{
    if (s == d)
        return 1;

    if (isLower(s) && find(path.begin(), path.end(), s) != path.end())
    {
        if (smallVisited.empty() && s != "start")
            smallVisited = s;
        else
            return 0;
    }

    int paths = 0;

    path.push_back(s);
    for (auto neighbor : edges[s])
        paths += explore(neighbor, d, edges, path, smallVisited);
    path.pop_back();

    if (smallVisited == s)
        smallVisited.clear();

    return paths;
}

int main(void)
{
    fstream fin("input.txt");

    map<string, vector<string>> edges;
    while (fin.good())
    {
        string edge;
        getline(fin, edge);
        int x = edge.find('-');

        string s = edge.substr(0, x);
        string d = edge.substr(x + 1);

        edges[s].push_back(d);
        edges[d].push_back(s);
    }

    vector<string> path;
    string smallVisited = "";
    cout << explore("start", "end", edges, path, smallVisited) << endl;
}