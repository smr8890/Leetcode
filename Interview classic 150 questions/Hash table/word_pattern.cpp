#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    void Stringsplit(string str, const char split, vector<string> &strs) {
        istringstream iss(str); // 输入流
        string token; // 接收缓冲区
        while (getline(iss, token, split)) {
            strs.push_back(token);
        }
    }

    bool wordPattern(string pattern, string s) {
        int plen = pattern.length();
        unordered_map<char, string> map;
        unordered_set<string> set;
        vector<string> strs;
        Stringsplit(s, ' ', strs);
        int slen = strs.size();
        if (plen != slen)
            return false;
        for (int i = 0; i < plen; ++i) {
            if (map.count(pattern[i])) {
                if (map[pattern[i]] != strs[i]) {
                    return false;
                }
            } else {
                if (set.count(strs[i]))
                    return false;
                map.insert({pattern[i], strs[i]});
                set.insert(strs[i]);
            }
        }
        return true;
    }
};
