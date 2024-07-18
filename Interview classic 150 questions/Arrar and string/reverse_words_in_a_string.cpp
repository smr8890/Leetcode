#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void Stringsplit(string str, const char split, vector<string> &strs) {
        istringstream iss(str); // 输入流
        string token; // 接收缓冲区
        while (getline(iss, token, split)) // 以split为分隔符
        {
            strs.push_back(token);
        }
    }

    string reverseWords(string s) {
        while (s[0] == ' ') {
            s.erase(s.begin());
        }
        while (s[s.length() - 1] == ' ') {
            s.erase(s.end() - 1);
        }

        int i = 0;
        while (i < s.length() - 1) {
            if (s[i] == ' ') {
                int j = i + 1;
                while (s[j] == ' ') {
                    s.erase(s.begin() + j);
                }
            }
            i++;
        }


        vector<string> strs;
        Stringsplit(s, ' ', strs);
        string result;
        for (int i = strs.size() - 1; i >= 0; --i) {
            result.append(strs[i] + ' ');
        }
        result.erase(result.end() - 1);
        return result;
    }
};
