#include <bits/stdc++.h>

using namespace std;

const int TXmin = 156;
const int TXmax = 202;

const int TYmin = -110;
const int TYmax = -69;

bool isInTargetArea(int x, int y)
{
    return x >= TXmin && x <= TXmax && y >= TYmin && y <= TYmax;
}

int maxProbeHeight(int vx, int vy)
{
    int x = 0, y = 0;
    int maxHeight = INT_MIN;

    bool inTargetArea = false;

    while (y >= TYmin)
    {
        x += vx;
        y += vy;

        if (isInTargetArea(x, y))
        {
            inTargetArea = true;
        }

        maxHeight = max(maxHeight, y);

        if (vx > 0)
            vx--;
        else if (vx < 0)
            vx++;

        vy--;
    }
    return inTargetArea ? maxHeight : INT_MIN;
}

int main(void)
{
    int ans = INT_MIN;
    for (int i = 0; i <= TXmax; i++)
        for (int j = -1000; j <= 1000; j++)
            ans = max(ans, maxProbeHeight(i, j));

    cout << ans << endl;
}