#include <queue>
#include <vector>
using namespace std;

class Solution {
    void infect(vector<vector<char> > &board, int i, int j) {
        queue<pair<int, int> > queue;
        queue.push({i, j});
        while (!queue.empty()) {
            int a = queue.front().first, b = queue.front().second;
            queue.pop();
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] != 'O')
                continue;
            board[a][b] = 'Y';
            queue.push({a - 1, b});
            queue.push({a + 1, b});
            queue.push({a, b - 1});
            queue.push({a, b + 1});
        }
    }

public:
    void solve(vector<vector<char> > &board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                infect(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                infect(board, i, n - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O') {
                infect(board, 0, i);
            }
            if (board[m - 1][i] == 'O') {
                infect(board, m - 1, i);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
    }
};
