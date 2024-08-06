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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> result;
        if (root == nullptr)return result;
        queue<TreeNode *> queue;
        queue.push(root);
        int cnt = 1;
        while (!queue.empty()) {
            int temp = 0;
            double sum = 0;
            for (int i = 0; i < cnt; ++i) {
                TreeNode *p = queue.front();
                queue.pop();
                sum += p->val;
                if (p->left) {
                    queue.push(p->left);
                    temp++;
                }
                if (p->right) {
                    queue.push(p->right);
                    temp++;
                }
            }
            result.push_back(sum / cnt);
            cnt = temp;
        }
        return result;
    }
};
