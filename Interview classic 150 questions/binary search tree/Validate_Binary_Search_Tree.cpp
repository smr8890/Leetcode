#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

class Solution {
    bool flag = true;
    long long int pre = LONG_LONG_MIN;

    void inorder(TreeNode *root) {
        if (root == nullptr || !flag)return;

        if (root->left)inorder(root->left);
        if (root->val <= pre)
            flag = false;
        pre = root->val;
        if (root->right)inorder(root->right);
    }

public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)return true;
        inorder(root);
        return flag;
    }
};
