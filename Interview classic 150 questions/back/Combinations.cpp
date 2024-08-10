#include <algorithm>
#include <queue>
#include <vector>
#include <bits/streambuf_iterator.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        queue<pair<vector<int>, int> > queue;
        for (int i = 1; i <= n; ++i) {
            queue.push({{i}, 1});
        }
        while (!queue.empty()) {
            vector<int> vect = queue.front().first;
            int step = queue.front().second;
            queue.pop();
            if (step < k) {
                for (int i = vect[vect.size() - 1]+1; i <= n; ++i) {
                    vector<int> temp = vect;
                    temp.push_back(i);
                    queue.push({temp, step + 1});
                }
            } else {
                res.push_back(vect);
            }
        }
        return res;
    }
};
