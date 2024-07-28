#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> map;
        Node *copy = new Node(-1);
        Node *p = copy, *q = head;
        while (q != NULL) {
            p->next = new Node(q->val);
            p = p->next;
            map.insert({q, p});
            q = q->next;
        }
        p = copy->next, q = head;
        while (q != NULL) {
            if (q->random != NULL) {
                p->random = map[q->random];
            }
            p = p->next;
            q = q->next;
        }
        return copy->next;
    }
};
