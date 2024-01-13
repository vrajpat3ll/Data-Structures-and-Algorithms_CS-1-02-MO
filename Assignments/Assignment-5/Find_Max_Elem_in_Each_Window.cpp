// https://www.hackerrank.com/contests/stack-queue-ug22/challenges/find-maximum-element-in-each-window-which-size-is-given-
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int k = arr[n - 1];
    int t = n - k;
    
    queue<int> q;
    
    int j = 0;
    while (t > 0)
    {
        int l = 0;
        for (int i = j; i < j + k; i++)
        {
            q.push(arr[i]);
            if (q.front() > l)  l = q.front();
            q.pop();
        }
        cout << l << " ";
        j++;
        t--;
    }
    return 0;
}