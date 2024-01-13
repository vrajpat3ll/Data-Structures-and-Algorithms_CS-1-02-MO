#include <bits/stdc++.h>
using std::cin, std::cout;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int x)
    {
        data = x;
        next = NULL;
    }

    Node(int x, Node *nextt)
    {
        data = x;
        next = nextt;
    }
};

class LinkedList
{
    int NEntries;
    Node *head = new Node();

public:
    int elements() { return this->NEntries; }

    /// @brief creates the linked list
    /// @param N : number of elements in the singly linked list
    void create(int N)
    {
        this->NEntries = N;
        if (N == 0)
        {
            this->head = NULL;
            return;
        }

        Node *temp = this->head;
        while (N)
        {
            cout << "Enter the data: ";
            cin >> temp->data;
            if (N == 1)
            {
                temp->next = NULL;
                return;
            }
            temp->next = new Node();
            temp = temp->next;
            N--;
        }
        return;
    }

    /// @brief reverses the singly linked list
    /// @return head of the singly linked list after reversal
    Node *reverse(void)
    {
        Node *current = this->head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        this->head = prev;
        return head;
    }

    /// @brief prints the data in the list
    void print(void)
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    /// @brief gives array-style functionality of reading the value at given index in a singly linked list (indexing is 0-based)
    /// @param index
    /// @return value at that index in the singly linked list
    int operator[](int index) noexcept
    {
        if (index < 0 && index >= NEntries)
            return INT_MIN;

        Node *temp = this->head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    ///@brief DOES NOT CREATE A COPY
    ///@param JUST CAN BE USED AS A ALIAS
    ///@return SO, NOT USEFUL
    LinkedList operator=(LinkedList LL)
    {
        this->NEntries = LL.NEntries;
        this->head = LL.head;
        return *this;
    }
    /// @brief inserts a value in the singly linked list at an index position
    /// @param value: value to be inserted
    /// @param index: index of insertion
    /// @return head of the list after insertion
    Node *insert(int value, int index)
    {
        if (index == 0)
        {
            Node *temp = new Node(value);
            temp->next = this->head;
            this->head = temp;
            return this->head;
        }
        Node *temp = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        Node *nn = new Node(value);
        nn->next = temp->next;
        temp->next = nn;
        return this->head;
    }

    int deletenode(int index)
    {
        int DELETED;
        Node *temp = head;
        if (index == 0)
        {
            DELETED = head->data;
            head = head->next;
            delete (temp);
            return DELETED;
        }
        int l = 0;
        for (Node *tempx = head; tempx != NULL; tempx = tempx->next)
        {
            l++;
        }
        if (index == l - 1)
        {

            while ((temp->next)->next != NULL)
            {
                temp = temp->next;
            }
            DELETED = temp->data;
            temp->next = NULL;
            return DELETED;
        }

        if (index <= l)
        {
            for (int i = 0; i < index - 1; i++)
            {

                temp = temp->next;
            }

            Node *temp1 = temp->next;
            DELETED = temp1->data;
            temp->next = (temp->next)->next;
            delete temp1;
            return DELETED;
        }
        return INT_MAX;
    }

    bool isPalindrome()
    {
        LinkedList l = *this;
        for (int i = 0; i < NEntries; i++)
        {
            if (l[i] != l[NEntries - i - 1])
                return false;
        }
        return true;
    }

    bool hasCycle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            if (slow == fast)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

int main()
{
    cout << std::setw(50) << "Linked list generator:\n\n\n\n";
    int N_ELEMENTS, CASE;

    cout << "Enter the number of elements to enter: ";
    cin >> N_ELEMENTS;

    LinkedList list;
    list.create(N_ELEMENTS);

    cout << "\n\n";
    list.print();
    cout << "\n\n";

    while (true)
    {
        cout << "Enter option number to operate:\n"
             << "   1. Print the list.\n"
             << "   2. Add an element to the list.\n"
             << "   3. Delete an element from the list.\n"
             << "   4. Check if the list has a cycle or not.\n"
             << "   5. Reverse the list and print the list.\n"
             << "   6. Check if the list is a palindrome.\n"
             << "   7. Exit the program.\n\n";
        cin >> CASE;
        int value, index;

        switch (CASE)
        {
            index = -1;
        case 1:
            list.print();
            cout << '\n';
            break;
        case 2:
            if (index < 0 || index >= list.elements())
            {
                cout << "\nEnter the index [0-" << list.elements() - 1 << "] for insertion: ";
                cin >> index;
            }
            cout << "\nEnter the value to insert: ";
            cin >> value;
            list.insert(value, index);
            list.print();
            cout << '\n';
            break;
        case 3:
            if (index < 0 || index >= list.elements())
            {
                cout << "\nEnter the index [0-" << list.elements() - 1 << "] of the element you want to delete: ";
                cin >> index;
            }
            list.deletenode(index);
            list.print();
            cout << '\n';
            break;
        case 4:
            if (list.hasCycle())
                cout << "\nHas a cycle.\n\n";
            else
                cout << "\nDoes not have a cycle.\n\n";
            break;
        case 5:
            list.reverse();
            list.print();
            cout << '\n';
            break;
        case 6:
            if (list.isPalindrome())
                cout << "\nList is a palindrome.\n\n";
            else
                cout << "\nList is not a palindrome.\n\n";
            break;
        case 7:
            goto exit;
            break;

        default:
            cout << "Enter a valid option.\n\n";
            break;
        }
    }
exit:
    return 0;
}