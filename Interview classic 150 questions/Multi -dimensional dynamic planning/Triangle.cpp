#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 1)return triangle[0][0];
        vector<vector<int> > dp(triangle.size(), vector<int>(triangle.size()));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            dp[i][0] = triangle[i][0] + dp[i - 1][0];
            for (int j = 1; j < triangle[i].size() - 1; ++j) {
                dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
            dp[i][triangle[i].size() - 1] = triangle[i][triangle[i].size() - 1] + dp[i - 1][triangle[i].size() - 2];
        }
        int mindp = dp[dp.size() - 1][0];
        for (int i = 0; i < dp.size(); ++i) {
            mindp = min(mindp, dp[dp.size() - 1][i]);
        }
        return mindp;
    }
};
