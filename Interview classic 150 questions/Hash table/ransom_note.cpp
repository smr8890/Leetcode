#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rlen = ransomNote.length(), mlen = magazine.length();
        vector<int> set(26, 0);
        for (int i = 0; i < mlen; ++i) {
            set[magazine[i] - 'a']++;
        }
        for (int i = 0; i < rlen; ++i) {
            if (set[ransomNote[i] - 'a']) {
                set[ransomNote[i] - 'a']--;
            } else {
                return false;
            }
        }
        return true;
    }
};
