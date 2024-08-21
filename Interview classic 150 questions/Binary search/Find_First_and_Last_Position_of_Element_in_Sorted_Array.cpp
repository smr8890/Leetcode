#include <vector>
using namespace std;

class Solution {
    int findLeft(vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    int findRight(vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int left = findLeft(nums, target), right = findRight(nums, target);
        if (left > right)return {-1, -1};
        return {left, right};
    }
};

int main() {
    vector<int> nums({5, 7, 7, 8, 8, 10});
    Solution my_solution;
    my_solution.searchRange(nums, 10);
    return 0;
}
