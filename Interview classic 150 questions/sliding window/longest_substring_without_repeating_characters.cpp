#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_set<char> set;
        int max_len = 0;
        int left = 0, right = 0;
        for (left = 0; left < len; left++) {
            while (!set.count(s[right]) && right < len) {
                set.insert(s[right]);
                right++;
            }
            int temp_len = right - left;
            if (temp_len > max_len) {
                max_len = temp_len;
            }
            set.erase(s[left]);
        }
        return max_len;
    }
};
