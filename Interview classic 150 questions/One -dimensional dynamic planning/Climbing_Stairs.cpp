#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n==1)return 1;
        if (n==2)return 2;
        vector<int>dp(n);
        dp[0]=1;
        dp[1]=2;
        for (int i = 2; i < dp.size(); ++i) {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[dp.size()-1];
    }
};