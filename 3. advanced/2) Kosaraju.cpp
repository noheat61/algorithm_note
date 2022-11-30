#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

vector<int> FOR[10000], BACK[10000], empty_vector; // FOR: 정방향, BACK: 역방향
vector<vector<int>> SCC_VECTOR;                    // SCC 집합
stack<int> order;                                  // leaf부터 push -> root부터 탐색
bool visit[10000];

// leaf->root(단방향): root에서 leaf로 접근 불가이므로 leaf가 나중에 쌓임
// BACK에서는 root->leaf인데 leaf 먼저 탐색하므로 접근 불가
// root->leaf(단방향): leaf가 stack에 먼저 쌓이고 root가 나중에 쌓임
// BACK에서는 leaf->root인데 root 먼저 탐색하므로 접근 불가

void KOSARAJU1(int num)
{
    if (visit[num])
        return;
    visit[num] = true; // visit은 바로바로 -> 탐색 순서대로
    for (int i : FOR[num])
        KOSARAJU1(i);
    order.push(num); // order은 DFS 후에 -> 탐색 역순대로
}
void KOSARAJU2(int num)
{
    if (visit[num])
        return;
    visit[num] = true;
    for (int i : BACK[num])
        KOSARAJU2(i);
    SCC_VECTOR[SCC_VECTOR.size() - 1].push_back(num);
}

int KOSARAJU()
{
    int V, E;
    cin >> V >> E;
    MAKE_GRAPH_WEIGHT(FOR);
    MAKE_GRAPH_WEIGHT(BACK); // edge의 방향을 반대로 하여

    // root부터 DFS로 stack 삽입 (main_root = 1)
    for (int i = 1; i <= V; i++)
        KOSARAJU1(i);

    // leaf부터 SCC 탐색
    memset(visit, 0, sizeof(visit));
    while (order.size())
    {
        int tmp = order.top();
        order.pop();
        if (visit[tmp])
            continue;
        // not visit이면 새로운 SCC(자기 자신뿐만이더라도..)
        SCC_VECTOR.push_back(empty_vector);
        KOSARAJU2(tmp);
    }
}
