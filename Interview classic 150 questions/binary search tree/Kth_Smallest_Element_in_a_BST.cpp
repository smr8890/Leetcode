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
    void inorder(TreeNode *root, int &count, int k, int &result) {
        if (root == nullptr || count > k)return;

        if (root->left)inorder(root->left, count, k, result);
        if (count == k) {
            result = root->val;
        }
        count++;
        if (root->right)inorder(root->right, count, k, result);
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        if (!root)return -1;
        int count = 1, result;
        inorder(root, count, k, result);
        return result;
    }
};
