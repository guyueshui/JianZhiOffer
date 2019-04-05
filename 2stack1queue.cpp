// Problem: use two stacks to form a queue

/*
 * Basic idea:
 *     1. the top of stack1 as queue rear
 *     2. the top of stack2 as queue front
 */

#include <stack>
#include <iostream>

using namespace std;

class Queue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int _node) {
        s1.push(_node);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
};
