#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;
int minnum[10000];
vector<int> graph[10000];
queue<int> qq;

void BFS()
{
    MAKE_GRAPH_NO_WEIGHT(graph);

    //초기 설정
    memset(minnum, -1, sizeof(minnum));
    minnum[0] = 0;
    qq.push(0);

    // BFS
    while (qq.size())
    {
        int go = qq.front();
        qq.pop();

        for (int tmp : graph[go])
        {
            if (minnum[tmp] >= 0)
                continue;
            minnum[tmp] = minnum[go]; //문제 조건에 맞게 설정
            qq.push(tmp);
        }
    }
}