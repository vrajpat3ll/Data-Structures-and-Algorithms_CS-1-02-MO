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
     void ReverseLL()
    {
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void print(){
        printll(this->head);
    }
    Node* insert(int value,int index){
        if (index==0)
        {
            return InsertAtBeginning(&(this->head),value);
        }
        if(index==NEntries-1)
        {
            return Append(&(this->head),value);
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

Node* InsertAtBeginning(Node **oldhead, int newdata)
{
    Node *temp = new Node;
    temp->data = newdata;
    temp->next = *oldhead;
    *oldhead = temp;
    return *oldhead;
}

Node* Append(Node **head, int newdata)
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
    return *head;
}

void Print_N_thNodeFromLast(Node *head, int N)
{
    int l = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    if (N > l)
    {
        cout << -1 << endl;
        return;
    }

    temp = head;
    for (int i = 0; i != l - N; i++, temp = temp->next)
    {
    }
    cout << temp->data << endl;
}

int main()
{
    int n;
    cin >> n;
    LinkedList list;
    list.CreateLL(n);
    list.ReverseLL();
    printll(list.head);
    return 0;
}