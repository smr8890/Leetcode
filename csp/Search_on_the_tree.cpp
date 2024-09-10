#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int w;
    vector<TreeNode *> childs;

    TreeNode(): w(0), childs({}) {
    }

    TreeNode(int x): w(x), childs({}) {
    }
};

vector<TreeNode *> build(int n, int m) {
    vector<TreeNode *> tree_nodes;
    int w, p;
    for (int i = 0; i < n; ++i) {
        cin >> w;
        TreeNode *node = new TreeNode(w);
        tree_nodes.push_back(node);
    }
    for (int i = 1; i < n; ++i) {
        cin >> p;
        tree_nodes[p - 1]->childs.push_back(tree_nodes[i]);
    }
    return tree_nodes;
}

void recycle(vector<TreeNode *> &tree_nodes) {
    for (auto & tree_node : tree_nodes) {
        delete tree_node;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    /*vector<int> w(n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
    }*/

    vector<TreeNode *> tree_nodes = build(n, m);

    while (m--) {
        int target;
        cin>>target;
    }

    recycle(tree_nodes);
    return 0;
}
