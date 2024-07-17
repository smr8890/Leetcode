#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int s_len = 0, flag = 0;
        int i = len - 1;
        while (s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            s_len++;
            i--;
        }
        return s_len;
    }
};

int main() {
    Solution mysolution;
    string s("a");
    cout << mysolution.lengthOfLastWord(s) << endl;
}
