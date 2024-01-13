//https://www.hackerrank.com/contests/trees-assignment-6-ug22/challenges/binary-search-tree-insertion

#include <iostream>
#include <cstddef>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void preOrder(Node *root)
    {

        if (root == NULL)
            return;

        std::cout << root->data << " ";

        preOrder(root->left);
        preOrder(root->right);
    }
    Node *insert(Node *root, int data)    // Node *insert(Node *root, int data)
    {                                     //{
        Node *nn = new Node(data);
        if (!root)
        {
            root = nn;
            return root;
        }
        Node *prev = NULL;
        Node *temp = root;
        while (temp)
        {
            if (temp->data > data)
            {
                prev = temp;
                temp = temp->left;
            }
            else if (temp->data < data)
            {
                prev = temp;
                temp = temp->right;
            }
        }
        if (prev->data > data)
            prev->left = nn;
        else
            prev->right = nn;
        return root;
    }
    //     if (root == NULL)
    //     {
    //         return new Node(data);
    //     }
    //     else
    //     {
    //         Node *cur;
    //         if (data <= root->data)
    //         {
    //             cur = insert(root->left, data);
    //             root->left = cur;
    //         }
    //         else
    //         {
    //             cur = insert(root->right, data);
    //             root->right = cur;
    //         }
    //
    //         return root;
    //     }
    // }
}; // End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    myTree.preOrder(root);
    return 0;
}
