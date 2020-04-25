#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void getLeafNum(TreeNode *root, TreeNode *node, vector<string> &s_vec, string &s)
{
    if (root == nullptr)
        return;
    else if (!root->left && !root->right)
    {
        s_vec.push_back(to_string(root->val));
        return;
    }
    s += to_string(node->val);
    if (node->left)
    {
        getLeafNum(root, node->left, s_vec, s);
        s.pop_back();
    }
    if (root == node)
        s = to_string(root->val);
    if (node->right)
    {
        getLeafNum(root, node->right, s_vec, s);
        s.pop_back();
    }
    if (root != node && !node->left && !node->right)
    {
        s_vec.push_back(s);
        //s.pop_back();
    }
}

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int res = 0;

        vector<string> vec;
        string s;
        getLeafNum(root, root, vec, s);

        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec.at(i) << endl;
            res += stoi(vec.at(i));
        }

        return res;
    }
};

void clearTree(TreeNode *root)
{
    if (root->left)
        clearTree(root->left);
    if (root->right)
        clearTree(root->right);
    delete (root);
}

int main()
{
    TreeNode *tree = new TreeNode(6);
    tree->left = new TreeNode(8);
    tree->left->left = new TreeNode(7);
    tree->left->right = new TreeNode(3);
    tree->left->left->left = new TreeNode(8);

    Solution sol;

    cout << sol.sumNumbers(tree) << endl;

    clearTree(tree);

    return 0;
}