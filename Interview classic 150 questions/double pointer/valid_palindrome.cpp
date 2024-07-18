#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0;
        while (i < s.length()) {
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i]) >= '0' && s[i] <= '9')) {
                s.erase(s.begin() + i);
            } else {
                i++;
            }
        }
        for (int j = 0, k = s.length() - 1; j < s.length(); ++j, --k) {
            if (s[j] != s[k]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution mysolution;
    string s("0P");
    cout << mysolution.isPalindrome(s) << endl;
    return 0;
}
