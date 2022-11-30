#include <bits/stdc++.h>
using namespace std;

int pi[10000];     // prefix와 suffix의 겹치는 개수
vector<int> index; // a와 b가 완전히 같아지는 시작 index

void GETPI(string str)
{
    int cur = 0;

    for (int i = 1; i < str.size(); i++)
    {
        //처음 cur = pi[i-1]
        //그러므로 str[i-1]까지 cur개(str[cur-1]까지)는 현재 겹치는 상태
        // i번째에서 겹치지 않을 때 -> pi를 이용해 다음 후보군으로
        // str[cur-1]까지 겹쳤음 -> 다음 후보는 str[pi[cur-1]-1]까지 겹침
        //그러면 str[i]와 str[(pi[cur-1]-1)+1]을 비교해야 함
        //그러므로 cur=pi[cur-1] -> str[i] ?= a[cur] 반복
        //계속 불일치한다면 cur -> 0
        while ((not(str[cur] == str[i])) and cur > 0)
            cur = pi[cur - 1];
        if (str[i] == str[cur])
            pi[i] = ++cur;
    }
}
void SEARCH(string a, string b)
{
    int it_b = 0;
    for (int it_a = 0; it_a < a.size(); it_a++)
    {
        while ((not(a[it_a] == b[it_b])) and it_b > 0)
            it_b = pi[it_b - 1];

        if (a[it_a] == b[it_b])
        {
            it_b++;
            if (it_b == b.size())
            {
                index.push_back((it_a + 1) - (it_b - 1));
                it_b = pi[it_b - 1];
            }
        }
    }
}
void KMP()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);

    GETPI(b);
    SEARCH(a, b);
}
