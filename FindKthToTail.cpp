// Problem: return the kth node to tail for a given 
// linked list

/*
 * 1. Travel all the list, get the list size `n`,
 *    then move `n-k` step
 * 2. Let `p` start from head and move `k` steps,
 *    now let `q` start from head move together with
 *    `p`, then `q` is the kth node as `p` reach the
 *    end of the list
 */

class ListNode {
public:
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(nullptr) { }
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* head, unsigned int k) {
        if (!head) return nullptr;
        auto p = head;
        unsigned int sz = 1;
        // get the list size
        while (p -> next) {
            ++sz;
            p = p -> next;
        }

        if (k == sz) return head;
        else if (k > sz) return nullptr;
        else {
            auto diff = sz - k;
            auto res = head;
            while (diff--) {
                res = res -> next;
            }
            return res;
        }
    }
};
