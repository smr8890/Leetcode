#include <queue>
#include <vector>
using namespace std;

class Solution {
    void infect(vector<vector<char> > &grid, int i, int j) {
        queue<pair<int, int> > queue;
        queue.push({i, j});
        while (!queue.empty()) {
            int a = queue.front().first, b = queue.front().second;
            queue.pop();
            if (a < 0 || a >= grid.size() || b < 0 || b >= grid[0].size() || grid[a][b] != '1')
                continue;
            grid[a][b] = '2';
            // if (a - 1 >= 0 && grid[a - 1][b] == '1')
            queue.push({a - 1, b});
            // if (a + 1 < grid.size() && grid[a + 1][b] == '1')
            queue.push({a + 1, b});
            // if (b - 1 >= 0 && grid[a][b - 1] == '1')
            queue.push({a, b - 1});
            // if (b + 1 < grid[0].size() && grid[a][b + 1] == '1')
            queue.push({a, b + 1});
        }
    }

public:
    int numIslands(vector<vector<char> > &grid) {
        int num = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    infect(grid, i, j);
                    num++;
                }
            }
        }
        return num;
    }
};
