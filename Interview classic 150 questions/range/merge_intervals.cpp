#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals) {
        vector<vector<int> > result;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while (i < intervals.size()) {
            vector<int> temp(intervals[i]);
            i++;
            while (i < intervals.size()) {
                if (intervals[i][0] <= temp[1]) {
                    if (intervals[i][1] > temp[1]) {
                        temp[1] = intervals[i][1];
                    }
                    i++;
                } else {
                    break;
                }
            }
            result.emplace_back(temp);
        }
        return result;
    }
};

int main() {
    vector<vector<int> > test({{1, 3}, {1, 62}, {15, 18}, {8, 10}});
    Solution mysolution;
    mysolution.merge(test);
}
