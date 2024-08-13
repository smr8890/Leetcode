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
    ListNode *sort(ListNode *head, ListNode *tail) {
        if (head == nullptr)return nullptr;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }

        ListNode *fast = head, *slow = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }
        return merge(sort(head, slow), sort(slow, tail));
    }

    ListNode *merge(ListNode *list1, ListNode *list2) {
        ListNode *merged = new ListNode(-1);
        ListNode *p = merged;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        if (list1 == nullptr) {
            p->next = list2;
        } else {
            p->next = list1;
        }
        return merged->next;
    }

public:
    ListNode *sortList(ListNode *head) {
        return sort(head, nullptr);
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
