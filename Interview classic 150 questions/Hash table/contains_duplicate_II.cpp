#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int len = nums.size();
        unordered_set<int> set;
        int left = 0, right = 0;
        while (left < len) {
            while (right - left <= k && right < len) {
                if (set.count(nums[right])) {
                    return true;
                }
                set.insert(nums[right]);
                right++;
            }
            set.erase(nums[left]);
            left++;
        }
        return false;
    }
};
