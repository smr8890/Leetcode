#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) {
            return 1;
        }
        if (n < 0) {
            n = abs(n);
            x = 1 / x;
        }
        double res = 1;
        while (n>0) {
            if (n%2==1) {
                res*=x;
            }
            n/=2;
            x*=x;
        }
        return res;
    }
};
