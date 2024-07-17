#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int len = strs.size();
        if (len == 1) {
            return strs[0];
        }
        string result = strs[0];
        for (int i = 1; i < len; ++i) {
            int s_len = strs[i].length(), r_len = result.length();
            string temp;
            for (int j = 0; j < s_len && j < r_len; ++j) {
                if (strs[i][j] == result[j]) {
                    temp.push_back(result[j]);
                } else {
                    break;
                }
            }
            result=temp;
        }
        return result;
    }
};
