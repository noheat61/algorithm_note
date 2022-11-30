#include <bits/stdc++.h>
using namespace std;

int dp[2][100000];

int Knapsack()
{
    int N, K;
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++)
    {
        int W, V;
        cin >> W >> V;
        int cur = i % 2, past = (i - 1) % 2;
        for (int j = 0; j <= K; j++)
        {
            if (j + W <= K)
                break;
            if (dp[past][j] < 0)
                continue;

            if (dp[cur][j + W] < 0)
                dp[cur][j + W] = dp[past][j] + V;
            else
                dp[cur][j + W] = max(dp[cur][j + W], dp[past][j] + V);
            dp[past][j] = -1;
        }
    }
}
