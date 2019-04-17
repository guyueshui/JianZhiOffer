// Problem:
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法
// （先后次序不同算不同的结果）。

/*
 * This is a typical DP problem. We must derive the
 * recursion relations between the origin problem 
 * and sub-problems.
 *
 * Let's say opt(n) denotes the number of ways the
 * frog can jump to nth floor, then
 * 
 * opt(n) = 1, if n = 1
 *        = 2, if n = 2
 *        = opt(n-1) + opt(n-2), o.w.
 * 
 * The last equation holds or you can condition on
 * the first jump:
 *    1) jump 1 step -> the # of ways jumping to nth
 *       floor is equal to # of ways jumping to (n-1)th
 *       floor
 *    2) jump 2 step -> similarly
 *
 * adding them together gives the total # of ways to
 * jump to nth floor.
 */

#include <iostream>
#include <functional>
using namespace std;

class Solution {
public:
    // top-down fashion, recursive and O(e^n)
    int jumpFloor(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        return jumpFloor(n-1) + jumpFloor(n-2);
    }

    // bottom-up fashion, iterative
    int opt(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        // functional style
        std::function<int(int,int,int)> opt_iter;
        opt_iter = [&opt_iter](int a, int b, int cnt) {
            if (cnt == 0) return b;
            else
                return opt_iter(b, a+b, cnt-1);
        };
        // tail recursive
        return opt_iter(1, 2, n-2);
    }
};

int main() {
    cout << Solution().jumpFloor(10) << '\n'
        << Solution().opt(88) << endl;
    return 0;
}
