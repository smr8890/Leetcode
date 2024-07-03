#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
    vector<int> vals;
    unordered_map<int, int> map;

    RandomizedSet() {
    }

    bool insert(int val) {
        if (map.count(val)) {
            return false;
        }
        vals.emplace_back(val);
        map[val] = vals.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!map.count(val)) {
            return false;
        }
        int index = map.at(val);
        if (index == vals.size() - 1) {
            vals.pop_back();
            map.erase(val);
        } else {
            vals[index] = vals[vals.size() - 1];
            vals.pop_back();
            map.erase(val);
            map[vals[index]] = index;
        }
        return true;
    }

    int getRandom() {
        int random = rand() % vals.size();
        return vals[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    return 0;
}
