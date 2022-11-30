#include <bits/stdc++.h>
using namespace std;

int lower_bound(int *arr, int min, int max, int num)
{
    if (min == max)
        return min;

    int mid = (min + max) / 2;
    if (arr[mid] < num)
        return lower_bound(arr, mid + 1, max, num);
    else
        return lower_bound(arr, min, mid, num);
}

int upper_bound(int *arr, int min, int max, int num)
{
    if (min == max)
        return min;

    int mid = (min + max) / 2;
    if (arr[mid] <= num)
        return upper_bound(arr, mid + 1, max, num);
    else
        return upper_bound(arr, min, mid, num);
}

double f(double num) { return num; }
double TERNARY_SEARCH(double min, double max, int cnt)
{
    if (cnt == 10000)
        return min;

    double mid1 = (min * 2 + max) / 3;
    double mid2 = (min + max * 2) / 3;

    if (f(mid1) > f(mid2))
        return TERNARY_SEARCH(mid1, max, cnt + 1);
    else
        return TERNARY_SEARCH(min, mid2, cnt + 1);
}
