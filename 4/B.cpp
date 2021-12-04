#include <bits/stdc++.h>

using namespace std;

#define N 5

void mark(int **board, int x)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == x)
                board[i][j] = -1;
}

bool check(int **board)
{
    for (int row = 0; row < N; row++)
    {
        int cnt = 0;
        for (int j = 0; j < N; j++)
            if (board[row][j] == -1)
                cnt++;

        if (cnt == N)
            return true;
    }

    for (int col = 0; col < N; col++)
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (board[i][col] == -1)
                cnt++;

        if (cnt == N)
            return true;
    }

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        if (board[i][i] == -1)
            cnt++;
        if (cnt == N)
            return true;
    }

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        if (board[i][4 - i] == -1)
            cnt++;

        if (cnt == N)
            return true;
    }
    return false;
}

int score(int **board)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] != -1)
                sum += board[i][j];
    return sum;
}

int main(void)
{
    fstream fin("input.txt");

    string numbers;
    getline(fin, numbers);
    stringstream ss(numbers);

    vector<int> nums;
    while (ss.good())
    {
        string num;
        getline(ss, num, ',');
        nums.push_back(stoi(num));
    }

    vector<int **> boards;
    while (fin.good())
    {
        int **board = new int *[N];
        for (int i = 0; i < N; i++)
            board[i] = new int[N];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                fin >> board[i][j];

        boards.push_back(board);
    }

    int lastScore = 0;
    map<int **, bool> hasWon;

    for (auto num : nums)
    {
        for (auto board : boards)
        {
            mark(board, num);
            if (!hasWon[board] && check(board))
            {
                lastScore = score(board) * num;
                hasWon[board] = true;
            }
        }
    }
    cout << lastScore << endl;
}