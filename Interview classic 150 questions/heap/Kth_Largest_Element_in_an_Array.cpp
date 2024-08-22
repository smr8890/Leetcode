#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int> queue;
        for (auto num: nums) {
            queue.push(num);
        }
        while (k-- > 1) {
            queue.pop();
        }
        return queue.top();
    }
};
