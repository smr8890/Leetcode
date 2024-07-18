#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.length()) {
            while (j < t.length()) {
                if (s[i] == t[j]) {
                    i++;
                    j++;
                } else {
                    j++;
                }
            }
            if (j == t.length())
                break;
        }
        if (i == s.length()) {
            return true;
        }
        return false;
    }
};
