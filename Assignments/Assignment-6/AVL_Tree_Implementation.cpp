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
    node *left;
    node *right;
    int height;
    node(int in)
    {
        data = in;
        left = NULL;
        right = NULL;
        height = 0;
    }
};

void inorderfrom(node *root)
{
    if (root != NULL)
    {
        inorderfrom(root->left);
        cout << root->data << " ";
        inorderfrom(root->right);
    }
    else
        return;
}

class AVLTree
{
public:
    node *root;

    int height(node *root)
    {
        if (root)
            return max(height(root->left), height(root->right)) + 1;

        else
            return 0;
    }

    node *LeftLeft(node *root)
    {
        node *rootL = root->left;
        node *rootLR = rootL->right;
        rootL->right = root;
        root->left = rootLR;
        root->height = height(root);
        rootL->height = height(rootL);
        if (this->root == root)
        {
            root = rootL;
        }
        return rootL;
    }

    node *LeftRight(node *root)
    {
        node *rootL = root->left;
        node *rootLR = rootL->right;
        rootL->right = rootLR->left;
        root->left = rootLR->right;
        rootLR->left = rootL;
        rootLR->right = root;
        if (this->root == root)
        {
            this->root = rootLR;
        }
        root->height = height(root);
        rootL->height = height(rootL);
        rootLR->height = height(rootLR);
        return rootLR;
    }

    node *RightRight(node *root)
    {
        node *rootR = root->right;
        node *rootRL = rootR->left;
        rootR->left = root;
        root->right = rootRL;
        root->height = height(root);
        rootR->height = height(rootR);
        if (this->root == root)
        {
            root = rootR;
        }
        return rootR;
    }

    node *RightLeft(node *root)
    {
        node *rootR = root->right;
        node *rootRL = rootR->left;
        rootR->left = rootRL->right;
        root->right = rootRL->left;
        rootRL->left = root;
        rootRL->right = rootR;
        root->height = height(root);
        rootR->height = height(rootR);
        rootRL->height = height(rootRL);
        if (root == this->root)
        {
            root = rootRL;
        }
        return rootRL;
    }

    node *prec(node *root)
    {
        if (root && root->right)
        {
            root = root->right;
        }
        return root;
    }

    node *succ(node *root)
    {
        if (root && root->left)
        {
            root = root->left;
        }
        return root;
    }

    int BalanceFactor(node *root)
    {
        int a, b;
        a = (root && root->left) ? root->left->height : 0;
        b = (root && root->right) ? root->right->height : 0;
        return a - b;
    }
    node *insert(int input)
    {
        return insert(this->root, input);
    }

    node *insert(node *root, int val)
    {
        if (root == NULL)
        {
            root = new node(val);
            root->height = 1;
            return root;
        }
        if (root->data > val)
        {
            root->left = insert(root->left, val);
        }
        else
        {
            root->right = insert(root->right, val);
        }

        root->height = height(root);
        if (BalanceFactor(root) == 2 && BalanceFactor(root->left) == 1)
        {
            return (LeftLeft(root));
        }
        else if (BalanceFactor(root) == -2 && BalanceFactor(root->right) == -1)
        {
            return (RightRight(root));
        }
        else if (BalanceFactor(root) == -2 && BalanceFactor(root->right) == 1)
        {
            return (RightLeft(root));
        }
        else if (BalanceFactor(root) == 2 && BalanceFactor(root->left) == -1)
        {
            return (LeftRight(root));
        }
        return root;
    }

    node *deletenode(node *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->left == NULL && root->right == NULL && root->data == val)
        {
            free(root);
            return NULL;
        }
        if (root->data > val)
        {
            root->left = deletenode(root->left, val);
        }
        else if (root->data < val)
        {
            root->right = deletenode(root->right, val);
        }
        else
        {
            if (height(root->left) > height(root->right))
            {
                node *temp = prec(root->left);
                root->data = temp->data;
                root->left = deletenode(root->left, temp->data);
            }
            else
            {
                node *temp = succ(root->right);
                root->data = temp->data;
                root->right = deletenode(root->right, temp->data);
            }
        }
        root->height = height(root);
        if (BalanceFactor(root) == 2 && (BalanceFactor(root->left) == 1 || BalanceFactor(root->left) == 0))
        {
            return LeftLeft(root);
        }
        else if (BalanceFactor(root) == -2 && (BalanceFactor(root->right) == -1 || BalanceFactor(root->left) == 0))
        {
            return RightRight(root);
        }
        else if (BalanceFactor(root) == 2 && BalanceFactor(root->left) == -1)
        {
            return LeftRight(root);
        }
        else if (BalanceFactor(root) == -2 && BalanceFactor(root->right) == 1)
        {
            return RightLeft(root);
        }
        return root;
    }

    void inorder()
    {
        inorderfrom(this->root);
    }
};

int main()
{
    int QueryType;
    int input;
    AVLTree tree;

    while (true)
    {
        cin >> QueryType;
        switch (QueryType)
        {
        case 1:
            cin >> input;
            tree.insert(input);
            break;
        case 2:
            cin >> input;
            tree.deletenode(tree.root,input);
            break;
        case 3:
            tree.inorder();
            cout << endl;
            break;
        case 4:
            return 0;
        }
    }
}