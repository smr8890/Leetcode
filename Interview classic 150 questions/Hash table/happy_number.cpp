#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        set.insert(n);
        while (n != 1) {
            int sum = 0;
            while (n > 0) {
                int t = n % 10;
                n /= 10;
                sum += t * t;
            }
            if (set.count(sum)) {
                return false;
            }
            set.insert(sum);
            n = sum;
        }
        return true;
    }
};
