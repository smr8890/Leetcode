#include <iostream>
#include <unordered_map>
using namespace std;

struct DLinkedList {
    int key, val;
    DLinkedList *pre;
    DLinkedList *next;

    DLinkedList(): key(0), val(0), pre(nullptr), next(nullptr) {
    }

    DLinkedList(int _key, int _val): key(_key), val(_val), pre(nullptr), next(nullptr) {
    }
};

class LRUCache {
private:
    DLinkedList *dummy;
    unordered_map<int, DLinkedList *> map;
    int capacity;

    void deleteNode(DLinkedList *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void moveToHead(DLinkedList *node) {
        deleteNode(node);
        node->pre = dummy;
        node->next = dummy->next;
        dummy->next = node;
        node->next->pre = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        dummy = new DLinkedList();
        dummy->pre = dummy;
        dummy->next = dummy;
    }

    int get(int key) {
        if (map.count(key)) {
            moveToHead(map[key]);
            return map[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            map[key]->val = value;
            moveToHead(map[key]);
        } else {
            auto *p = new DLinkedList(key, value);
            p->pre = dummy;
            p->next = dummy->next;
            dummy->next = p;
            p->next->pre = p;
            map.insert({key, p});
            if (map.size() > capacity) {
                p = dummy->pre;
                deleteNode(p);
                map.erase(p->key);
                delete p;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
