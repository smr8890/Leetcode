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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *node = new ListNode(); //哨兵节点
        node->next = head;
        int count = 0;
        ListNode *cur = node, *pre = nullptr;
        for (; count < left; count++) {
            pre = cur;
            cur = cur->next;
        }
        ListNode *p0 = pre;
        for (; count <= right; count++) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        p0->next->next = cur;
        p0->next = pre;
        return node->next;
    }
};
