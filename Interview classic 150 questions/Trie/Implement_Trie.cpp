#include <iostream>
#include <vector>
using namespace std;

class Trie {
    bool isEnd;
    vector<Trie *> next;

public:
    Trie() : isEnd(false), next(26, nullptr) {
    }

    void insert(string word) {
        Trie *node = this;
        for (auto ch: word) {
            if (node->next[ch - 'a'] == nullptr) {
                node->next[ch - 'a'] = new Trie();
            }
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie *node = this;
        for (auto ch: word) {
            node = node->next[ch - 'a'];
            if (node == nullptr)return false;
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie *node = this;
        for (auto ch: prefix) {
            node = node->next[ch - 'a'];
            if (node == nullptr)return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
