#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size();
        for (int i = 0; i < len; ++i) {
            int current_gas = 0, current_cost = 0;
            int j;
            for (j = 0; j < len; ++j) {
                int index = (i + j) % len;
                current_gas += gas[index];
                current_cost += cost[index];
                if (current_gas < current_cost) {
                    break;
                }
            }
            if (j == len) {
                return i;
            } else {
                i = i + j;
            }
        }
        return -1;
    }
};
