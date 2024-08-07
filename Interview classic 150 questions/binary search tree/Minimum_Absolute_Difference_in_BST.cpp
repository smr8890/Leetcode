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
    void inorder(TreeNode *root, int &pre, int &min) {
        if (root == nullptr)return;

        if (root->left)inorder(root->left, pre, min);
        int temp = root->val - pre;
        if (temp < min)min = temp;
        pre = root->val;
        if (root->right)inorder(root->right, pre, min);
    }

public:
    int getMinimumDifference(TreeNode *root) {
        if (!root)return 0;
        int pre = -100000, min = INT_MAX;
        inorder(root, pre, min);
        return min;
    }
};
