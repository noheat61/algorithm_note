#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int num[10000];

int MY_lower_bound(int min, int max, int N)
{
    if (num[min] == num[max])
        return min;

    int mid = (min + max) / 2;
    if (num[mid] < num[N])
        return MY_lower_bound(mid + 1, max, N);
    else
        return MY_lower_bound(min, mid, N);
}

int LIS()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];

        //시작할 때 or 가장 큰 값일 때
        if ((not dp.size()) or (num[i] > num[dp.back()]))
            dp.push_back(i);
        //중간의 값이 들어왔을 때
        else
        {
            // num[dp[it]] >= num[i]인 최소의 it
            int it = MY_lower_bound(0, dp.size() - 1, i);
            if (num[dp[it]] > num[i])
                dp[it] = i;
        }
    }
}
