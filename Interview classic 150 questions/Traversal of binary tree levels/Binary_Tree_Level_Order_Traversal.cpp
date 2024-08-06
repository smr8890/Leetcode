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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == nullptr)return result;
        queue<TreeNode *> queue;
        queue.push(root);
        int cnt = 1, result_i = 0;
        while (!queue.empty()) {
            result.resize(result_i + 1);
            int temp = 0;
            for (int i = 0; i < cnt; ++i) {
                TreeNode *p = queue.front();
                queue.pop();
                result[result_i].push_back(p->val);
                if (p->left) {
                    queue.push(p->left);
                    temp++;
                }
                if (p->right) {
                    queue.push(p->right);
                    temp++;
                }
            }
            cnt = temp;
            result_i++;
        }
        return result;
    }
};
