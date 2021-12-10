#include <bits/stdc++.h>

using namespace std;

map<char, int> error = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};

int corruptedScore(string &s)
{
    stack<char> stk;
    for (auto c : s)
    {
        if (c == '(' || c == '[' || c == '{' || c == '<')
            stk.push(c);
        else if (c == ')' && stk.top() != '(')
            return error[c];
        else if (c == ']' && stk.top() != '[')
            return error[c];
        else if (c == '}' && stk.top() != '{')
            return error[c];
        else if (c == '>' && stk.top() != '<')
            return error[c];
        else
            stk.pop();
    }
    return 0;
}

int main(void)
{
    fstream fin("input.txt");
    int ans = 0;
    while (fin.good())
    {
        string line;
        getline(fin, line);
        ans += corruptedScore(line);
    }
    cout << ans << endl;
}