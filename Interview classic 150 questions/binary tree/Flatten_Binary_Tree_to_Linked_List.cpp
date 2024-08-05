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
public:
    TreeNode *pre = nullptr;

    void flatten(TreeNode *root) {
        if (root == nullptr)
            return;
        if (root->right != nullptr)flatten(root->right);
        if (root->left != nullptr)flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
};
