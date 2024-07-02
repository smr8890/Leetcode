#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int len = nums.size();
        int max_i = 0;
        for (int i = 0; i < len; ++i) {
            if (max_i >= i) {
                if (i + nums[i] > max_i) {
                    max_i = i + nums[i];
                }
            } else {
                break;
            }
        }
        if (max_i >= len - 1)
            return true;
        return false;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution mysolution;
    printf("%d", mysolution.canJump(nums));
    return 0;
}
