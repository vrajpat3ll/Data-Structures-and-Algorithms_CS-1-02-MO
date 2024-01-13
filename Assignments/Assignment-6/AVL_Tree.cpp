#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int key)
    {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

class AVLTree
{
public:
    Node *root;

    int getHeight(Node *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalanceFactor(Node *node)
    {
        if (node == NULL)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node *RightRotate(Node *node)
    {
        Node *y = node->left;
        Node *T2 = y->right;

        y->right = node;
        node->left = T2;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node *LeftRotate(Node *node)
    {
        Node *x = node->right;
        Node *T2 = x->left;

        x->left = node;
        node->right = T2;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node *insert(Node *node, int key)
    {
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; 

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1)
        {
            if (key < node->left->key)
                return RightRotate(node);
            else
            {
                node->left = LeftRotate(node->left);
                return RightRotate(node);
            }
        }

        if (balanceFactor < -1)
        {
            if (key > node->right->key)
                return LeftRotate(node);
            else
            {
                node->right = RightRotate(node->right);
                return LeftRotate(node);
            }
        }

        return node;
    }

    Node *MINnode(Node *node)
    {
        Node *temp = node;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }

    Node *deletenode(Node *node, int key)
    {
        if (node == NULL)
            return node;

        if (key < node->key)
            node->left = deletenode(node->left, key);
        else if (key > node->key)
            node->right = deletenode(node->right, key);
        else
        {
            if (node->left == NULL || node->right == NULL)
            {
                Node *temp = node->left ? node->left : node->right;
                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;
                delete temp;
            }
            else
            {
                Node *temp = MINnode(node->right);
                node->key = temp->key;
                node->right = deletenode(node->right, temp->key);
            }
        }

        if (node == NULL)
            return node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1)
        {
            if (getBalanceFactor(node->left) >= 0)
                return RightRotate(node);
            else
            {
                node->left = LeftRotate(node->left);
                return RightRotate(node);
            }
        }

        if (balanceFactor < -1)
        {
            if (getBalanceFactor(node->right) <= 0)
                return LeftRotate(node);
            else
            {
                node->right = RightRotate(node->right);
                return LeftRotate(node);
            }
        }

        return node;
    }

    void inorder(Node *node)
    {
        if (node != NULL)
        {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }

    void push(int key)
    {
        root = insert(root, key);
    }

    void pop(int key)
    {
        root = deletenode(root, key);
    }

    void printInOrder()
    {
        inorder(root);
    }
};

int main()
{
    AVLTree tree;
    int QueryType;
    int input;
    while (true)
    {

        cin >> QueryType;

        switch (QueryType)
        {
        case 1:
            cin >> input;
            tree.push(input);
            break;
        case 2:
            cin >> input;
            tree.pop(input);
            break;
        case 3:
            tree.printInOrder();
            cout << endl;
            break;
        case 4:
            return 0;
        }
    }

    return 0;
}