#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int> > &board) {
        int n = board.size(), n2 = n * n;
        //二维数组转一维
        vector<int> _board;
        bool flag = true;
        for (int i = n - 1; i >= 0; --i) {
            if (flag) {
                for (int j = 0; j < n; ++j) {
                    _board.push_back(board[i][j]);
                }
                flag = false;
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    _board.push_back(board[i][j]);
                }
                flag = true;
            }
        }

        unordered_set<int> visited;
        queue<pair<int, int> > queue;
        queue.push({1, 0});
        visited.insert(1);
        while (!queue.empty()) {
            int cur = queue.front().first, step = queue.front().second;
            queue.pop();
            for (int i = 1; i <= 6; ++i) {
                int next = cur + i;
                if (next >= n2)return step + 1;
                if (visited.count(next)) {
                    continue;
                } else {
                    visited.insert(next);
                    if (_board[next - 1] != -1) {
                        next = _board[next - 1];
                        if (next == n2)return step + 1;
                        if (_board[next - 1] == -1) {
                            //只有当前节点不是传送节点时，才标记访问
                            visited.insert(next);
                        }
                    }
                    queue.push({next, step + 1});
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int> > test({{7, 8, 9}, {6, 5, 4}, {1, 2, 3}});
    Solution mysolution;
    mysolution.snakesAndLadders(test);
    return 0;
}
