#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;
int ny[4] = {1, 0, -1, 0};
int nx[4] = {0, 1, 0, -1};
int minnum[10000];
vector<int> graph[10000];
queue<pair<int, int>> qq;

void go(int N)
{
    for (int tmp : graph[N])
    {
        if (minnum[tmp] >= 0)
            continue;
        minnum[tmp] = minnum[N]; //문제 조건에 맞게 설정
        go(tmp);
    }
}

void DFS()
{
    //그래프 만들기(1-2)
    MAKE_GRAPH_NO_WEIGHT(graph);

    //초기 설정
    memset(minnum, -1, sizeof(minnum));
    minnum[0] = 0;

    // DFS
    go(0);
}
