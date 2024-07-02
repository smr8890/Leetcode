#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int max_profit=0;
        for (int i = 1; i < len; ++i) {
            if (prices[i]>prices[i-1]) {
                max_profit+=prices[i]-prices[i-1];
            }
        }
        return max_profit;
    }
};