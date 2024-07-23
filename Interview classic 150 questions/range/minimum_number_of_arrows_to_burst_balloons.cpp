#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int> > &points) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int arrows = 0;
        int left = 0;
        int len = points.size();
        while (left < len) {
            arrows++;
            int right = left + 1;
            while (right < len && points[right][0] <= points[left][1]) {
                right++;
            }
            left = right;
        }
        return arrows;
    }
};
