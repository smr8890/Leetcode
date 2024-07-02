#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        int max_profit = 0, min_prices = prices[0];
        for (int i = 1; i < len; ++i) {
            int profit = prices[i] - min_prices;
            if (profit > max_profit) {
                max_profit = profit;
            }
            if (prices[i] < min_prices) {
                min_prices = prices[i];
            }
        }
        return max_profit;
    }
};
