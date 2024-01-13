/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

bool bst(Node *root, Node *MIN = NULL, Node *MAX = NULL)
{
    if (root == NULL)
        return true;

    if (MIN != NULL && root->data <= MIN->data)
        return false;

    if (MAX != NULL && root->data >= MAX->data)
        return false;

    bool isLeftbst = bst(root->left, MIN, root), isRightbst = bst(root->right, root, MAX);

    return (isLeftbst && isRightbst);
}

bool checkBST(Node *root)
{
    return bst(root,NULL,NULL);
}
