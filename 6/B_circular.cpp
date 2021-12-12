#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(void)
{
    fstream fin("input.txt");

    deque<ll> fishes(9, 0);

    while (fin.good())
    {
        string fish;
        getline(fin, fish, ',');
        fishes[stoi(fish)]++;
    }

    for (int i = 0; i < 256; i++)
    {
        ll x = fishes.front();
        fishes.pop_front();
        fishes.push_back(x);
        fishes[6] += x;
    }
    cout << accumulate(fishes.begin(), fishes.end(), 0LL) << endl;
}