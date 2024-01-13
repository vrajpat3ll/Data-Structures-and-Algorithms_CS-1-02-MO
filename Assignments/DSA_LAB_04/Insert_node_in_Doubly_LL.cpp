#include <bits/stdc++.h>
using namespace std;
/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
class DoublyLinkedListNode
{
private:
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode(int){}
    
};
DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *llist, int data)
{

    DoublyLinkedListNode *temp = llist;
    DoublyLinkedListNode *newdata = new DoublyLinkedListNode(data);
    if (temp->data >= data)
    {
        temp->prev = newdata;
        newdata->next = temp;
        return newdata;
    }
    while (temp != NULL)
    {
        if (temp->next == NULL && temp->data <= data)
        {
            temp->next = newdata;
            newdata->prev = temp;
            return llist;
        }
        else if (temp->data <= data && temp->next->data >= data)
        {
            newdata->next = temp->next;
            temp->next->prev = newdata;
            temp->next = newdata;
            newdata->prev = temp;
            return llist;
        }
        temp = temp->next;
    }
    return llist;
}