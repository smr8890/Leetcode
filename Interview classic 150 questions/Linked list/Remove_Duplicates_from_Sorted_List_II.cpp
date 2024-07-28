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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *node = new ListNode(0, head);
        ListNode *pre = head, *p = pre->next, *p0 = node;
        while (p != nullptr) {
            if (p->val == pre->val) {
                while (p != nullptr && p->val == pre->val) {
                    pre->next = p->next;
                    delete p;
                    p = pre->next;
                }
                p0->next = p;
                delete pre;
                if (p != nullptr) {
                    pre = p;
                    p = p->next;
                }
            } else {
                p0 = pre;
                pre = p;
                p = p->next;
            }
        }
        head = node->next;
        delete node;
        return head;
    }
};
