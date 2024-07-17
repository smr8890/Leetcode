#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int len = ratings.size();
        vector<int> candy(len);

        candy[0] = 1;
        for (int i = 1; i < len; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            } else {
                candy[i] = 1;
            }
        }
        for (int i = len - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += candy[i];
        }

        return sum;
    }
};
