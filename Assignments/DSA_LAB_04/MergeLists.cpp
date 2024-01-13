#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void Append(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;

    return;
}

Node *MergeLists(Node *list1, Node *list2)
{
    Node *h3 = NULL;
    Node *temp1 = list1;
    Node *temp2 = list2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            Append(&h3, temp2->data);
            temp2 = temp2->next;
        }
        else
        {
            Append(&h3, temp1->data);
            temp1 = temp1->next;
        }
    }

    while (temp1 != NULL)
    {
        Append(&h3, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        Append(&h3, temp2->data);
        temp2 = temp2->next;
    }
    return h3;
}

int main()
{
    int n, m, p;
    Node *head = new Node();
    Node *head1 = new Node();
    Node *head2 = new Node();

    head = NULL;
    head1 = NULL;
    head2 = NULL;

    cin >> n;

    for (int i = 0; i < n; i++)
    {

        cin >> p;
        Append(&head, p);
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {

        cin >> p;
        Append(&head1, p);
    }

    head2 = MergeLists(head, head1);
    print(head2);

    return 0;
}