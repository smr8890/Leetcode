#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {
    }

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {
    }

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};

class Solution {
public:
    Node *connect(Node *root) {
        if (root == NULL)
            return root;
        queue<Node *> queue;
        queue.push(root);
        int cnt = 1;
        while (!queue.empty()) {
            int temp = 0;
            for (int i = 0; i < cnt; ++i) {
                Node *p = queue.front();
                queue.pop();
                if (p->left != NULL) {
                    queue.push(p->left);
                    temp++;
                }
                if (p->right != NULL) {
                    queue.push(p->right);
                    temp++;
                }
                if (i < cnt - 1) {
                    p->next = queue.front();
                }
            }
            cnt = temp;
        }
        return root;
    }
};
