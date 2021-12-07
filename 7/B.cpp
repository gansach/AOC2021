#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    fstream fin("input.txt");
    vector<int> nums;
    while (fin.good())
    {
        string x;
        getline(fin, x, ',');
        nums.push_back(stoi(x));
    }
    int m = *max_element(nums.begin(), nums.end());

    ll ans = INT_MAX;
    for (int x = 0; x <= m; x++)
    {
        ll tmp = 0;
        for (auto y : nums)
        {
            ll n = abs(x - y);
            tmp += (n * (n + 1)) / 2;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}