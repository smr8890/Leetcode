#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int len = nums.size();
        int current = 0, next_jump, max_next, count = 0;
        while (current < len - 1) {
            if (current + nums[current] >= len - 1) {
                count++;
                break;
            }
            max_next = 0;
            next_jump = current;
            for (int i = 1; i <= nums[current] && current + i < len; ++i) {
                int next = current + i + nums[current + i];
                if (next > max_next) {
                    max_next = next;
                    next_jump = current + i;
                }
            }
            current = next_jump;
            count++;
        }
        return count;
    }
};

int main() {
    Solution my_solution;
    vector<int> test = {2, 1};
    printf("%d", my_solution.jump(test));
    return 0;
}
