#include <vector>
using namespace std;

class Solution {
    void dfs(int target, vector<int> &candidates, vector<int> &temp, vector<vector<int> > &res, int index) {
        if (index == candidates.size())return;
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        dfs(target, candidates, temp, res, index + 1);
        if (target - candidates[index] >= 0) {
            temp.push_back(candidates[index]);
            dfs(target - candidates[index], candidates, temp, res, index);
            temp.pop_back();
        }
    }

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        vector<int> temp;
        dfs(target, candidates, temp, res, 0);
        return res;
    }
};
