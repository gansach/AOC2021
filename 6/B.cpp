#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<pair<ll, ll>, ll> memo;
ll num_fishes(ll fish, ll days)
{
    if (days == 0)
        return 0;

    if (memo[{fish, days}])
        return memo[{fish, days}];

    if (fish == 0)
        return memo[{fish, days}] = 1 + num_fishes(6, days - 1) + num_fishes(8, days - 1);

    return memo[{fish, days}] = num_fishes(fish - 1, days - 1);
}

int main(void)
{
    fstream fin("input.txt");

    ll ans = 0;
    while (fin.good())
    {
        string fish;
        getline(fin, fish, ',');
        ans += num_fishes(stoi(fish), 256) + 1;
    }
    cout << ans << endl;
}