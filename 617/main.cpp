#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void addNodes(TreeNode * res, TreeNode* node1, TreeNode* node2) {
        if (node1->left && node2->left) {
            res->left = new TreeNode(node1->left->val + node2->left->val);
            addNodes(res->left, node1->left, node2->left);
        }
        if (node1->right && node2->right) {
            res->right = new TreeNode(node1->right->val + node2->right->val);
            addNodes(res->right, node1->right, node2->right);
        }
        if (node1->left && !node2->left) {
            TreeNode * newNode = new TreeNode();
            newNode = node1->left;
            res->left = newNode;
        }
        if (!node1->left && node2->left) {
            TreeNode * newNode = new TreeNode();
            newNode = node2->left;
            res->left = newNode;
        }
        if (node1->right && !node2->right) {
            TreeNode * newNode = new TreeNode();
            newNode = node1->right;
            res->right = newNode;
        }
        if (!node1->right && node2->right) {
            TreeNode * newNode = new TreeNode();
            newNode = node2->right;
            res->right = newNode;
        }
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 || !t2) {
            if (t1)
                return new TreeNode(t1->val);
            else if (t2)
                return new TreeNode(t2->val);
            return nullptr;
        }
        TreeNode* sol = new TreeNode(t1->val + t2->val);
        addNodes(sol, t1, t2);
        return sol;
    }
};

void freeTree(TreeNode *node, TreeNode *root)
{
    if (node->left)
        freeTree(node->left, root);
    if (node->right)
        freeTree(node->right, root);
    delete node;
}

int main() {
    TreeNode * node11 = new TreeNode(1);
    TreeNode * node12 = new TreeNode(1);
    TreeNode * node13 = new TreeNode(1);
    TreeNode * node14 = new TreeNode(1);
    TreeNode * node15 = new TreeNode(1);
    TreeNode * node16 = new TreeNode(1);

    TreeNode * node21 = new TreeNode(1);
    TreeNode * node22 = new TreeNode(2);
    TreeNode * node23 = new TreeNode(3);
    TreeNode * node24 = new TreeNode(4);
    TreeNode * node25 = new TreeNode(5);
    TreeNode * node26 = new TreeNode(6);

    TreeNode * tree1 = new TreeNode();
    tree1->left = node11;
    tree1->right = node12;
    tree1->left->left = node13;
    tree1->left->right = node14;
    tree1->right->left = node15;
    tree1->right->right = node16;

    TreeNode * tree2 = new TreeNode();
    tree2->left = node21;
    tree2->right = node22;
    tree2->left->left = node23;
    tree2->left->right = node24;
    tree2->right->left = node25;
    tree2->right->right = node26;

    freeTree(tree1, tree1);
    freeTree(tree2, tree2);

    return 0;
}