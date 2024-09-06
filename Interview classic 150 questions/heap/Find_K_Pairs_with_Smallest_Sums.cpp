#include <iostream>
#include <ostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    struct node {
        int sum;
        int x, y;

        node() : sum(0), x(0), y(0) {
        }

        node(int val, int a, int b) : sum(val), x(a), y(b) {
        }

        bool operator <(const node &a) const {
            return sum > a.sum;
        }
    };

public:
    vector<vector<int> > kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<vector<int> > result;
        priority_queue<node> queue;

        for (int i = 0; i < nums1.size(); ++i) {
            queue.push(node(nums1[i] + nums2[0], i, 0));
        }

        while (!queue.empty() && k--) {
            auto top = queue.top();
            queue.pop();
            result.push_back({nums1[top.x], nums2[top.y]});
            if (top.y + 1 < nums2.size()) {
                queue.push(node(nums1[top.x] + nums2[top.y + 1], top.x, top.y + 1));
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    return 0;
}
