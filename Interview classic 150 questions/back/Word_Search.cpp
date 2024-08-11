#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// class Solution {
//     int hash(int i, int j, int m) {
//         return i * m + j;
//     }
//
//     bool dfs(string &target, vector<vector<char> > &board, unordered_set<int> set, int slen, int i, int j) {
//         if (slen == target.size())return true;
//         if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || set.count(hash(i, j, board[0].size())) || board[
//                 i][j] != target[slen])
//             return false;
//         set.insert(hash(i, j, board[0].size()));
//         if (dfs(target, board, set, slen + 1, i + 1, j) ||
//             dfs(target, board, set, slen + 1, i - 1, j) ||
//             dfs(target, board, set, slen + 1, i, j + 1) ||
//             dfs(target, board, set, slen + 1, i, j - 1)) {
//             return true;
//             }
//         set.erase(hash(i, j, board[0].size()));
//         return false;
//     }
//
// public:
//     bool exist(vector<vector<char> > &board, string word) {
//         unordered_set<char>set;
//         for (int i = 0; i < board.size(); ++i) {
//             for (int j = 0; j < board.size(); ++j) {
//                 set.insert(board[i][j]);
//             }
//         }
//         for (auto c: word) {
//             if (!set.count(c))return false;
//         }
//         for (int i = 0; i < board.size(); ++i) {
//             for (int j = 0; j < board[0].size(); ++j) {
//                 unordered_set<int> used;
//                 if ( dfs(word, board, used, 0, i, j)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };


class Solution {
    int hash(int i, int j, int m) {
        return i * m + j;
    }

    bool dfs(string &target, vector<vector<char> > &board, vector<vector<bool> > used, int slen, int i, int j) {
        if (slen == target.size())return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || used[i][j] ||
            board[
                i][j] != target[slen])
            return false;
        used[i][j] = true;
        if (dfs(target, board, used, slen + 1, i + 1, j) ||
            dfs(target, board, used, slen + 1, i - 1, j) ||
            dfs(target, board, used, slen + 1, i, j + 1) ||
            dfs(target, board, used, slen + 1, i, j - 1)) {
            return true;
        }
        used[i][j] = false;
        return false;
    }

public:
    bool exist(vector<vector<char> > &board, string word) {
        unordered_set<char> set;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                set.insert(board[i][j]);
            }
        }
        for (int i = 0; i < word.length(); ++i) {
            if (!set.count(word[i]))return false;
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                vector<vector<bool> > used(board.size(), vector<bool>(board[0].size(), false));
                if (dfs(word, board, used, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // vector<vector<char> > board({
    //     {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'},
    //     {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}
    // });
    // string word("AAAAAAAAAAAAAAB");
    vector<vector<char>>board({{'a','b'}});
    string word("ab");
    Solution my_solution;
    clock_t start, stop;
    start = clock();
    my_solution.exist(board, word);
    stop = clock();
    int duration = (stop - start) / CLOCKS_PER_SEC;
    std::cout << duration;
    return 0;
}
