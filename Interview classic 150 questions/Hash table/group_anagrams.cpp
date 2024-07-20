#include <iostream>
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
        int i = 0;
        while (!strs.empty()) {
            result[i].push_back(strs[0]);
            strs.erase(strs.begin());
            int j = 0;
            while (j < strs.size()) {
                if (isAnagram(result[i][0], strs[j])) {
                    result[i].push_back(strs[j]);
                    strs.erase(strs.begin() + j);
                } else {
                    j++;
                }
            }
            i++;
        }
        return result;
    }
};
