#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        unordered_set<string> set;
        queue<pair<string, pair<int, int> > > queue;
        queue.push({"(", {1, 0}});
        while (!queue.empty()) {
            string cur = queue.front().first;
            int left = queue.front().second.first, right = queue.front().second.second;
            queue.pop();

            if (left == n && right == n) {
                res.push_back(cur);
            }
            if (left < n) {
                queue.push({cur + "(", {left + 1, right}});
            }
            if (right < left) {
                queue.push({cur + ")", {left, right + 1}});
            }
        }
        return res;
    }
};
