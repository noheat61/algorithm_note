#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;
int ny[4] = {1, 0, -1, 0};
int nx[4] = {0, 1, 0, -1};
int minnum[100][100];
vector<int> graph[100];
queue<pair<int, int>> qq;

void BFS()
{
    int N, M;
    MAKE_GRAPH_NO_WEIGHT(graph);

    //초기 설정
    memset(minnum, -1, sizeof(minnum));
    minnum[0][0] = 0;
    qq.push({0, 0});

    // BFS
    while (qq.size())
    {
        pair<int, int> go = qq.front();
        qq.pop();

        for (int i = 0; i < 4; i++)
        {
            int tmpy = go.first + ny[i], tmpx = go.second + nx[i];
            if (tmpy >= N or tmpy < 0)
                continue;
            if (tmpx >= M or tmpx < 0)
                continue;
            if (minnum[tmpy][tmpx] >= 0)
                continue;
            minnum[tmpy][tmpx] = minnum[go.first][go.second];
            qq.push({tmpy, tmpx});
        }
    }
}