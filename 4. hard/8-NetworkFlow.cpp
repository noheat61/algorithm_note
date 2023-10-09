#include <bits/stdc++.h>
using namespace std;

int c[1001][1001];
int f[1001][1001];
int parent[1001];
queue<int> qq;

int NETWORK(int start, int end, int N)
{
    //총 유량
    int sum = 0;
    // start -> end 경로 한 번에 반복 한 번씩
    while (1)
    {
        memset(parent, -1, sizeof(parent));
        while (qq.size())
            qq.pop();
        qq.push(start);
        parent[start] = start;

        // BFS로 잔여 그래프 만들기
        while (qq.size() and (parent[end] == -1))
        {
            int from = qq.front();
            qq.pop();

            for (int to = 1; to <= N; to++)
            {
                if (c[from][to] - f[from][to] <= 0)
                    continue;
                if (not(parent[to] == -1))
                    continue;
                parent[to] = from;
                qq.push(to);
            }
        }
        //더 이상 잔여 그래프 생성 안되면 break
        if (parent[end] == -1)
            break;

        //추가할 유량은 지나온 경로의 최솟값
        int minnum = INT_MAX, p = end;
        while (not(p == start))
        {
            minnum = min(c[parent[p]][p] - f[parent[p]][p], minnum);
            p = parent[p];
        }

        //유량 추가
        p = end;
        while (not(p == start))
        {
            f[parent[p]][p] += minnum;
            f[p][parent[p]] -= minnum;
            p = parent[p];
        }
        sum += minnum;
    }
    return sum;
}
