#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h_len = haystack.length(), n_len = needle.length();
        for (int i = 0; i <= h_len - n_len; ++i) {
            int flag = 1;
            for (int j = 0; j < n_len; ++j) {
                if (haystack[i + j] != needle[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    string hay("a");
    string need("a");
    Solution mysolution;
    printf("%d", mysolution.strStr(hay, need));
    return 0;
}
