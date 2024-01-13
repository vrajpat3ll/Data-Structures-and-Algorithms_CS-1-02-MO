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

    void Partition(int x)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data < x)
            {
                cout << temp->data << " ";
            }
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            if (temp->data >= x)
            {
                cout << temp->data << " ";
            }
            temp = temp->next;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    DoublyLinkedList list;
    list.CreateDLL(n);
    int x;
    cin >> x;
    list.Partition(x);
    return 0;
}