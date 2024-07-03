#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = nums.size();
        vector<int> before(len);
        vector<int> after(len);
        vector<int> answer(len);
        before[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            before[i] = before[i - 1] * nums[i];
        }
        after[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; --i) {
            after[i] = after[i + 1] * nums[i];
        }
        answer[0] = after[1];
        for (int i = 1; i < len - 1; ++i) {
            answer[i] = before[i - 1] * after[i + 1];
        }
        answer[len - 1] = before[len - 2];
        return answer;
    }
};
