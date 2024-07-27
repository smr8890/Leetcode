#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    void removeSpace(string &s) {
        int i = 0;
        while (i < s.length()) {
            if (s[i] == ' ') {
                s.erase(s.begin() + i);
            } else {
                i++;
            }
        }
    }

    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        for (auto token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                switch (token[0]) {
                    case '+': {
                        stack.push(a + b);
                        break;
                    }
                    case '-': {
                        stack.push(a - b);
                        break;
                    }
                    case '*': {
                        stack.push(a * b);
                        break;
                    }
                    case '/': {
                        stack.push(a / b);
                        break;
                    }
                }
            } else {
                int num = 0;
                istringstream ss(token);
                ss >> num;
                stack.push(num);
            }
        }
        return stack.top();
    }

    int calculate(string s) {
        removeSpace(s);
        vector<string> tokens;
        stack<string> stack;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stack.push("(");
            } else if (s[i] == ')') {
                while (stack.top() != "(") {
                    tokens.emplace_back(stack.top());
                    stack.pop();
                }
                stack.pop();
            } else if (s[i] == '+' || s[i] == '-') {
                if ((s[i] == '-' && i == 0&&std::isdigit(s[i+1])) || (s[i] == '-' && s[i - 1] == '('&&std::isdigit(s[i+1]))) {
                    string num;
                    num.push_back('-');
                    int j = i + 1;
                    while (j < s.length() && std::isdigit(s[j])) {
                        num.push_back(s[j]);
                        j++;
                    }
                    tokens.emplace_back(num);
                    i = j - 1;
                    continue;
                }
                if (stack.empty()) {
                    string str(1, s[i]);
                    stack.push(str);
                } else {
                    while (!stack.empty() && stack.top() != "(") {
                        tokens.emplace_back(stack.top());
                        stack.pop();
                    }
                    if (s[i] == '+') {
                        stack.push("+");
                    } else {
                        stack.push("-");
                    }
                }
            } else {
                string num;
                int j = i;
                while (j < s.length() && std::isdigit(s[j])) {
                    num.push_back(s[j]);
                    j++;
                }
                tokens.emplace_back(num);
                i = j - 1;
            }
        }
        while (!stack.empty()) {
            tokens.emplace_back(stack.top());
            stack.pop();
        }
        return evalRPN(tokens);
    }
};

int main() {
    string s("1-(     -2)");
    Solution mysolution;
    std::cout << mysolution.calculate(s);
    return 0;
}
