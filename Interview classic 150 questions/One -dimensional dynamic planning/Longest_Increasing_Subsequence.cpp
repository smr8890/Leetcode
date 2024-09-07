#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size());
        dp[0] = 1;
        int maxdp = 0;
        for (int i = 0; i < dp.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > maxdp)maxdp = dp[i];
        }
        return maxdp;
    }
};
