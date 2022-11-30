#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

pair<ll, ll> ext_gcd(ll a, ll b)
{ // ax+by = gcd(a,b)
    int x1 = 1, y1 = 0;
    int x2 = 0, y2 = 1;
    while (a % b)
    {
        int tmp = a % b;
        int tmpx = x1 - (a / b) * x2;
        int tmpy = y1 - (a / b) * y2;
        a = b, b = tmp;
        x1 = x2, x2 = tmpx;
        y1 = y2, y2 = tmpy;
    }
    return {x2, y2};
}

ll mod_inv(ll a, ll m)
{ // ax+my = ax = 1 mod m
    int x = ext_gcd(a, m).first;
    if (x < 0)
        x += m; //음수일 때는 m 더함
    return x;
}
