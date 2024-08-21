#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[nums.size() - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int min_index = left;
        if (target <= nums[nums.size() - 1]) {
            left = min_index;
            right = nums.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] < target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid - 1;
                } else {
                    return mid;
                }
            }
        } else {
            left = 0;
            right = min_index - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] < target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid - 1;
                } else {
                    return mid;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums({4, 5, 6, 7});
    Solution my_solution;
    my_solution.search(nums, 6);
    return 0;
}
