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

class Solution {
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)return false;
        queue<pair<TreeNode *, int> > queue;
        queue.push({root, root->val});
        while (!queue.empty()) {
            TreeNode *p = queue.front().first;
            int cur_sum = queue.front().second;
            queue.pop();
            if (p->left == nullptr && p->right == nullptr && cur_sum == targetSum)
                return true;
            if (p->left)queue.push({p->left, cur_sum + p->left->val});
            if (p->right)queue.push({p->right, cur_sum + p->right->val});
        }
        return false;
    }
};
