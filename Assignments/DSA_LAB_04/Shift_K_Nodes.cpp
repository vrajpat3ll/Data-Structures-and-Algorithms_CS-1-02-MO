#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;
};

class DoublyLinkedList
{
public:
    Node *head = new Node;
    int NElements;

    void CreateDLL(int n)
    {
        NElements = n;
        Node *temp = head;
        while (n)
        {
            cin >> temp->data;
            if (n == 1)
            {
                temp->next == NULL;
                temp->back = NULL;
                break;
            }
            temp->next = new Node;
            temp->next->back = temp;
            temp = temp->next;
            n--;
        }
    }

    void printDLL(void)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }

    void Shift(int k, int len)
    {
        if (k == 0 || len == 1 || k == len) return;
        
        int diff = len - k - 1;
        Node *temp = head;
        while (diff > 0)
        {
            temp = temp->next;
            diff--;
        }
        Node *NewNode = temp->next;
        Node *NewHead = temp->next;
        temp->next = NULL;
        NewNode->back = NULL;
        while (NewNode->next != NULL)
        {
            NewNode = NewNode->next;
        }
        NewNode->next = head;
        head->back = NewNode;
        head = NewHead;
    }
};

int main()
{
    int n; cin >> n;
    DoublyLinkedList list;
    list.CreateDLL(n);
    int k; cin >> k;
    list.Shift(k, n);
    list.printDLL();
    return 0;
}