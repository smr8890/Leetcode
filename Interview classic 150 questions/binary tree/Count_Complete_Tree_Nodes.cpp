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
    void preorder(TreeNode *root, int &n) {
        if (root == nullptr)return;
        n++;
        if (root->left)preorder(root->left, n);
        if (root->right)preorder(root->right, n);
    }

public:
    int countNodes(TreeNode *root) {
        int n = 0;
        preorder(root, n);
        return n;
    }
};

int main() {
    Solution mysolution;
    return 0;
}
