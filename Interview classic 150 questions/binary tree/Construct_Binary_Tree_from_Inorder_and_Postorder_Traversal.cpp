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
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int &post_i, int begin, int end) {
        if (begin > end)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[post_i]);
        int rooti = begin;
        while (rooti <= end) {
            if (inorder[rooti] == postorder[post_i])
                break;
            rooti++;
        }
        post_i--;
        root->right = build(inorder, postorder, post_i, rooti + 1, end);
        root->left = build(inorder, postorder, post_i, begin, rooti - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int post_i = postorder.size() - 1;
        return build(inorder, postorder, post_i, 0, postorder.size() - 1);
    }
};
