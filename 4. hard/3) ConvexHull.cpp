#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct pos
{
    ll x;
    ll y;
};

// a -> b -> c 방향으로 계산
// CCW > 0 : 반시계 방향, CCW = 0 : 일직선, CCW < 0 : 시계 방향
// abs(CCW)/2 : 삼각형의 넓이
ll CCW(pos a, pos b, pos c)
{
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

pos point[10000];
vector<pos> convex;

bool comp_y(pos a, pos b)
{ // y값이 작은 순서로 정렬
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

bool comp_c(pos a, pos b)
{
    long long cc = CCW(point[0], a, b); // point[0] -> a -> b 순서
    if (cc == 0)
        return (a.x + a.y) < (b.x + b.y); //일직선이면 작은 것부터
    return cc > 0;                        //반시계 방향 정렬
}

void ConvexHull(void)
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> point[i].x >> point[i].y;

    // v[0]에 y값 최소 pos -> 일정한 방향으로 탐색
    sort(point, point + N, comp_y);
    sort(point + 1, point + N, comp_c);

    pos from, via;

    for (int i = 0; i < N; i++)
    {
        while (convex.size() >= 2)
        { //두 개 미만이면 볼록 의미 없음
            via = convex.back();
            convex.pop_back();
            from = convex.back();
            //일직선이거나 시계 방향이면 다시 탐색
            if (CCW(from, via, point[i]) <= 0)
                continue;

            convex.push_back(via); // via 거쳐서 볼록이면 via 삽입
            break;
        }
        convex.push_back(point[i]); // to(도착)는 항상 삽입
    }
}
