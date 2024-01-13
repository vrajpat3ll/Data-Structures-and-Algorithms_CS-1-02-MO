#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node
{
    int ht;
    int val;
    node *left;
    node *right;
};
node *newnode(int input)
{
    node *nn = new node;
    nn->val = input;
    nn->left = NULL;
    nn->right = NULL;
    nn->ht = 0;
}
class SelfBalancingBinarySearchTree
{
private:
    node *root;

public:
    void insert(int input)
    {
        root = insert(root, input);
    }

    int ht(node *root)
    {
        return root == NULL ? -1 : root->ht;
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    node *insert(node *root, int input)
    {
        if (root == NULL)
            root = newnode(input);
        else if (input < root->val)
        {
            root->left = insert(root->left, input);
            if (ht(root->left) - ht(root->right) == 2)
                if (input < root->left->val)
                    root = rotateWithLeftChild(root);
                else
                    root = doubleWithLeftChild(root);
        }
        else if (input > root->val)
        {
            root->right = insert(root->right, input);
            if (ht(root->right) - ht(root->left) == 2)
                if (input > root->right->val)
                    root = rotateWithRightChild(root);
                else
                    root = doubleWithRightChild(root);
        }
        root->ht = max(ht(root->left), ht(root->right)) + 1;
        return root;
    }

    node *rotateWithLeftChild(node *k2)
    {
        node *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->ht = max(ht(k2->left), ht(k2->right)) + 1;
        k1->ht = max(ht(k1->left), k2->ht) + 1;
        return k1;
    }

    node *rotateWithRightChild(node *k1)
    {
        node *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->ht = max(ht(k1->left), ht(k1->right)) + 1;
        k2->ht = max(ht(k2->right), k1->ht) + 1;
        return k2;
    }

    node *doubleWithLeftChild(node *k3)
    {
        k3->left = rotateWithRightChild(k3->left);
        return rotateWithLeftChild(k3);
    }

    node *doubleWithRightChild(node *k1)
    {
        k1->right = rotateWithLeftChild(k1->right);
        return rotateWithRightChild(k1);
    }

    int countNodes()
    {
        return countNodes(this->root);
    }

    int countNodes(node *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            int count = 1;
            count += countNodes(root->left);
            count += countNodes(root->right);
            return count;
        }
    }

    bool search(int val)
    {
        return search(root, val);
    }

    bool search(node *root, int val)
    {
        bool found = false;
        while ((root != NULL) && !found)
        {
            int rval = root->val;
            if (val < rval)
                root = root->left;
            else if (val > rval)
                root = root->right;
            else
            {
                found = true;
                break;
            }
            found = search(root, val);
        }
        return found;
    }

    void inorder()
    {
        inorder(this->root);
    }

    void inorder(node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->val << "  ";
            inorder(root->right);
        }
    }
};

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */
int height(node *root)
{
    if (root != NULL)
        return max(height(root->left), height(root->right)) + 1;

    else
        return -1;
}

node *LeftRight(node *root)
{
    node *rootL = root->left;
    node *rootLR = rootL->right;
    rootL->right = rootLR->left;
    root->left = rootLR->right;
    rootLR->left = rootL;
    rootLR->right = root;
    root->ht = height(root);
    rootL->ht = height(rootL);
    rootLR->ht = height(rootLR);
    return rootLR;
}

node *LeftLeft(node *root)
{
    node *rootL = root->left;
    node *rootLR = rootL->right;
    rootL->right = root;
    root->left = rootLR;
    root->ht = height(root);
    rootL->ht = height(rootL);
    return rootL;
}

node *RightLeft(node *root)
{
    node *rootR = root->right;
    node *rootRL = rootR->left;
    rootR->left = rootRL->right;
    root->right = rootRL->left;
    rootRL->left = root;
    rootRL->right = rootR;
    root->ht = height(root);
    rootR->ht = height(rootR);
    rootRL->ht = height(rootRL);
    return rootRL;
}

node *RightRight(node *root)
{
    node *rootR = root->right;
    node *rootRL = rootR->left;
    rootR->left = root;
    root->right = rootRL;
    root->ht = height(root);
    rootR->ht = height(rootR);
    return rootR;
}

int balanceFactor(node *root)
{
    if (root != NULL)
        return height(root->left) - height(root->right);

    else
        return 0;
}

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        root = new node;
        root->val = val;
        root->ht = 0;
        return root;
    }
    if (root->val > val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    root->ht = height(root);
    if (balanceFactor(root) == 2 && balanceFactor(root->left) == 1)
    {
        return (LeftLeft(root));
    }
    else if (balanceFactor(root) == -2 && balanceFactor(root->right) == -1)
    {
        return (RightRight(root));
    }
    else if (balanceFactor(root) == -2 && balanceFactor(root->right) == 1)
    {
        return (RightLeft(root));
    }
    else if (balanceFactor(root) == 2 && balanceFactor(root->left) == -1)
    {
        return (LeftRight(root));
    }
    return root;
}