#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        int maxdp = 0, left = 0, right = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (i == j || j == i + 1) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (dp[i][j]) {
                    if (j - i + 1 > maxdp) {
                        maxdp = j - i + 1;
                        left = i;
                        right = j;
                    }
                }
            }
        }
        return s.substr(left, maxdp);
    }
};
