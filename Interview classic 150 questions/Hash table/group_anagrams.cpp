#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i] < 0)
                return false;
        }
        return true;
    }

    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        vector<vector<string> > result;
        // int i = 0;
        // while (!strs.empty()) {
        //     result.resize(i+1);
        //     result[i].push_back(strs[0]);
        //     strs.erase(strs.begin());
        //     int j = 0;
        //     while (j < strs.size()) {
        //         if (isAnagram(result[i][0], strs[j])) {
        //             result[i].push_back(strs[j]);
        //             strs.erase(strs.begin() + j);
        //         } else {
        //             j++;
        //         }
        //     }
        //     i++;
        // }
        unordered_map<string, vector<string> > map;
        for (auto &str: strs) {
            string value = str;
            sort(str.begin(), str.end());
            map[str].emplace_back(value);
        }
        for (auto &it: map) {
            result.emplace_back(it.second);
        }
        return result;
    }
};

int main() {
    vector<string> strs({"eat", "tea", "tan", "ate", "nat", "bat"});
    Solution mysolution;
    vector<vector<string> > result = mysolution.groupAnagrams(strs);
    return 0;
}
