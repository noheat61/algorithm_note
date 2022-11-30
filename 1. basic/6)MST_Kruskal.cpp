#include <bits/stdc++.h>
#include "DisjointSet.h"
using namespace std;

priority_queue<pair<int, pair<int, int>>,
               vector<pair<int, pair<int, int>>>,
               greater<pair<int, pair<int, int>>>>
    pq;

extern int root[10000];
extern int lvl[10000];

int Kruskal()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        pq.push({cost, {a, b}});
    }

    int dap = 0;
    init(1, N);

    while (pq.size())
    {
        int cur = pq.top().first;
        pair<int, int> tmp = pq.top().second;
        pq.pop();

        if (find(tmp.first) == find(tmp.second))
            continue;
        merge(tmp.first, tmp.second);
        dap += cur;
    }

    return dap;
}
