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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL)
            return head;
        ListNode *node = new ListNode(0, head);
        int len = 0;
        ListNode *p = head, *pre_p = node;
        while (p != nullptr) {
            len++;
            p = p->next;
        }
        k = k % len;
        if (k == 0) {
            delete node;
            return head;
        }
        p = head;
        while (k--) {
            p = p->next;
            pre_p = pre_p->next;
        }
        ListNode *left = node;
        while (p != nullptr) {
            p = p->next;
            pre_p = pre_p->next;
            left = left->next;
        }
        pre_p->next = head;
        head = left->next;
        left->next = nullptr;
        delete node;
        return head;
    }
};
