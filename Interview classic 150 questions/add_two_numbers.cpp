#include<iostream>
/**
* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l3 = nullptr, *next = nullptr;
        int carry = 0, sum=0;
        while (l1 || l2) {
            if (l1 && l2) {
                sum = l1->val + l2->val + carry;
                carry = 0;
                l1 = l1->next;
                l2 = l2->next;
                if (sum >= 10) {
                    sum -= 10;
                    carry++;
                }
            } else if (l1) {
                sum = l1->val + carry;
                carry = 0;
                l1 = l1->next;
                if (sum >= 10) {
                    sum -= 10;
                    carry++;
                }
            } else if (l2){
                sum = l2->val + carry;
                carry = 0;
                l2 = l2->next;
                if (sum >= 10) {
                    sum -= 10;
                    carry++;
                }
            }
            if (!l3) {
                l3=new ListNode(sum);
                next=l3;
            } else {
                next->next=new ListNode(sum);
                next=next->next;
            }
        }
        if (carry) {
            next->next=new ListNode(carry);
        }
        return l3;
    }
};
