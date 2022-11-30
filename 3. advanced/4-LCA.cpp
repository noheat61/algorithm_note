#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

int parent[10000][20];
int level[10000];
vector<int> child[10000];

void MAKE_TREE_DFS(int cur)
{
    for (int tmp : child[cur])
    {
        if (level[tmp] >= 0)
            continue;
        parent[tmp][0] = cur;
        level[tmp] = level[cur] + 1;

        for (int i = 1; i < 20; i++) // parent[i][N]: i의 2^N번째 parent
            parent[tmp][i] = parent[parent[tmp][i - 1]][i - 1];

        MAKE_TREE_DFS(tmp);
    }
}

int LCA(int a, int b)
{
    if (level[a] > level[b])
        swap(a, b);
    int chai = level[b] - level[a];

    // level 같게 하기
    for (int i = 19; i >= 0; i--)
    {
        if (chai < (1 << i))
            continue;
        b = parent[b][i];
        chai -= 1 << i;
    }

    if (a == b)
        return a;

    // LCA 바로 아래 단계로 이동
    for (int i = 19; i >= 0; i--)
    {
        if (parent[a][i] == parent[b][i])
            continue;
        a = parent[a][i];
        b = parent[b][i];
    }
    return parent[a][0];
}

int main()
{
    int N;
    cin >> N;
    MAKE_GRAPH_NO_WEIGHT(child);

    memset(level, -1, sizeof(level));
    level[1] = 0;
    MAKE_TREE_DFS(1);

    int a, b;
    cin >> a >> b;
    cout << LCA(a, b);
}
