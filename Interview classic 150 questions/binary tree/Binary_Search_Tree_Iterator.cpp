#include <iostream>
#include <queue>
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

class BSTIterator {
    TreeNode *point = new TreeNode();

public:
    void inorder(TreeNode *root, queue<auto> &queue) {
        if (root == nullptr)return;
        inorder(root->left, queue);
        queue.push(root);
        inorder(root->right, queue);
    }

    BSTIterator(TreeNode *root) {
        queue<TreeNode *> queue;
        inorder(root, queue);
        TreeNode *p = point;
        while (!queue.empty()) {
            p->right = queue.front();
            p = p->right;
            queue.pop();
        }
        point = point->right;
    }

    int next() {
        int temp = point->val;
        point = point->right;
        return temp;
    }

    bool hasNext() {
        if (point)return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
