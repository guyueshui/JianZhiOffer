// Problem: use two queues to form a stack

/*
 * 1. queue2 as a auxiliary storage
 * 2. push: push to the rear of queue1
 * 3. pop: 
 *    3.1. quque1 has only one element, pop it
 *    3.2. pop the elements of queue1, push them to queue2
 *         till queue1 has exactly one left, pop it
 *    then pop elems of queue2 push to queue1
 */

#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int _node) {
        q1.push(_node);
    }

    int pop() {
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }
};
