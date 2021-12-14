#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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

    map<char, ll> charFreq;
    for (auto c : s)
        charFreq[c]++;

    map<string, ll> pairFreq, tmp;
    for (int i = 0; i < s.size() - 1; i++)
        pairFreq[s.substr(i, 2)]++;

    for (int i = 0; i < 40; i++)
    {
        for (auto itr : pairFreq)
        {
            string t = itr.first;
            charFreq[polymers[t]] += itr.second;

            string t1 = string({t[0], polymers[t]});
            string t2 = string({polymers[t], t[1]});

            tmp[t1] += itr.second;
            tmp[t2] += itr.second;
        }
        swap(pairFreq, tmp);
        tmp.clear();
    }

    auto maxx = *max_element(charFreq.begin(), charFreq.end(), [](const pair<char, ll> &a, const pair<char, ll> &b)
                             { return a.second < b.second; });

    auto minn = *min_element(charFreq.begin(), charFreq.end(), [](const pair<char, ll> &a, const pair<char, ll> &b)
                             { return a.second < b.second; });

    cout << maxx.second - minn.second << endl;
}