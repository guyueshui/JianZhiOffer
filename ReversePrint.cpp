// Problem: print from the end to begining of
// a given linked list.

/*
 * 1. use stack
 * 2. use recursion
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        // boundary case
        if (head == nullptr) return ret;

        stack<int> s;
        for (auto p = head; p != nullptr; p = p -> next) {
            s.push(p -> val);
        }

        while (!s.empty()) {
            ret.push_back(s.top());
            s.pop();
        }
        return ret;
    }

    // recursive needs a member variable
    // use recursion stack, tricky
    vector<int> arr;
    vector<int> reversePrint(ListNode* head) {
        if (head) {
            reversePrint(head -> next);
            arr.push_back(head -> val);
        }
        return arr;
    }
    /*
     * Consider the closure, at one recursive step,
     * what I should do? Let's drop all the details,
     * just look one recursive step.
     * What had I done?
     *     Oh gee, I see if the head is not null,
     *     I must push the value to the vector,
     *     but before this, I should take a look at
     *     `head -> next`, since I have to push
     *     the tail first. So which one can help me
     *     do this? Yes, the function itself! Then
     *     after I have addressed the tail, now I'm
     *     going to push current value to the vector.
     *     That's all I need!
     * The key is you work in one recursive step, and
     * form a closure for the next, and do not forget
     * the base case (stopping rules). That how
     * recursion runs! And you are free of those
     * confusing details.
     */
};
