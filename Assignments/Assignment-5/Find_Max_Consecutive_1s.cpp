// https://www.hackerrank.com/contests/stack-queue-ug22/challenges/find-maximum-consecutive-1s-in-a-binary-array
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int max_consecutive_ones(int *arr, int len)
{
    stack<int> s;
    int maxcount = 0, currcount = 0;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 1)
        {
            s.push(arr[i]);
            currcount = s.size();
        }
        else
        {
            while (!s.empty())
            {
                s.pop();
            }
            currcount = 0;
        }
        if (currcount > maxcount)
        {
            maxcount = currcount;
        }
    }
    return maxcount;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << max_consecutive_ones(a, n) << endl;
    return 0;
}