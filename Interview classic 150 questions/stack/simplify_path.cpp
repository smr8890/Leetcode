#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    void Stringsplit(string str, const char split, vector<string> &res) {
        istringstream iss(str);
        string token;
        while (getline(iss, token, split)) {
            res.push_back(token);
        }
    }

    string simplifyPath(string path) {
        string simplified_path;
        vector<string> strs;
        Stringsplit(path, '/', strs);
        stack<string> stack;
        for (auto str: strs) {
            if (str == "." || str.empty()) {
            } else if (str == "..") {
                if (!stack.empty()) {
                    stack.pop();
                }
            } else {
                stack.push(str);
            }
        }
        while (!stack.empty()) {
            simplified_path.insert(0, "/" + stack.top());
            stack.pop();
        }
        if (simplified_path.empty())
            simplified_path.append("/");
        return simplified_path;
    }
};

int main() {
    string path("/a/./b/../../c/");
    Solution mysolution;
    mysolution.simplifyPath(path);
    return 0;
}
