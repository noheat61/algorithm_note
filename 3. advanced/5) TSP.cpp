#include <bits/stdc++.h>
using namespace std;

int cost[16][16];
int dp[1 << 16][16]; //{현재 위치, 방문한 지점들}
int dap = INT_MAX;

int TSP()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            cost[i][j] = tmp;
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0; // 0에서 출발

    for (int visit = 0; visit < (1 << N); visit++)
    { //방문한 지점들
        for (int cur = 0; cur < N; cur++)
        { //현재 위치
            if (dp[visit][cur] < 0)
                continue; //이전에 방문하지 못함
            for (int next = 1; next < N; next++)
            { //다음 위치
                if (visit & (1 << next))
                    continue; //이미 갔음
                if (not cost[cur][next])
                    continue; //방문하지 못함
                int next_visit = visit + (1 << next);
                //다른 경로로 이미 찍었다면 최솟값만 갱신
                if (dp[next_visit][next] >= 0)
                    dp[next_visit][next] =
                        min(dp[next_visit][next], dp[visit][cur] + cost[cur][next]);
                //안 찍었다면 추가
                else
                    dp[next_visit][next] = dp[visit][cur] + cost[cur][next];
            }
        }
    }
    //전부 찍었을 때
    for (int cur = 1; cur < N; cur++)
    {
        if (not cost[cur][0])
            continue; // 0으로 돌아가지 못함
        dap = min(dap, dp[(1 << N) - 1][cur] + cost[cur][0]);
    }
    cout << dap;
}
