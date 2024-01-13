#include <bits/stdc++.h>
using namespace std;

typedef struct AnsFound
{
    int data;
    bool flag;
} Mila;

class Node
{
private:
    int data;
    Node *next;
    friend class LinkedList;
};

class LinkedList
{
private:
    int NEntries;
    Node *head = new Node;

public:
    void create(int n_elements)
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
    void reverse()
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

    void print()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push_front(Node **oldhead, int newdata)
    {
        Node *temp = new Node;
        temp->data = newdata;
        temp->next = *oldhead;
        *oldhead = temp;
    }

    void insert(int index, int newdata)
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

    void push_back(Node **head, int newdata)
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

    void delete_at(int index)
    {
        Node *temp = head;
        if (index == 0)
        {
            head = head->next;
            delete (temp);
            return;
        }

        if (index == NEntries - 1)
        {

            while ((temp->next)->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
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

        Node *temp = head;

        if (N > NEntries)
        {
            cout << -1 << endl;
            return;
        }

        temp = head;
        for (int i = 0; i != NEntries - N; i++, temp = temp->next)
        {
        }
        cout << temp->data << endl;
    }

    bool operator==(LinkedList &l1)
    {
        if (l1.NEntries != this->NEntries)
            return false;
        for (Node *temp1 = this->head, *temp2 = l1.head; temp1 != NULL && temp2 != NULL; temp1 = temp1->next, temp2 = temp2->next)
        {
            if (temp1->data != temp2->data)
                return false;
            // cout<<" temp1  "<<temp1->data<<' '<<"temp2   "<<temp2->data<<endl;
        }
        return true;
    }

    LinkedList operator=(LinkedList &list)
    {
        this->NEntries = list.NEntries;
        this->head = list.head;
        return *this;
    }

    /// @brief gives array-style functionality of reading the value data_at given index in a singly linked list
    /// @param index
    /// @return value data_at given index and also whether the value was found or not in the singly linked list
    int operator[](int index) noexcept
    {
        if (index < 0 && index > NEntries - 1)
            return INT_MIN;

        Node *temp = this->head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    Mila data_at(int index)
    {
        if (index < 0 && index > NEntries - 1)
            return Mila{INT_MIN, 0};
        int p = 0;
        Node *temp = this->head;
        while (temp != NULL)
        {
            if (p == index)
                return Mila{temp->data, 1};
            p++;
            temp = temp->next;
        }
        return Mila{INT_MIN, 0};
    }

    bool isPalindrome(void)
    {
        if (head == nullptr)
            return 1;
        for (int i = 0; i < NEntries / 2; i++)
        {
            if (data_at(i).data != data_at(NEntries - i - 1).data)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    int n;
    cin >> n;
    LinkedList list1;
    list1.create(n);
    list1.print();
    cout << list1.isPalindrome() << endl;
    return 0;
}