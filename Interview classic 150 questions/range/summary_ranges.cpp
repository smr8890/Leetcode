#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        int len = nums.size();
        int left = 0, right = 1;
        while (left < len) {
            right = left + 1;
            while (right < len) {
                if (nums[right] == nums[right - 1] + 1) {
                    right++;
                } else
                    break;
            }
            if (right - left == 1) {
                result.emplace_back(to_string(nums[left]));
            } else {
                result.emplace_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
            }
            left = right;
        }
        return result;
    }
};
