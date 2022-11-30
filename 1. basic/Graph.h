#include <bits/stdc++.h>
using namespace std;

void MAKE_GRAPH_NO_WEIGHT(vector<int> unweighted[])
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        unweighted[a].push_back(b);
        unweighted[b].push_back(a);
    }
}

void MAKE_GRAPH_WEIGHT(vector<pair<int, int>> weighted[])
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        weighted[a].push_back({c, b});
        weighted[b].push_back({c, a});
    }
}