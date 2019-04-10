// Problem: 
// 定义栈的数据结构，
// 请在该类型中实现一个能够得到栈中所含最小元素的min函数
// （时间复杂度应为O（1））。

/*
 * Use a auxiliary stack for help, whose top elem is
 * always the min value of the origin stack.
 *
 * Credits: nowcoder.com
 */

#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> aux;

public:
    void push(int val) {
        s.push(val);
        if (aux.empty())
            aux.push(val);
        else if (val <= aux.top())
            aux.push(val);
    }

    void pop() {
        if (s.empty()) return;

        if (s.top() == aux.top())
            aux.pop();
        s.pop();
    }

    int top() { return s.top(); }
    int min() { return aux.top(); }
};
