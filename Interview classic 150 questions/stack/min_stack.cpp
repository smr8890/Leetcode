#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class MinStack {
public:
    vector<int> stack;
    int minIndex;
    int len;

    MinStack() {
        minIndex = -1;
        len = 0;
    }

    void push(int val) {
        stack.push_back(val);
        len++;
        if (minIndex != -1) {
            if (val < stack[minIndex]) {
                minIndex = len - 1;
            }
        } else {
            minIndex = len - 1;
        }
    }

    void pop() {
        if (stack.empty())
            return;
        stack.erase(stack.end() - 1);
        len--;
        minIndex = -1;
        int min = INT_MAX;
        for (int i = 0; i < len; ++i) {
            if (stack[i] <= min) {
                min = stack[i];
                minIndex = i;
            }
        }
    }

    int top() {
        return stack[len - 1];
    }

    int getMin() {
        return stack[minIndex];
    }
};

int main() {
    MinStack min_stack;
    min_stack.push(-2);
    min_stack.push(0);
    min_stack.push(-1);
    cout << min_stack.getMin() << endl;
    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
