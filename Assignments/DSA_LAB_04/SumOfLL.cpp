#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

int Sum(node *head)
{
    int sum = 0;

    for (node *temp = head; temp != NULL; temp = temp->next)
    {
        sum += temp->data;
    }
    return sum;
}
class LinkedList
{
    int NEntries;
    node *head = new node;
public:

    void create(int n)
    {
        NEntries = n;
        node *temp = head;
        while (n)
        {
            cin >> temp->data;
            if (n == 1)
            {
                temp->next = NULL;
                break;
            }
            temp->next = new node;
            temp = temp->next;
            n--;
        }
    }
    int sum()
    {
        return Sum(this->head);
    }
};

int main()
{
    cout << "Enter the number of elements you want to have in the linked list: \n";
    int n;
    cin >> n;
    LinkedList list;
    list.create(n);
    cout << list.sum();
    return 0;
}
