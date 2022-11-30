#include <bits/stdc++.h>
using namespace std;

int aa[1000][1000], N;
queue<int> order;
void go(int num)
{
    for (int i = 1; i <= N; i++)
    {
        if (not aa[num][i])
            continue;
        aa[num][i]--;
        aa[i][num]--;
        go(i);
    }
    order.push(num);
}

int DFS()
{
    cin >> N;
    bool even = true;
    for (int i = 1; i <= N; i++)
    {
        int how = 0;
        for (int j = 1; j <= N; j++)
        {
            cin >> aa[i][j];
            how += aa[i][j];
        }
        if (how % 2)
            even = false;
    }
    if (not even)
        cout << "-1";
    else
        go(1);
}
