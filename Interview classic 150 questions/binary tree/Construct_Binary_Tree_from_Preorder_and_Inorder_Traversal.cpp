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
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &prei, int begin, int end) {
        if (begin > end)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[prei]);
        int rooti = begin;
        while (rooti <= end) {
            if (inorder[rooti] == preorder[prei])
                break;
            rooti++;
        }

        prei++;
        root->left = build(preorder, inorder, prei, begin, rooti - 1);
        root->right = build(preorder, inorder, prei, rooti + 1, end);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int prei = 0;
        return build(preorder, inorder, prei, 0, preorder.size() - 1);
    }
};
