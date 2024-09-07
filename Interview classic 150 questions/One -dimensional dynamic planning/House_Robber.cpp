#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1)return nums[0];
        if (nums.size() == 2)return max(nums[0], nums[1]);
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = nums[1];
        int max_back = dp[0];
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = nums[i] + max_back;
            max_back = max(max_back, dp[i - 1]);
        }
        return max(max_back, dp[dp.size() - 1]);
    }
};
