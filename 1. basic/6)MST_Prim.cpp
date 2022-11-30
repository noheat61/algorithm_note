#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>>
    pq;

vector<pair<int, int>> graph[10000];
bool visited[10000];

int Prim()
{
    int N;
    cin >> N;
    MAKE_GRAPH_WEIGHT(graph);

    int dap = 0;
    pair<int, int> go;
    pq.push({0, 1}); // {cost, 지점}

    while (pq.size())
    {
        int cost = pq.top().first, next = pq.top().second;
        pq.pop();

        if (visited[next])
            continue;
        visited[next] = true;
        dap += cost;

        for (pair<int, int> tmp : graph[next])
        {
            if (visited[tmp.second])
                continue;
            pq.push(tmp);
        }
    }
    cout << dap;
}
