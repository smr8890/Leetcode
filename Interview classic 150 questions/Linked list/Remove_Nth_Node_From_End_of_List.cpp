#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *node = new ListNode();
        node->next = head;
        int len = 0;
        ListNode *p = head;
        while (p != nullptr) {
            p = p->next;
            len++;
        }
        ListNode *pre = node;
        p = node;
        for (int i = 0; i < len - n + 1; ++i) {
            pre = p;
            p = p->next;
        }
        pre->next = p->next;
        delete p;
        return node->next;
    }
};
