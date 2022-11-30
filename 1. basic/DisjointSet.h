#include <bits/stdc++.h>
using namespace std;

int root[10000];
int lvl[10000];

void init(int num1, int num2)
{
    for (int i = num1; i <= num2; i++)
    {
        root[i] = -1;
        lvl[i] = 1;
    }
}

int find(int num)
{
    if (root[num] < 0)
        return num;
    return root[num] = find(root[num]);
}

void merge(int num1, int num2)
{
    int r1 = find(num1);
    int r2 = find(num2);
    if (r1 == r2)
        return;

    if (lvl[r1] < lvl[r2])
    {
        root[r2] += root[r1];
        root[r1] = r2;
    }
    else
    {
        root[r1] += root[r2];
        root[r2] = r1;
    }
    if (lvl[r1] == lvl[r2])
        lvl[r1]++;
}
