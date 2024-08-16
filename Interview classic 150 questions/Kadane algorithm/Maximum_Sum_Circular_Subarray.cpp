#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int n = nums.size();
        if (nums.size() == 1)return nums[0];
        vector<int> maxdp(nums.size()), mindp(nums.size());
        maxdp[0] = nums[0];
        mindp[0] = nums[0];
        int mx = nums[0], mn = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxdp[i] = max(nums[i], maxdp[i - 1] + nums[i]);
            mindp[i] = min(nums[i], mindp[i - 1] + nums[i]);
            mx = max(mx, maxdp[i]);
            mn = min(mn, mindp[i]);
            sum += nums[i];
        }
        return max(mx, sum - mn) == 0 ? mx : max(mx, sum - mn);
    }
};

int main() {
    vector<int> nums({5, -3, 5});
    Solution my_solution;
    my_solution.maxSubarraySumCircular(nums);
    return 0;
}
