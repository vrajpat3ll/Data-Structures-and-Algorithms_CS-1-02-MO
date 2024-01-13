#include <bits/stdc++.h>

using namespace std;

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
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }
    void topView(Node *root)
    {
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        map<int, int> Tmap;

        while (!q.empty())
        {
            Node *temp = q.front().first;
            int h_dist = q.front().second;
            q.pop();
            if (Tmap.find(h_dist) == Tmap.end())
                Tmap[h_dist] = temp->data;

            if (temp->left != NULL)
                q.push({temp->left, h_dist - 1});

            if (temp->right != NULL)
                q.push({temp->right, h_dist + 1});
        }

        auto iter = Tmap.begin();
        while (iter != Tmap.end())
        {
            cout << iter->second << " ";
            iter++;
        }
    }
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

    myTree.topView(root);
    return 0;
}
