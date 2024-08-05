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
    int sumNumbers(TreeNode *root) {
        if (root == nullptr)return 0;
        queue<pair<TreeNode *, int> > queue;
        queue.push({root, root->val});
        int sum = 0;
        while (!queue.empty()) {
            TreeNode *p = queue.front().first;
            int cur_num = queue.front().second;
            queue.pop();
            if (p->left == nullptr && p->right == nullptr) {
                sum += cur_num;
            }
            if (p->left)queue.push({p->left, cur_num * 10 + p->left->val});
            if (p->right)queue.push({p->right, cur_num * 10 + p->right->val});
        }
        return sum;
    }
};
