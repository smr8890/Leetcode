#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
    Node *build(vector<vector<int> > &grid, int x, int y, int n) {
        if (n <= 0)return nullptr;

        for (int i = x; i < x + n; ++i) {
            for (int j = y; j < y + n; ++j) {
                if (grid[i][j] != grid[x][y]) {
                    Node *node = new Node(false, false, build(grid, x, y, n / 2), build(grid, x, y + n / 2, n / 2),
                                          build(grid, x + n / 2, y, n / 2), build(grid, x + n / 2, y + n / 2, n / 2));
                    return node;
                }
            }
        }
        Node *node = new Node(grid[x][y], true, nullptr, nullptr, nullptr, nullptr);
        return node;
    }

public:
    Node *construct(vector<vector<int> > &grid) {
        return build(grid, 0, 0, grid.size());
    }
};
