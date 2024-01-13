// https://www.hackerrank.com/contests/stack-queue-ug22/challenges/queue-using-two-stacks
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s;
    stack<int> q;

public:
    void Enqueue(int x)
    {
        s.push(x);
    }

    void Dequeue()
    {
        if (!q.empty())
        {
            q.pop();
        }
        else
        {
            while (!s.empty())
            {
                q.push(s.top());
                s.pop();
            }
            q.pop();
        }
    }

    void PrintFront()
    {
        if (!q.empty())
        {
            cout << q.top() << endl;
        }
        else
        {
            while (!s.empty())
            {
                q.push(s.top());
                s.pop();
            }
            cout << q.top() << endl;
        }
    }
};

int main()
{
    int q;
    cin >> q;
    Queue Q;
    int QueryType, x;
    for (int i = 0; i < q; i++)
    {
        cin >> QueryType;
        switch (QueryType)
        {
        case 1:
            cin >> x;
            Q.Enqueue(x);
            break;
        case 2:
            Q.Dequeue();
            break;
        case 3:
            Q.PrintFront();
        default:
            break;
        }
    }

    return 0;
}