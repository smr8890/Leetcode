#include <algorithm>
#include<vector>
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

    vector<vector<int> > insert(vector<vector<int> > &intervals, vector<int> &newInterval) {
        intervals.emplace_back(newInterval);
        vector<vector<int> > result = merge(intervals);
        return result;
    }
};
