#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        digits[digits.size() - 1]++;
        int flag = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += flag;
            flag = digits[i] / 10;
            digits[i] %= 10;
        }
        if (flag) {
            digits.insert(digits.begin(), flag);
        }
        return digits;
    }
};

int main() {
    Solution my_solution;
    vector<int> test({9, 9, 9, 9, 9});
    my_solution.plusOne(test);
    return 0;
}
