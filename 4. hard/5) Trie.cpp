#include <bits/stdc++.h>
using namespace std;

int Next[5000000][26];
bool Finish[5000000];
int p = 0;

void insert(string str)
{
    int node = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int curr;
        if (str[i] >= 'a')
            curr = str[i] - 'a';
        else
            curr = str[i] - 'A';

        if (not Next[node][curr])
            Next[node][curr] = ++p;
        node = Next[node][curr];
    }

    Finish[node] = true;
}

int find(string str)
{
    int node = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int curr;
        if (str[i] >= 'a')
            curr = str[i] - 'a';
        else
            curr = str[i] - 'A';

        if (not Next[node][curr])
            return 0;
        node = Next[node][curr];
    }
    return node;
}
