#include <bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
typedef vector<vector<ll>> matrix;
using namespace std;

matrix operator*(const matrix &a, const matrix &b)
{
    ll size = a.size();
    matrix res(size, vector<ll>(size));

    for (ll i = 0; i < size; i++)
        for (ll j = 0; j < size; j++)
        {
            for (ll k = 0; k < size; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    return res;
}

matrix power(matrix a, ll n)
{
    ll size = a.size();
    matrix res(size, vector<ll>(size));
    for (ll i = 0; i < size; i++)
        res[i][i] = 1;

    while (n)
    {
        if (n % 2)
            res = res * a;
        n /= 2;
        a = a * a;
    }
    return res;
}

int main(void)
{
    // T: matrix의 개수, N: column의 개수, D: 지수(power)
    ll T, N, D;
    cin >> T >> N >> D;

    // matrix 선언+초기화
    matrix dap(N, vector<ll>(N));
    for (ll i = 0; i < N; i++)
        dap[i][i] = 1;
    matrix gogo[100];
    for (int i = 0; i < T; i++)
        gogo[i].resize(N, vector<ll>(N));

    // matrix gogo에 입력받기

    // matrix multiple
    if (D >= T)
        for (int i = 0; i < T; i++)
            dap = dap * gogo[i];
    dap = power(dap, D / T);
    for (int i = 0; i < D % T; i++)
        dap = dap * gogo[i];
}
