#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LOG 1
#if LOG
#define print(x) cout << x << endl;
#else print(x)
#endif

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

    void ReverseLL(void)
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

    void printll(void)
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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
        if (index == 0) // delete head
        {
            head = head->next;
            delete (temp);
            return;
        }

        if (index == NEntries - 1) // delete tail
        {

            while ((temp->next)->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            return;
        }

        for (int i = 0; i < index - 1; i++) // delete in the middle
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

    /// @brief Gets data element from Linked List
    /// @param index : index of element in Linked List
    /// @return Value at index and also whether it was found or not
    Mila GetIFromLL(int index)
    {
        if (index < 0 && index > NEntries - 1)
            return Mila{0, 0}; // nahi mila
        int temp_next = 0;
        Node *temp = this->head;
        while (temp != NULL)
        {
            if (temp_next == index)
                return Mila{temp->data, 1};
            temp_next++;
            temp = temp->next;
        }
        return Mila{0, 0}; // nahi mila
    }

    /// @brief Checks whether a Linked List is Palindrome or not
    /// @return True if Linked List is Palindrome & False if Linked List is not palindrome
    bool isPalindrome()
    {
        if (head == nullptr)
            return 1;
        for (int i = 0; i < NEntries / 2; i++)
        {
            if (GetIFromLL(i).data != GetIFromLL(NEntries - i - 1).data)
            {
                return false;
            }
        }
        return true;
    }

    /// @brief Deletes the duplicate elements in a SORTED Linked List
    void DeleteDuplicates()
    {
        Node *curr = head;
        Node *curr_next = (head)->next;
        while (curr_next!=NULL)
        {
            if (curr_next->data == curr->data)
            {
                curr->next = curr_next->next;
                Node *node_to_delete = curr_next;
                curr_next = curr_next->next;
                free(node_to_delete);
            }
            else
            {
                curr_next = curr_next->next;
                curr = curr->next;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;

    LinkedList list1;

    list1.CreateLL(n);
    list1.DeleteDuplicates();
    list1.printll();
    return 0;
} 