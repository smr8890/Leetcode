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
    ListNode *partition(ListNode *head, int x) {
        ListNode *node = new ListNode(0, head);
        ListNode *left = node, *right = node;
        ListNode *nextl, *nextr;
        int flag = 1;
        while (right->next != nullptr) {
            if (right->next->val >= x) {
                right = right->next;
                flag = 0;
            } else if (flag) {
                left = left->next;
                right = right->next;
            } else {
                nextl = left->next;
                nextr = right->next->next;
                left->next = right->next;
                left->next->next = nextl;
                right->next = nextr;
                left = left->next;
            }
        }
        head = node->next;
        delete node;
        return head;
    }
};
