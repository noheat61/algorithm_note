#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;
typedef long long ll;

ll dist[10000];
vector<pair<ll, int>> graph[10000];

int BellmanFord()
{
    int N, M;
    cin >> N >> M;

    bool negative = false;
    MAKE_GRAPH_WEIGHT(graph); //{cost, to}
    fill(dist + 1, dist + N, LLONG_MAX);
    dist[1] = 0;
    //시작 위치 입력받는다면, 환형 회전 만들어서 1번 되도록 조정

    for (int i = 1; i <= N; i++)
    { // N-1번 반복 + N번째는 negative 확인
        for (int j = 1; j <= N; j++)
        { // 1부터 N번 위치까지 순환하며 확인

            if (dist[j] == LLONG_MAX)
                continue;
            for (pair<ll, int> tmp : graph[j])
            {
                if (dist[tmp.second] <= tmp.first + dist[j])
                    continue;
                dist[tmp.second] = tmp.first + dist[j];
                if (i == N)
                    negative = true;
            }
        }
    }
}
