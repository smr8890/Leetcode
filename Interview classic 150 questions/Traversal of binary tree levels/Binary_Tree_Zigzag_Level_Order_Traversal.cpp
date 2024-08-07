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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root)return result;
        queue<TreeNode *> queue;
        queue.push(root);
        int cnt = 1, result_i = 0;
        while (!queue.empty()) {
            int temp = 0;
            result.resize(result_i + 1);
            for (int i = 0; i < cnt; ++i) {
                TreeNode *p = queue.front();
                queue.pop();
                if (result_i % 2) {
                    result[result_i].insert(result[result_i].begin(), p->val);
                } else {
                    result[result_i].push_back(p->val);
                }
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
