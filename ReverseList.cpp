// Problem: Reverse a linked list.
// A linked list can be reversed either iteratively
// or recursively.
// Could you implement both?

class ListNode {
public:
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // iterative
    ListNode* reverseList(ListNode* head) {
        // base case
        if (!head || head -> next == nullptr)
            return head;

        auto origin_head = head;
        auto p = head -> next;
        while (p) {
            // a copy for next iteration
            auto newp = p -> next;
            p -> next = head; // relink
            head = p; // update head
            p = newp; // ready for next iteration
        }
        // set origin head -> next point to null
        origin_head -> next = nullptr;
        return head;
    }

    // recursive
    ListNode* ReverseList(ListNode* head) {
        if (!head || head -> next == nullptr)
            return head;
        
        // suppose it can already do the job
        auto p = ReverseList(head -> next);
        auto tmp = p;
        // move tmp until reaching the end
        while (tmp -> next) {
            tmp = tmp -> next;
        }
        tmp -> next = head; // relink
        head -> next = nullptr;
        return p;
    }
};
