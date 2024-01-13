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
        Node *current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void printll()
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }

    void InsertAtBeginning(Node **oldhead, int newdata)
    {
        Node *temp = new Node;
        temp->data = newdata;
        temp->next = *oldhead;
        *oldhead = temp;
    }

    void InsertAtANode(int index, int newdata)
    {
        if (index == 0)
        {
            Node *temp = head;
            head = NULL;
            head = new Node;
            head->data = newdata;
            head->next = temp;
            cout << head->data << endl;
            return;
        }
        Node *temp = head;

        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        Node *NewNode = new Node;
        NewNode->data = newdata;
        NewNode->next = temp->next;
        temp->next = NewNode;
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

    void DeleteANode(int index)
    {
        Node *temp = head;
        if (index == 0)
        {
            head = head->next;
            delete (temp);
            return;
        }
        int l=0;
        for (Node* tempx=head; tempx!=NULL; tempx=tempx->next){l++;}
        if (index==l-1)
        {

            while((temp->next)->next!=NULL){
            temp=temp->next;
            }
            temp->next=NULL;
            return;
        }
        
        
        for (int i = 0; i < index - 1; i++)
        {

            temp = temp->next;
        }
        Node *temp1 = temp->next;
        temp->next = (temp->next)->next;
        delete temp1;
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
};

int main()
{
    int n, indextodelete;
    cin >> n;
    LinkedList list;
    list.CreateLL(n);
    cin >> indextodelete;
    list.DeleteANode(indextodelete);
    list.printll();
    return 0;
}