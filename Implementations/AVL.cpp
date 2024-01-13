#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;
    int ht;
    // node(int x)
    // {
    //     val=x;
    //     ht=0;
    //     left=NULL;
    //     right=NULL;
    // }
};
class AVLTree
{
public:
int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->ht;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

node *newnode(int val)
{
    node *nn =new node;
    nn->left=NULL;
    nn->right=NULL;
    nn->ht = 1;
    return (nn);
}
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->ht = max(height(y->left),
                    height(y->right)) +
                1;
    x->ht = max(height(x->left),
                    height(x->right)) +
                1;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->ht = max(height(x->left),
                    height(x->right)) +
                1;
    y->ht = max(height(y->left),
                    height(y->right)) +
                1;

    return y;
}

int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node *insert(node *node, int val)
{
    if (node == NULL)
        return (newnode(val));

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else
        return node;

    node->ht = 1 + max(height(node->left),
                            height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && val < node->left->val)
        return rightRotate(node);

    if (balance < -1 && val > node->right->val)
        return leftRotate(node);

    if (balance > 1 && val > node->left->val)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && val < node->right->val)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
    void updateHeight(node *node) {
    if (node == nullptr)
        return;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->ht = 1 + max(leftHeight, rightHeight);
}

    // node *deleteNode(node *root, int val)
    // {
    //     if (root == nullptr)
    //         return root;

    //     if (val < root->val)
    //         root->left = deleteNode(root->left, val);
    //     else if (val > root->val)
    //         root->right = deleteNode(root->right, val);
    //     else
    //     {
    //         if (root->left == nullptr || root->right == nullptr)
    //         {
    //             node *temp = root->left ? root->left : root->right;
    //             delete root;
    //             return temp;
    //         }

    //         node *temp ;/////////////////////////= minValueNode(root->right);
    //         root->val = temp->val;
    //         root->right = deleteNode(root->right, temp->val);
    //     }

    //     updateHeight(root);

    //     int balance = getBalance(root);

    //     // Left Left Case
    //     if (balance > 1 && getBalance(root->left) >= 0)
    //         return rightRotate(root);

    //     // Left Right Case
    //     if (balance > 1 && getBalance(root->left) < 0)
    //     {
    //         root->left = leftRotate(root->left);
    //         return rightRotate(root);
    //     }

    //     // Right Right Case
    //     if (balance < -1 && getBalance(root->right) <= 0)
    //         return leftRotate(root);

    //     // Right Left Case
    //     if (balance < -1 && getBalance(root->right) > 0)
    //     {
    //         root->right = rightRotate(root->right);
    //         return leftRotate(root);
    //     }

    //     return root;
    // }
};