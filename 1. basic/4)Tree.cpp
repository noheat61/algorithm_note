#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

int parent[10000];
int level[10000];
vector<int> graph[10000];

void go(int N)
{
    for (int tmp : graph[N])
    {
        if (level[tmp] >= 0)
            continue;
        parent[tmp] = N;
        level[tmp] = level[N] + 1;
        go(tmp);
    }
}

void MAKE_TREE()
{
    int N;
    cin >> N;
    MAKE_GRAPH_NO_WEIGHT(graph);

    memset(level, -1, sizeof(level));
    level[1] = 0;
    go(1);
}
