#include <bits/stdc++.h>

using namespace std;

string polymerize(string s, map<string, char> &polymers)
{
    string t;
    for (auto c : s)
    {
        t.push_back(c);
        t.push_back(' ');
    }
    for (int i = 0; i < s.size() - 1; i++)
        t[2 * i + 1] = polymers[s.substr(i, 2)];

    return t;
}

using namespace std;

int main(void)
{
    fstream fin("input.txt");

    string s;
    getline(fin, s);

    map<string, char> polymers;

    string line;
    while (getline(fin, line))
    {
        if (!line.empty())
        {
            char a, b, c;
            sscanf(line.c_str(), "%c%c -> %c", &a, &b, &c);
            string poly({a, b});
            polymers[poly] = c;
        }
    }
    for (int i = 0; i < 10; i++)
        s = polymerize(s, polymers);

    map<char, int> frequency;
    for (auto c : s)
        if (c >= 'A' && c <= 'Z')
            frequency[c]++;

    auto maxx = *max_element(frequency.begin(), frequency.end(), [](const pair<char, int> &a, const pair<char, int> &b)
                             { return a.second < b.second; });

    auto minn = *min_element(frequency.begin(), frequency.end(), [](const pair<char, int> &a, const pair<char, int> &b)
                             { return a.second < b.second; });

    cout << maxx.second - minn.second << endl;
}