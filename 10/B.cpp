#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<char, int> error = {{'(', 1}, {'[', 2}, {'{', 3}, {'<', 4}};

void incompleteScore(string &s, vector<ll> &scores)
{
    stack<char> stk;
    for (auto c : s)
    {
        if (c == '(' || c == '[' || c == '{' || c == '<')
            stk.push(c);
        else if (c == ')' && stk.top() != '(')
            return;
        else if (c == ']' && stk.top() != '[')
            return;
        else if (c == '}' && stk.top() != '{')
            return;
        else if (c == '>' && stk.top() != '<')
            return;
        else
            stk.pop();
    }
    if (stk.empty())
        return;

    ll score = 0;
    while (!stk.empty())
    {
        score *= 5;
        score += error[stk.top()];
        stk.pop();
    }
    scores.push_back(score);
}

int main(void)
{
    fstream fin("input.txt");
    int ans = 0;
    vector<ll> incompleteScores;
    while (fin.good())
    {
        string line;
        getline(fin, line);
        incompleteScore(line, incompleteScores);
    }
    sort(incompleteScores.begin(), incompleteScores.end());
    cout << incompleteScores[incompleteScores.size() / 2] << endl;
}