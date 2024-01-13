#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    int height;
    node(int x = 0)
    {
        data = x;
        left = NULL;
        right = NULL;
        height = 0;
    }
};

node *root = 0;
int height(node *temp)
{
    if (temp)
        return max(height(temp->left), height(temp->right)) + 1;

    else
        return 0;
}
node *LL(node *temp)
{
    node *tempL = temp->left;
    node *tempLR = tempL->right;
    tempL->right = temp;
    temp->left = tempLR;
    temp->height = height(temp);
    tempL->height = height(tempL);
    if (root == temp)
    {
        root = tempL;
    }
    return tempL;
}
node *RR(node *temp)
{
    node *tempR = temp->right;
    node *tempRL = tempR->left;
    tempR->left = temp;
    temp->right = tempRL;
    temp->height = height(temp);
    tempR->height = height(tempR);
    if (root == temp)
    {
        root = tempR;
    }
    return tempR;
}
node *LR(node *temp)
{
    node *tempL = temp->left;
    node *tempLR = tempL->right;
    tempL->right = tempLR->left;
    temp->left = tempLR->right;
    tempLR->left = tempL;
    tempLR->right = temp;
    if (root == temp)
    {
        root = tempLR;
    }
    temp->height = height(temp);
    tempL->height = height(tempL);
    tempLR->height = height(tempLR);
    return tempLR;
}
node *RL(node *temp)
{
    node *tempR = temp->right;
    node *tempRL = tempR->left;
    tempR->left = tempRL->right;
    temp->right = tempRL->left;
    tempRL->left = temp;
    tempRL->right = tempR;
    temp->height = height(temp);
    tempR->height = height(tempR);
    tempRL->height = height(tempRL);
    if (temp == root)
    {
        root = tempRL;
    }
    return tempRL;
}

int BalanceFactor(node *temp)
{
    if (temp)
        return height(temp->left) - height(temp->right);

    else
        return 0;
}

node *insert(node *temp, int in)
{
    if (temp == 0)
    {
        temp = new node(in);
        temp->height = 1;
        return temp;
    }
    if (temp->data > in)
    {
        temp->left = insert(temp->left, in);
    }
    else
    {
        temp->right = insert(temp->right, in);
    }

    temp->height = height(temp);
    if (BalanceFactor(temp) == 2 && BalanceFactor(temp->left) == 1)
    {
        return (LL(temp));
    }
    else if (BalanceFactor(temp) == -2 && BalanceFactor(temp->right) == -1)
    {
        return (RR(temp));
    }
    else if (BalanceFactor(temp) == -2 && BalanceFactor(temp->right) == 1)
    {
        return (RL(temp));
    }
    else if (BalanceFactor(temp) == 2 && BalanceFactor(temp->left) == -1)
    {
        return (LR(temp));
    }
    return temp;
}

void push(node **temp, int val)
{
    node *t = *temp;
    node *r = t;
    if (*temp == NULL)
    {
        *temp = new node(val);
    }
    else
    {
        while (t!=NULL)
        {
            if (t->data > val)
            {
                r = t;
                t = t->left;
            }
            else
            {
                r = t;
                t = t->right;
            }
        }
        node *nn = new node(val);
        if (r->data < val)
        {
            r->right = nn;
        }
        else
        {
            r->left = nn;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    root = insert(root, x);
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        insert(root, x);
    }

    cout << height(root);
}