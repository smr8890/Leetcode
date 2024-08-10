#include <vector>
#include <string>
using namespace std;

class WordDictionary {
    bool isEnd;
    vector<WordDictionary *> next;

    bool search(string word, int index) {
        WordDictionary *node = this;
        for (int i = index; i < word.size(); ++i) {
            if (word[i] == '.') {
                bool flag = false;
                for (int j = 0; j < 26; ++j) {
                    if (node->next[j] != nullptr) {
                        flag = flag | node->next[j]->search(word,i+1);
                    }
                }
                return flag;
            } else {
                if (node->next[word[i] - 'a'] == nullptr)return false;
                node = node->next[word[i] - 'a'];
            }
        }
        return node->isEnd;
    }

public:
    WordDictionary() : isEnd(false), next(26, nullptr) {
    }

    void addWord(string word) {
        WordDictionary *node = this;
        for (auto c: word) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new WordDictionary();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return search(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
