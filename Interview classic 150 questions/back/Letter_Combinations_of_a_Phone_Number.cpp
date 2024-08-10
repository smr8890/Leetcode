#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    unordered_map<char, string> map = {
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int n = digits.size();
        if (n == 0)return result;
        queue<pair<string, int> > queue;
        for (auto c: map[digits[0]]) {
            string s;
            s = c;
            queue.push({s, 1});
        }
        while (!queue.empty()) {
            string s = queue.front().first;
            int step = queue.front().second;
            queue.pop();
            if (step < n) {
                for (auto c: map[digits[step]]) {
                    string temp = s;
                    temp.push_back(c);
                    queue.push({temp, step + 1});
                }
            } else {
                result.push_back(s);
            }
        }
        return result;
    }
};
