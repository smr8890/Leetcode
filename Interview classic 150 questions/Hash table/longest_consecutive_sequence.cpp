#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set;
        unordered_set<int> used;
        for (auto num: nums) {
            set.insert(num);
        }
        int max_len = 0;
        for (auto num: nums) {
            if (!used.count(num)) {
                int temp = num;
                int temp_len = 0;
                while (set.count(temp)) {
                    temp_len++;
                    used.insert(temp);
                    temp++;
                }
                temp = num - 1;
                while (set.count(temp)) {
                    temp_len++;
                    used.insert(temp);
                    temp--;
                }
                if (temp_len > max_len) {
                    max_len = temp_len;
                }
            }
        }
        return max_len;
    }
};
