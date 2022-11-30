#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

vector<int> a[1001];
// d[i]: i의 parent
int parent[1001];
bool tmp[1001];

// x의 새로운 짝 찾아주기
bool MATCH(int x)
{
    for (int to : a[x])
    {
        //이미 확인 했었음
        if (tmp[to])
            continue;
        //자신의 것으로 이미 설정되어서 다시 탐색하면 안됨
        if (parent[to] == x)
            continue;
        // to 확인했음
        tmp[to] = true;

        //기존의 parent가 있고 이것을 바꿀 수 없을 때
        if (parent[to] and (not MATCH(parent[to])))
            continue;
        parent[to] = x;
        return true;
    }
    return false;
}

int main()
{
    int N;
    cin >> N;
    MAKE_GRAPH_NO_WEIGHT(a);
    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        memset(tmp, false, sizeof(tmp));
        //가능한 개수만큼 실행해줌(여기서는 1개)
        if (MATCH(i))
            cnt++;
    }
}
