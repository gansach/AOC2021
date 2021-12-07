#include <bits/stdc++.h>

using namespace std;

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
    int ans = INT_MAX;
    for (auto x : nums)
    {
        int tmp = 0;
        for (auto y : nums)
        {
            tmp += abs(x - y);
        }
    }
    cout << ans << endl;
}