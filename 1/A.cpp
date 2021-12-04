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
    int ans = 0;
    for (int i = 1; i < nums.size(); i++)
        if (nums[i] > nums[i - 1])
            ans++;

    cout << ans << endl;
}