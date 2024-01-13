// https://www.hackerrank.com/contests/stack-queue-ug22/challenges/create-a-stack-using-linked-list

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack
{
private:
    StackNode *top;

public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
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
}

// } Driver Code Ends

// Function to push an integer into the stack.
void MyStack ::push(int x)
{
    // Your Code
    StackNode *NewHead = new StackNode(x);
    NewHead->next = top;
    top = NewHead;
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    // Your Code
    if (top != NULL)
    {
        StackNode *N = top;
        int y = N->data;
        top = top->next;
        delete N;
        return y;
    }

    return -1;
}
