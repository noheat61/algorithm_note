#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

int cnt[10000];
vector<int> graph[10000];
queue<int> qq, dap;

int TopologicalSorting()
{
    int N, M;
    cin >> N >> M;
    MAKE_GRAPH_NO_WEIGHT(graph); // cnt[to]++; 추가

    bool onlyone = true;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (not cnt[i])
        {
            qq.push(i);
            sum++;
        }
    }
    onlyone = (sum == 1);

    while (qq.size())
    {
        int go = qq.front();
        qq.pop();
        dap.push(go);

        sum = 0;
        for (int tmp : graph[go])
        {
            cnt[tmp]--;
            if (not cnt[tmp])
            {
                qq.push(tmp);
                sum++;
            }
        }
        if (onlyone and (sum >= 2))
            onlyone = false;
    }

    if (dap.size() < N)
        cout << "불가능!";
    else if (not onlyone)
        cout << "하나가 아님!";
}
