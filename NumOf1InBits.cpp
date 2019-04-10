// Problem:
// 输入一个整数，输出该数二进制表示中1的个数。
// 其中负数用补码表示。

/*
 * `n` and `n-1` are the same from high bit position
 * to low, they differs from the last bit of 1 of n,
 * let's name it x. Have a look from x to the lowest 
 * bit position,
 * n:   010101000
 * &         x      <--- position x
 * n-1: 010100111
 * ---------------
 *      010100000   <--- n&(n-1)
 * It erases the last bit of 1 in n!!!
 *
 * This is why the following procedure will work. :)
 */

#include <iostream>

int NumOf1(int n) {
    int cnt = 0;
    while (n) {
        n = n & (n-1);
        ++cnt;
    }
    return cnt;
}

int main() {
    int N = 0;
    std::cin >> N;
    std::cout << NumOf1(N);
    return 0;
}
