// Problem:
// 一只青蛙一次
// 可以跳上1级台阶，
// 也可以跳上2级……
// 它也可以跳上n级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法。

/*
 * First case analysis:
 *    Condition on the first step, if we know:
 *    the first step i jump x stairs, let f(n)
 *    denotes the # of ways jumping to nth floor
 *    1) x=1, there are f(n-1)
 *    2) x=2, f(n-2)
 *    ...
 *    n) x=n, f(n-n)
 *    --> f(n) = f(0) + f(1) + ... + f(n-1)
 *    
 * adding them all together gives the answer.
 *
 * f(1) = 1
 * f(2) = f(1) + f(0) = 1 + 1 = 2
 * f(3) = f(2) + f(1) + f(0) = 2 * f(2)
 * f(4) = f(3) + f(2) + f(1) + f(0) = 2 * f(3)
 * ...
 */

#include <iostream>

class Solution {
public:
    int jumpFloorII(int n) {
        if (n == 1) return 1;
        else
            return 1 << (n-1);
    }
};

int main() {
    std::cout << Solution().jumpFloorII(10);
    return 0;
}
