#include <vector>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
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
};
