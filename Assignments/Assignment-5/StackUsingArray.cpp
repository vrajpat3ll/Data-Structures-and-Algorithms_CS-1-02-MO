// https://www.hackerrank.com/contests/stack-queue-ug22/challenges/stack-using-array-6

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};

int main()
{
    MyStack *sq = new MyStack();

    int Q;
    cin >> Q;
    while (Q--)
    {
        int QueryType = 0;
        cin >> QueryType;
        if (QueryType == 1)
        {
            int a;
            cin >> a;
            sq->push(a);
        }
        else if (QueryType == 2)
        {
            cout << sq->pop() << " ";
        }
    }

    return 0;
}

// } Driver Code Ends

// Function to push an integer into the stack.

void MyStack ::push(int x)
{
    // Your Code
    if (top < 1000)
    {
        top = top + 1;
        arr[top] = x;
    }
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    // Your Code
    if (top != -1)
    {
        top -= 1;
        return arr[top + 1];
    }
    return -1;
}