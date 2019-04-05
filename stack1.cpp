// Problem: 输入两个整数序列，第一个序列表示栈的压入顺序，
// 请判断第二个序列是否可能为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的
// 压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
// 但4,3,5,1,2就不可能是该压栈序列的弹出序列。
// （注意：这两个序列的长度是相等的）

/*
 * The idea is I push all elems of `pushV` into 
 * a stack `s`, simultaneously, I track if the elems 
 * of `popV` equal to the `s.top()`. If it is, I will
 * pop a elem from the stack and track the next elem
 * of `popV` till a mismatch. Then I'll continue to push
 * elems into the stack.
 *
 * When I run out all elems of `pushV`, I check if the
 * stack is empty, if it is, then the `popV` should be
 * a possible pop sequence or vice versa.
 *
 * Credit: https://www.nowcoder.com/profile/248554
 */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        // border case
        if (pushV.size() == 0) return false;
        
        stack<int> s;
        auto i = 0, j = 0;
        while (i != pushV.size()) {
            s.push(pushV[i++]);
            // KEY POINT here
            while (!s.empty()
                    && s.top() == popV[j]
                    && j != popV.size()) {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};

// test
int main() {
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {4,5,3,2,1};
    cout << Solution().IsPopOrder(pushV, popV);
    return 0;
}
