#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        vector<vector<int> > res;
        queue<pair<vector<int>, int> > queue;
        for (int &num: nums) {
            queue.push({{num}, 1});
        }
        while (!queue.empty()) {
            vector<int> vect = queue.front().first;
            int step = queue.front().second;
            queue.pop();
            if (step < nums.size()) {
                for (auto num: nums) {
                    vector<int> temp = vect;
                    if (find(temp.begin(), temp.end(), num) == temp.end()) {
                        temp.push_back(num);
                        queue.push({temp, step + 1});
                    }
                }
            } else {
                res.push_back(vect);
            }
        }
        return res;
    }
};
