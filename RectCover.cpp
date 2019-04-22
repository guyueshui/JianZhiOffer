// Problem:
// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
// 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，
// 总共有多少种方法？

/*
 * Again a typical DP problem. Let opt(n) denotes
 * the # of ways that give small (2x1) rectangle 
 * covers a big (2 x n) rect. How can we write the
 * recursive relation? Again consider the first
 * step, which is so-called first-step analysis,
 * learned from Probability. The first step is the
 * crux. If we know the first step exactly, we can
 * go on the next step, which is a sub-problem
 * having the same structure as the origin.
 *
 * Now let's see.
 *
 * If the first step
 *     1) a vertical-fill, then I have opt(n-1)
 *     2) a horizontal-fill, then I have opt(n-2)
 * What about base cases?
 *     1) opt(1) = 1
 *     2) opt(2) = 2
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // recursive, O(2^n)
    int rectCover(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        // else
        return rectCover(n-1) + rectCover(n-2);
    }

    // iterative O(n)
    int opt(int n) {
        if (n <= 2) return n;

        // else
        int a = 1, b = 2;
        /* apply the transform n-2 times
         * then `b` is fib(n)
         *    a = b
         *    b = a + b
         */
        for (; n > 2; --n) {
            b = a + b;
            a = b - a; // `a` is the previous `b`
        }
        return b;
    }
};
