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

void updateLazy(int node)
{
    if (lazy[node])
    {
        tree[node] += (scope[node].second - scope[node].first + 1) * lazy[node];
        if (scope[node].first != scope[node].second)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
    }
    lazy[node] = 0;
}

void update(int left, int right, ll diff, int node = 1)
{
    updateLazy(node);

    // 구하고자 하는 범위와 겹치지 않을 때
    if (right < scope[node].first or scope[node].second < left)
        return;

    // 구하고자 하는 범위 내부에 완전히 속할 때
    if (left <= scope[node].first and scope[node].second <= right)
    {
        tree[node] += (scope[node].second - scope[node].first + 1) * diff;

        // lazy propagation
        // 현재 노드에서의 update만으로 쿼리를 달성할 수 있으므로, 자식 노드의 업데이트는 lazy에 미뤄둠
        if (scope[node].first != scope[node].second)
        {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }

    update(left, right, diff, node * 2);
    update(left, right, diff, node * 2 + 1);

    // vanilla segment tree와 반대로, 트리 update는 leaf->root로 수행
    // 가장 깊은 노드부터 update한 뒤 재귀적으로 반영
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(int left, int right, int node = 1)
{
    updateLazy(node);

    // 구하고자 하는 범위와 겹치지 않을 때
    if (right < scope[node].first or scope[node].second < left)
        return 0LL;
    // 구하고자 하는 범위 내부에 완전히 속할 때
    if (left <= scope[node].first and scope[node].second <= right)
        return tree[node];
    return sum(left, right, node * 2) + sum(left, right, node * 2 + 1);
}