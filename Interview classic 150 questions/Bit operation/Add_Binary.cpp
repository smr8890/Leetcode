#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        string res;
        int flag = 0;
        while (i >= 0 || j >= 0) {
            int tmp = (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0) + flag;
            flag = tmp / 2;
            res += to_string(tmp % 2);
            i--;
            j--;
        }
        if (flag) {
            res += to_string(flag);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
