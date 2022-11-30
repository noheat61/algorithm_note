#include <bits/stdc++.h>
using namespace std;

int minnum[100][100];

int FloydWarshall()
{
    int V, E;
    cin >> V >> E;
    fill(&minnum[0][0], &minnum[V][V + 1], INT_MAX);
    for (int i = 0; i < E; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        minnum[a][b] = min(minnum[a][b], cost);
    }

    for (int via = 1; via <= V; via++)
    {
        for (int from = 1; from <= V; from++)
        {
            for (int to = 1; to <= V; to++)
                minnum[from][to] = min(minnum[from][to], minnum[from][via] + minnum[via][to]);
        }
    }
}
