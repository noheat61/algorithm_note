#include <bits/stdc++.h>
using namespace std;

int arr[10000];
int tree[10000];
// tree[N]: arr[N - N의 가장 작은 bit + 1]부터 arr[N]까지 합
// tree[0b1100] = arr[0b1001] + arr[0b1001] + arr[0b1010] + arr[0b1011]
//(N & -N): N의 가장 작은 bit
int N;

void update(int num, int diff)
{
    //오른쪽으로 가면서 num을 포함하는 트리들 교체
    for (int i = num; i <= N; i += (i & -i))
        tree[i] += diff;
}
int sum(int num)
{
    //왼쪽으로 가면서 마지막 bit를 점점 키우면서 더하기
    int dap = 0;
    for (int i = num; i > 0; i -= (i & -i))
        dap += tree[i];
    return dap;
}
