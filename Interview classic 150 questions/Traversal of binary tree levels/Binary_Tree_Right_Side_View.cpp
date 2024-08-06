#include <queue>
#include <vector>
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if (root == nullptr)return result;
        queue<TreeNode *> queue;
        queue.push(root);
        int cnt = 1;
        while (!queue.empty()) {
            int temp = 0;
            for (int i = 0; i < cnt; ++i) {
                TreeNode *p = queue.front();
                queue.pop();
                if (p->left) {
                    queue.push(p->left);
                    temp++;
                }
                if (p->right) {
                    queue.push(p->right);
                    temp++;
                }
                if (i == cnt - 1)
                    result.push_back(p->val);
            }
            cnt = temp;
        }
        return result;
    }
};
