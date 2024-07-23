#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<char> st;
        for (int i = 0; i < len; ++i) {
            switch (s[i]) {
                case '(': {
                    st.push(s[i]);
                    break;
                }
                case ')': {
                    if (st.empty() || st.top() != '(')
                        return false;
                    st.pop();
                    break;
                }
                case '{': {
                    st.push(s[i]);
                    break;
                }
                case '}': {
                    if (st.empty() || st.top() != '{')
                        return false;
                    st.pop();
                    break;
                }
                case '[': {
                    st.push(s[i]);
                    break;
                }
                case ']': {
                    if (st.empty() || st.top() != '[')
                        return false;
                    st.pop();
                    break;
                }
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};

int main() {
    string s("([)]");
    Solution mysolution;
    cout << mysolution.isValid(s) << endl;
    return 0;
}
