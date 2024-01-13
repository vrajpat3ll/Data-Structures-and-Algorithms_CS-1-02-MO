#include <bits/stdc++.h>
using namespace std;
struct Node *modifyTheList(struct Node *head);
typedef struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }

} Node;

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution
{
public:
    struct Node *modifyTheList(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *start = head;
        Node *tail = head;

        int n = 1;
        while (tail->next != NULL)
        {
            tail = tail->next;
            n++;
        }

        for (int i = 0; i < n / 2; i++)
        {
            int temp = start->data;
            start->data = tail->data - start->data;
            tail->data = temp;

            tail = head;
            for (int j = 0; j < n - i - 2; j++, tail = tail->next){}

            start = start->next;
        }

        return head;
    }
};

//{ Driver Code Starts.
int main()
{
    int n;
    cin >> n;
    struct Node *head = NULL, *temp = NULL;
    while (n--)
    {
        int a;
        cin >> a;
        Node *newNode = new Node(a);
        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    Solution obj;
    head = obj.modifyTheList(head);
    print(head);
    return 0;
}