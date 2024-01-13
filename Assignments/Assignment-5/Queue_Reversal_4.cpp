// https://www.hackerrank.com/contests/stack-queue-ug22/challenges/queue-reversal-4-1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

queue<int> reverseK(queue<int> q, int k)
{

    stack<int> s;
    queue<int> qq;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        qq.push(s.top());
        s.pop();
    }
    while (!q.empty())
    {
        qq.push(q.front());
        q.pop();
    }

    return qq;
}

void printqueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> ogQ;
    int l;
    for (int i = 0; i < n; i++)
    {
        cin >> l;
        ogQ.push(l);
    }

    queue<int> NewQ = reverseK(ogQ, k);

    printqueue(NewQ);

    return 0;
}