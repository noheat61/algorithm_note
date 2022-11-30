#include <bits/stdc++.h>
using namespace std;

int dp[2][100000];

int Knapsack()
{
    int N;
    cin >> N;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    // dp[N][M]: N번째까지 A가 M시간일 때 B의 시간

    for (int i = 1; i <= N; i++)
    {
        int WA, WB;
        cin >> WA >> WB;
        int cur = i % 2, past = (i - 1) % 2;

        for (int j = 0; j <= 100000; j++)
        {
            if (dp[past][j] < 0)
                continue;

            if (dp[cur][j + WA] < 0)
                dp[cur][j + WA] = dp[past][j];
            else
                dp[cur][j + WA] = min(dp[cur][j + WA], dp[past][j]);

            if (dp[cur][j] < 0)
                dp[cur][j] = dp[past][j] + WB;
            else
                dp[cur][j] = min(dp[cur][j], dp[past][j] + WB);

            dp[past][j] = -1;
        }
    }
}
