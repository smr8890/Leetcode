#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string> &bank) {
        unordered_set<string> _bank;
        unordered_set<string> visited;
        queue<pair<string, int> > queue;
        vector<char> gene({'A', 'C', 'G', 'T'});
        for (int i = 0; i < bank.size(); ++i) {
            _bank.insert(bank[i]);
        }
        if (!_bank.count(endGene))return -1;

        queue.push({startGene, 0});
        visited.insert(startGene);
        while (!queue.empty()) {
            string cur = queue.front().first;
            int step = queue.front().second + 1;
            queue.pop();
            for (int i = 0; i < 8; ++i) {
                for (auto gene1: gene) {
                    string next = cur;
                    next[i] = gene1;
                    if (!_bank.count(next)) {
                        continue;
                    }
                    if (visited.count(next)) {
                        continue;
                    } else {
                        if (next == endGene)return step;
                        visited.insert(next);
                        queue.push({next, step});
                    }
                }
            }
        }
        return -1;
    }
};
