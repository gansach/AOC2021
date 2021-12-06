#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    fstream fin("input.txt");

    int *fishes = new int[100000000];

    int size = 0;
    while (fin.good())
    {
        string fish;
        getline(fin, fish, ',');
        fishes[size++] = stoi(fish);
    }

    int days = 80;
    while (days--)
    {
        for (int i = 0; i < size; i++)
        {
            if (fishes[i])
                fishes[i]--;
            else
            {
                fishes[i] = 6;
                fishes[size++] = 9; // Size++, so newly added fish gets decremented
            }
        }
    }

    cout << size << endl;

    delete[] fishes;
}