#include <algorithm>
#include <vector>
#include <wchar.h>
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
    bool cmp_(ListNode *a, ListNode *b) {
        if (a->val < b->val) {
            return true;
        }
        return false;
    }

    ListNode *sortList(ListNode *head) {
        ListNode *dummy = new ListNode(0, head);
        // ListNode *cur1 = head, *pre1 = dummy;
        // while (cur1 != nullptr) {
        //     if (cur1->next != nullptr && cur1->val > cur1->next->val) {
        //         ListNode *cur2 = cur1, *pre2 = pre1;
        //         while (cur2->next != nullptr) {
        //             if (cur2->val > cur2->next->val) {
        //                 pre2->next = cur2->next;
        //                 cur2->next = cur2->next->next;
        //                 pre2->next->next = cur2;
        //                 pre2 = pre2->next;
        //             } else {
        //                 break;
        //             }
        //         }
        //         cur1 = pre1->next;
        //     } else {
        //         pre1 = cur1;
        //         cur1 = cur1->next;
        //     }
        // }
        vector<ListNode *> tmp;
        while (head != nullptr) {
            tmp.push_back(head);
            head = head->next;
        }
        sort(tmp.begin(), tmp.end(),cmp_);
        for (int i = 0; i < tmp.size() - 1; ++i) {
            tmp[i]->next = tmp[i + 1];
        }
        tmp[tmp.size() - 1]->next = nullptr;
        delete dummy;
        return tmp[0];
    }
};

int main() {
    ListNode *head = new ListNode();
    vector<int> a({-1, 5, 3, 4, 0});
    ListNode *p = head;
    for (auto num: a) {
        p->next = new ListNode(num);
        p = p->next;
    }
    Solution my_solution;
    my_solution.sortList(head->next);
    return 0;
}
