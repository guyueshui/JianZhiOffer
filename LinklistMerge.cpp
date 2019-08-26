// Problem: merget two sorted linked list.

/*
 * Use recursion. 
 */

#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* Merge(ListNode* head1, ListNode* head2) {
        if (!head1) return head2;
        if (!head2) return head1;

        // else head1 and head2 are both valid
        ListNode* mergedHead = new ListNode(-1);
        auto p = mergedHead;
        while (head1 && head2) {
            if (head1 -> val <= head2 -> val) {
                p -> next = head1;
                p = p -> next;
                head1 = head1 -> next;
            } else {
                p -> next = head2;
                p = p -> next;
                head2 = head2 -> next;
            }
        }
        // tail processing
        if (head2 == nullptr) {
            p -> next = head1;
        } else {// head1 == nullptr
            p -> next = head2;
        }
        return mergedHead -> next;
    }

    // recursive solution
    ListNode* rMerge(ListNode* h1, ListNode* h2) {
        if (!h1) return h2;
        if (!h2) return h1;
        // else h1 and h2 must be both valid
        ListNode *p = nullptr;
        if (h1 -> val <= h2 -> val) {
            p = h1;
            p -> next = rMerge(h1 -> next, h2);
        } else {
            p = h2;
            p -> next = rMerge(h1, h2 -> next);
        }
        return p;
    }
};

// a printer for easy vision
void printer(ListNode* head) {
    if (head == nullptr) return;
    cout << head -> val << ' ';
    printer(head -> next);
}

int main() {
    // build two linked list
    ListNode* head1 = new ListNode(1);
    ListNode* head2 = new ListNode(2);
    auto p = head1,
         q = head2;
    for (int n = 2; n <= 3; ++n) {
        p -> next = new ListNode(2 * n - 1);
        q -> next = new ListNode(2 * n);
        p = p -> next;
        q = q -> next;
    }
    // buid done
    printer(head1);
    printer(head2);
    auto ret = Solution().rMerge(head1, head2);
    cout << "now print ret: \n";
    printer(ret);
    delete p;
    delete q;
    return 0;
}
