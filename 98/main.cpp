#include <iostream>
#include <stack>

using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void treeTraverse(TreeNode *node, bool print)
{
    if (node->left)
        treeTraverse(node->left, print);
    if (print)
        cout << node->val << endl;
    if (node->right)
        treeTraverse(node->right, print);
}

void freeTree(TreeNode *node, TreeNode *root)
{
    if (node->left)
        freeTree(node->left, root);
    if (node->right)
        freeTree(node->right, root);
    delete node;
}

class Solution
{
    stack<int> s;

    bool traverse(TreeNode *root, TreeNode *parent, TreeNode *node)
    {
        if (!node)
            return true;
  
        if (node->left)
        {
            if (!traverse(root, node, node->left))
                return false;
        }
        if (s.size())
        {
            cout << "here: " << s.top() << " " << node->val << endl;
            if (s.top() >= node->val)
            {
                cout << "err: " << s.top() << " " << node->val << endl;
                return false;
            }
            else
            {
                s.pop();
                s.push(node->val);
            }
        }
        else
            s.push(node->val);

        cout << node->val << endl;

        if (node->right)
        {
            if (!traverse(root, node, node->right))
                return false;
        }
        return true;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return traverse(root, root, root);
    }
};

int main()
{
    TreeNode *tree = new TreeNode(5);
    tree->left = new TreeNode(1);
    tree->right = new TreeNode(4);
    tree->right->left = new TreeNode(3);
    tree->right->right = new TreeNode(8);

    treeTraverse(tree, true);
    cout << endl;

    Solution sol;

    if (sol.isValidBST(tree))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;

    cout << tree->val << endl;

    freeTree(tree, tree);    

    return 0;
}