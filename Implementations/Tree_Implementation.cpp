#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int val)
    {
        data = val;
        left = right = NULL;
        height = 0;
    }
};

class BST
{
public:
    Node *root;
    Node *InsertNode(Node *root, int val);
    Node *insert(Node *root, int value);
    void preorderprint(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorderprint(root->left);
        preorderprint(root->right);
    }
    void CreateTree(int n_elements)
    {
        int x;
        while (n_elements--)
        {
            cin >> x;
            if (root == NULL)
            {
                root = new Node(x);
                continue;
            }

            Node *newnode = new Node(x);
            Node *temp = root;
            Node *temp_parent = NULL;

            while (temp != NULL)
            {
                temp_parent = temp;
                if (x > temp->data)
                {
                    temp = temp->right;
                }
                else
                {
                    temp = temp->left;
                }
            }
            if (x > temp_parent->data)
            {
                temp_parent->right = newnode;
            }
            else
                temp_parent->left = newnode;
        }
    }
    Node *LeftRotate();
    Node *RightRotate();

    void MakeBalanced();
};

Node *BST::InsertNode(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
    {
        root->left = InsertNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = InsertNode(root->right, val);
    }
    else
        return root;

    return root;
}

Node *BST::insert(Node *root, int value)
{
    Node *newnode = new Node(value);

    Node *curr = root;

    Node *prev = NULL;

    while (curr != NULL)
    {
        prev = curr;
        if (value < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    // If the prev is NULL it means that the tree is empty
    // The new node is the root node
    if (prev == NULL)
        prev = newnode;

    // if the new value is lesser than the leaf node
    // make the newNode as the left child of leaf node
    else if (value < prev->data)
        prev->left = newnode;

    // otherwise make the newNode as right child of leaf node
    else
        prev->right = newnode;
    return prev;
}

int main()
{
    BST tree;
    int n;
    cin >> n;
    tree.CreateTree(n);
    tree.preorderprint(tree.root);
}