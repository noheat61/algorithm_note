#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll num[1000010];
ll tree[4000000]; //(num 개수 이상의 2^k) * 2 < (num 개수) * 4
ll lazy[4000000];
pair<int, int> scope[4000000];

ll init(int start, int end, int node = 1)
{
    scope[node] = {start, end};
    if (start == end)
        return tree[node] = num[start];

    int mid = (start + end) / 2;
    tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    return tree[node];
}
void update(int index, ll diff, int node = 1)
{
    if (index < scope[node].first or scope[node].second < index)
        return;

    tree[node] += diff;
    if (scope[node].first == scope[node].second)
        return;

    update(index, diff, node * 2);
    update(index, diff, node * 2 + 1);
}

ll sum(int left, int right, int node = 1)
{
    // 구하고자 하는 범위와 겹치지 않을 때
    if (right < scope[node].first or scope[node].second < left)
        return 0LL;
    // 구하고자 하는 범위 내부에 완전히 속할 때
    if (left <= scope[node].first and scope[node].second <= right)
        return tree[node];
    return sum(left, right, node * 2) + sum(left, right, node * 2 + 1);
}
