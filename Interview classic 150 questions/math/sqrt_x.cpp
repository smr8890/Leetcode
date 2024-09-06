#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left <= right) {
            int mid = (left + right) / 2;
            double tmp=mid*mid;
            if (tmp< x) {
                left = mid + 1;
            } else if (tmp > x) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};
