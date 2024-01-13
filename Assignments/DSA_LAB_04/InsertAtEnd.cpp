#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    int NEntries;
    Node *head = new Node;

    void CreateLL(int n_elements)
    {
        NEntries = n_elements;
        Node *temp = head;
        while (n_elements)
        {
            cin >> temp->data;
            if (n_elements == 1)
            {
                temp->next = NULL;
                break;
            }
            temp->next = new Node;
            temp = temp->next;
            n_elements--;
        }
    }
};

void printll(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

void InsertAtBeginning(Node **oldhead, int newdata)
{
    Node *temp = new Node;
    temp->data = newdata;
    temp->next = *oldhead;
    *oldhead = temp;
}

void Append(Node **head, int newdata)
{

    Node *NewNode = new Node;
    Node *last = *head;
    NewNode->data = newdata;
    NewNode->next = NULL;
    if (*head == NULL)
    {
        *head = NewNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = NewNode;
    return;
}

int main()
{
    int n, x;
    cin >> n >> x;
    LinkedList list;
    list.CreateLL(n);
    printll(list.head);
    Append(&list.head, x);
    cout << endl;
    printll(list.head);
    return 0;
}