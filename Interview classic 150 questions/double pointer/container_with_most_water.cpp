#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        int max_c = 0, capacity;
        int left = 0, right = n - 1;
        while (left < right) {
            capacity = (right - left) * min(height[left], height[right]);
            if (capacity > max_c) {
                max_c = capacity;
            }
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_c;
    }
};
