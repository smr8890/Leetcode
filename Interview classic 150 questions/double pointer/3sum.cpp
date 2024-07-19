#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        int len = nums.size();
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = len - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++, right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution mysolution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int> > result = mysolution.threeSum(nums);
    return 0;
}
