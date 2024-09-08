#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> > &matrix) {
        vector<vector<int> > dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        int maxdp = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size(); ++j) {
                if (matrix[i-1][j-1]=='1') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                maxdp = max(maxdp, dp[i][j]);
            }
        }
        return maxdp * maxdp;
    }
};
