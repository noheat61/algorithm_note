#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int num[10000];
int tree[40000]; //(num 개수 이상의 2^k) * 2 < (num 개수) * 4
pair<int, int> range[40000];

int init(int start, int end, int node = 1)
{
    range[node] = {start, end};
    if (start == end)
        return tree[node] = num[start];

    int mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
    return tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update(int index, int diff, int node = 1)
{
    tree[node] += diff;
    if (range[node].first == range[node].second)
        return;

    int mid = (range[node].first + range[node].second) / 2;
    if (index <= mid)
        update(index, diff, node * 2);
    else
        update(index, diff, node * 2 + 1);
}
int sum(int from, int to, int node = 1)
{
    //구하고자 하는 범위와 겹치지 않을 때
    if (to < range[node].first or from > range[node].second)
        return 0;
    //구하고자 하는 범위 내부에 완전히 속할 때
    if (from <= range[node].first and to >= range[node].second)
        return tree[node];
    return sum(from, to, 2 * node) + sum(from, to, 2 * node + 1);
}
