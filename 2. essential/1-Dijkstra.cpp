#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;
priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>>
    pq;

vector<pair<int, int>> graph[10000];
int minnum[10000];

int Dijkstra()
{
    int V, E;
    cin >> V >> E;
    memset(minnum, -1, sizeof(minnum));

    int start;
    cin >> start;
    pq.push({0, start});
    MAKE_GRAPH_WEIGHT(graph);

    while (pq.size())
    {
        int cost = pq.top().first, cur = pq.top().second;
        pq.pop();

        if (minnum[cur] >= 0)
            continue;
        minnum[cur] = cost;

        for (pair<int, int> tmp : graph[cur])
        {
            if (minnum[tmp.second] >= 0)
                continue;
            pq.push({cost + tmp.first, tmp.second});
        }
    }
}
