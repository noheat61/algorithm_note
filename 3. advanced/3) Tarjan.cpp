#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

vector<int> FOR[10000];
vector<vector<int>> SCC_VECTOR;
stack<int> order;
// VISIT_ORDER[N]: N을 몇 번째 방문했는지, SCC_NUM[N]: N이 몇 번째 SCC인지
int VISIT_ORDER[10000], SCC_NUM[10000];
int cnt = 1;

int go(int num)
{
    if (SCC_NUM[num])
        return 0;

    VISIT_ORDER[num] = cnt++;
    order.push(num);

    // DFS 탐색(반복문 돌고 나면 INIT_ORDER=SCC 시작점의 VISIT_ORDER)
    int INIT_ORDER = VISIT_ORDER[num];
    for (int i : FOR[num])
    {
        if (SCC_NUM[i] > 0)
            continue;

        //아직 탐색하지 않았을 때(DFS)
        if (not VISIT_ORDER[i])
            INIT_ORDER = min(INIT_ORDER, go(i));
        //탐색한 곳일 때(SCC의 시작점)
        else
            INIT_ORDER = min(INIT_ORDER, VISIT_ORDER[i]);
    }
    //현재 node가 SCC의 시작점이면 SCC 만들기
    if (INIT_ORDER == VISIT_ORDER[num])
    {
        vector<int> CUR_SCC;
        // stack에서 SCC vector 만들기
        while (1)
        {
            int tmp = order.top();
            order.pop();
            CUR_SCC.push_back(tmp);
            SCC_NUM[tmp] = SCC_VECTOR.size() + 1;
            if (tmp == num)
                break;
        }
        SCC_VECTOR.push_back(CUR_SCC);
    }

    return INIT_ORDER;
}

int Tarjan()
{
    int V, E;
    cin >> V >> E;
    MAKE_GRAPH_NO_WEIGHT(FOR);

    for (int i = 1; i <= V; i++)
    {
        if (SCC_NUM[i])
            continue;
        go(i);
    }
}
