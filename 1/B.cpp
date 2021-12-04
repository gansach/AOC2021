#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    fstream fin("input.txt");
    vector<int> nums;
    while (fin.good())
    {
        int x;
        fin >> x;
        nums.push_back(x);
    }

    vector<int> triplets;
    for (int i = 0; i < nums.size() - 2; i++)
        triplets.push_back(nums[i] + nums[i + 1] + nums[i + 2]);

    int ans = 0;
    for (int i = 1; i < triplets.size(); i++)
        if (triplets[i] > triplets[i - 1])
            ans++;

    cout << ans << endl;
}