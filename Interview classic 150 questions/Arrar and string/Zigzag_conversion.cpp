#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        vector<int> flag(len);
        int i = 0;
        while (i < len) {
            for (int j = 1; j <= numRows && i < len; ++j, ++i) {
                flag[i] = j;
            }
            for (int j = numRows - 1; j > 1 && i < len; --j, ++i) {
                flag[i] = j;
            }
        }
        string result;
        for (i = 1; i <= numRows; ++i) {
            for (int j = 0; j < len; ++j) {
                if (flag[j] == i) {
                    result.push_back(s[j]);
                }
            }
        }
        return result;
    }
};
