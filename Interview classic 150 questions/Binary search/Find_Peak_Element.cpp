#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        nums.insert(nums.begin(),INT_MIN);
        nums.push_back(INT_MIN);
        int left = 1, right = nums.size() - 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
