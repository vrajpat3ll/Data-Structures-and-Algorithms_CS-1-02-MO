#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    /// @brief Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
    /// @brief Constructor with value input
    /// @param x : value to be stored in the node
    Node(int x)
    {
        data = x;
        next = NULL;
    }
    /// @brief Parametrized constructor with value as well as address input
    /// @param x :value to be stored
    /// @param nn : address where the value is to be stored
    Node(int x, Node *nn)
    {
        data = x;
        next = nn;
    }
};

/// @brief prints the data present in the connected nodes
/// @param node: address of the initial node
void printlist(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

void InsertAtBeginning(Node **oldhead, int newdata)
{
    Node *temp = new Node(newdata, *oldhead);
    *oldhead = temp;
}

/// @brief linked list data structure 
class LinkedList
{
public:
    int NEntries;
    Node *head = new Node();

    int create(int n_elements)
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
            temp->next = new Node();
            temp = temp->next;
            n_elements--;
        }
        return n_elements;
    }
    void print()
    {
        printlist(this->head);
    }
    
    Node *push_front(int value)
    {
        InsertAtBeginning(&this->head, value);
        return this->head;
    }
};

int main()
{
    int n, x;
    cin >> n >> x;
    LinkedList list;
    list.create(n);
    list.print();
    list.push_front(x);
    cout << endl;
    list.print();
    return 0;
}