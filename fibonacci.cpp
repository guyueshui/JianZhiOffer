// Problem: 
// fibonacci numbers: 0,1,1,2,3,5,8...
// find fib(n)

/*
 * this requires a iterative fibonacci, otherwise
 * it will run out of the time limit
 */

// iterative fibonacci
class Solution {
public:
    int fib(int n) {
        return fib_iter(1, 0, n);
    }

    // tail recursion <=> iteration
    // please refer to SICP Ch. 1.2.2
    int fib_iter(int a, int b, int cnt) {
        if (cnt == 0) return b;
        else
            return fib_iter(a+b, a, cnt-1);
    }
};
