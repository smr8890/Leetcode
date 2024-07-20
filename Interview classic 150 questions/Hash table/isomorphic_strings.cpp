#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        unordered_map<char, char> map;
        unordered_set<char> set;
        for (int i = 0; i < len; ++i) {
            if (map.count(s[i])) {
                if (map[s[i]] != t[i]) {
                    return false;
                }
            } else {
                if (set.count(t[i])) {
                    return false;
                }
                map.insert({s[i], t[i]});
                set.insert(t[i]);
            }
        }
        return true;
    }
};
